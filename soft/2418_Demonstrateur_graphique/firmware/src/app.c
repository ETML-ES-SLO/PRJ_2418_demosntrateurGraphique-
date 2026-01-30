/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "Mc32gestSpiFT800.h"
#include "Mc32Delays.h"
#include "xc.h"
#include <stdint.h>
#include <string.h>
#include "sys/kmem.h"
#include "driver/usart/drv_usart_static.h"
#include "GesPec12.h"

#define NUM_LEDS        12
#define WS2812_BITS     (NUM_LEDS * 24)
#define PWM_HIGH        65             // 65% duty (bit '1')
#define PWM_LOW         35             // 35% duty (bit '0')

uint16_t ws2812_pwm_data[WS2812_BITS ]; // +50 zéros pour reset (>50 µs)
rgb_t leds[NUM_LEDS]; // Tableau global contenant les couleurs de chaque LED
LedMode_t currentMode;

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************

// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
 */

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
 */

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
 */


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize(void) {
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;


    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks(void) {
    //    static bool affich = true;
    char tableauUART[3];
    static uint8_t indexTrameUSART = 0;
    int i;
    static int pos = 0;
    static uint8_t hue_offset = 0;
    /* Check the application's current state. */
    switch (appData.state) {
            /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
            DRV_TMR0_Start();
            DRV_USART0_Initialize();
            DRV_SPI0_Initialize();
            DRV_OC0_Start();
            InitFT800();
            init_dma();
            //Appel de la fonction d'initialisation du PEC12
            Pec12Init();
            Led_OEOff();
            wr8(REG_VOL_SOUND, 0);
            wr8(REG_VOL_PB, 0);
            Audio_SHDNOn();
            for (i = 0; i < NUM_LEDS; i++) {
                leds[i] = (rgb_t){0, 0, 0}; // Éteint toutes les LEDs
            }
            if (appInitialized) {
                APP_UpdateState(APP_STATE_SERVICE_TASKS);
            }

            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            //            if(!DRV_USART0_ReceiverBufferIsEmpty()){
            //                LedEtatToggle();
            //            }
//                                    tableauUART[0] = 'I';
//                                    tableauUART[1] = 'D';
//                                    tableauUART[2] = rd8(REG_ID);
//                                    // Envoyer le tableau via UART
//                                    for (indexTrameUSART = 0; indexTrameUSART < 3; indexTrameUSART++) {
//                                        if (!DRV_USART0_TransmitBufferIsFull()) {
//                                            DRV_USART0_WriteByte((int8_t) tableauUART[indexTrameUSART]);
//                                        }
//                                    }
            // Appel de la fonction lisant les actions sur le bouton PEC12
            ScanPec12(Pec12_AStateGet(), Pec12_BStateGet(), Pec12_PBStateGet());

            // Gestion des rotations du PEC12
            if ((Pec12IsPlus())&& (currentMode != MODE_DOT)) {
                currentMode = currentMode + 1; // Incrémente le mode si rotation vers la droite
            } else if ((Pec12IsMinus())&& (currentMode != MODE_DOT)) {
                currentMode = currentMode - 1; // Décrémente le mode si rotation vers la gauche
            }

            // Gestion des effets selon currentMode
            switch (currentMode) {

                case MODE_RAINBOW:
                    for (i = 0; i < NUM_LEDS; i++) {
                        uint8_t hue = (hue_offset + i * 20) % 256; // Teinte variant progressivement selon la LED
                        rgb_t color = hsv_to_rgb(hue, 255, 30); // Conversion HSV?RGB avec saturation max et faible luminosité
                        leds[i] = color; // Affecte la couleur à la LED i
                    }
                    ws2812_update(leds); // Met à jour la bande LED
                    hue_offset++; // Fait défiler les couleurs pour l?animation
                    delay_msCt(3); // Pause pour ralentir l?effet
                    break;

                case MODE_STATIC_COLOR_PINK:
                {
                    rgb_t color = {20, 0, 10}; // Définition d'une couleur rose/rouge
                    for (i = 0; i < NUM_LEDS; i++) {
                        leds[i] = color; // Applique la même couleur à chaque LED
                    }
                    ws2812_update(leds); // Met à jour les LEDs
                    break;
                }

                case MODE_STATIC_COLOR_ORANGE:
                {
                    rgb_t color = {20, 10, 0}; // Couleur orange
                    for (i = 0; i < NUM_LEDS; i++) {
                        leds[i] = color; // Applique cette couleur à toutes les LEDs
                    }
                    ws2812_update(leds); // Envoie les données à la bande LED
                    break;
                }
                case MODE_DOT:
                    if (Pec12IsOK()) {
                        currentMode = MODE_RAINBOW;
                    }
                    if (Pec12IsMinus()) {
                        pos = (pos + 1) % NUM_LEDS; // Avance d?un pas (boucle si fin de bande atteinte)
                        for (i = 0; i < NUM_LEDS; i++) {
                            leds[i] = (rgb_t){0, 0, 0}; // Éteint toutes les LEDs
                        }
                        leds[pos % NUM_LEDS] = (rgb_t){50, 0, 0}; // Allume la LED actuelle en rouge
                        ws2812_update(leds); // Envoie les couleurs à la bande
                    }

                    if (Pec12IsPlus()) {
                        pos = (pos - 1 + NUM_LEDS) % NUM_LEDS; // Recule d?un pas avec gestion du débordement
                        for (i = 0; i < NUM_LEDS; i++) {
                            leds[i] = (rgb_t){0, 0, 0}; // Éteint toutes les LEDs
                        }
                        leds[pos % NUM_LEDS] = (rgb_t){0, 10, 0}; // Allume la LED actuelle en rouge
                        ws2812_update(leds); // Envoie les couleurs à la bande
                    }

                    break;
                default:
                    break;
            }

            // Réinitialise les états du PEC12 pour ne pas répéter l'action
            Pec12ClearMinus(); // Efface le flag de rotation négative
            Pec12ClearPlus(); // Efface le flag de rotation positive
            Pec12ClearOK(); // Efface le flag de clic si utilisé

            //            wr8(REG_VOL_SOUND, 0x01);
            //            //            wr16(REG_SOUND,  (0x6C<< 8) | 0x41);
            //            wr16(REG_SOUND, 0x12);
            //            wr8(REG_PLAY, 1);
            //            rd8(REG_PLAY);
            //            LedFSM_Update();

            LedEtatToggle(); // toggle LED

            //rd8(REG_CHIPFT); //Lire code indentification FT si 0x12 -> FT812 Attention peut être overwrite 

            //                        cmd(CMD_LOGO);
            //                        cmd_exec();
            //            while (rd16(REG_CMD_WRITE) != 0) {
            //            }
            //            cmd_wait();

            //            HostCommand(ACTIVE);

            //                        if (affich) {
            //            
            //                            rd8(REG_ID);
            //                                            cmd_dlstart(); // Démarre une nouvelle display lis
            //            
            //                            wr32(RAM_DL + 0, CLEAR_COLOR_RGB(0, 0, 255)); // Couleur bleu
            //                            wr32(RAM_DL + 4, CLEAR(1, 0, 0)); // Clear color, stencil, tag buffers
            //                            //                wr32(RAM_DL + 4, BEGIN(BITMAPS)); // start drawing bitmaps
            //                            //                wr32(RAM_DL + 8, VERTEX2II(220, 110, 31, 0x54)); // ASCII T in font 31
            //                            //                wr32(RAM_DL + 12, END());
            //                            //                wr32(RAM_DL + 16, COLOR_RGB(160, 22, 22)); // change colour to red
            //                            //                wr32(RAM_DL + 20, POINT_SIZE(160)); // set point size to 20 pixels in radius
            //                            //                wr32(RAM_DL + 24, BEGIN(POINTS)); // start drawing points
            //                            //                wr32(RAM_DL + 28, VERTEX2II(192, 133, 0, 0)); // red point
            //                            //                wr32(RAM_DL + 32, END());
            //                            wr32(RAM_DL + 8, DISPLAY()); // Marque fin de la display list
            //                            //                wr8(REG_DLSWAP, DLSWAP_FRAME);
            //                            //                while (rd8(REG_DLSWAP) != DLSWAP_DONE);
            //            
            //                            wr8(REG_DLSWAP, DLSWAP_FRAME);
            //                            affich = 0;
            //                        }
            //            wr8(REG_GPIO_DIR, 0x80); // Met GPIO7 en sortie
            //            wr8(REG_GPIO, 0x80); // allume le backlight (met GPIO7 à 1)

            //            APP_UpdateState(APP_STATE_WAIT);

            break;
        }
        case APP_STATE_WAIT:

            /* TODO: implement your application state machine.*/


            /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

void APP_UpdateState(APP_STATES NewState) {
    appData.state = NewState;
}
// === Initialisation DMA Channel 0 vers OC2RS ===

void init_dma() {
    DMACONbits.ON = 1; // Active le contrôleur DMA global

    DCH0CON = 0; // Réinitialise la config du canal DMA 0
    DCH0ECON = 0; // Réinitialise le registre d'évènement du canal

    DCH0ECONbits.CHSIRQ = _TIMER_2_IRQ; // Déclenchement DMA sur interruption Timer2 (base de temps du PWM)
    DCH0ECONbits.SIRQEN = 1; // Active le déclenchement par IRQ

    DCH0SSA = KVA_TO_PA(&ws2812_pwm_data[0]); // Adresse source : début du tableau contenant les données PWM (GRB encodé)
    DCH0DSA = KVA_TO_PA(&OC2RS); // Adresse destination : registre de comparaison du PWM (OC2RS)

    DCH0SSIZ = sizeof (ws2812_pwm_data); // Taille totale de la source à envoyer
    DCH0DSIZ = 2; // Taille d?un élément de destination (OC2RS = 16 bits)
    DCH0CSIZ = 2; // Taille d?un bloc transféré à chaque déclenchement (un PWM)

    DCH0INTCLR = 0x00FF00FF; // Réinitialise tous les flags d?interruptions du DMA
    DCH0CONbits.CHEN = 1; // Active le canal DMA 0
}
// === Encodage des couleurs GRB en séquences PWM ===
// === Lancer DMA vers OC1 ===

void ws2812_update(rgb_t *led_array) {
    uint32_t bit_idx = 0; // Index pour remplir le tableau PWM
    int i, j, k, l; // Compteurs pour les boucles

    // Convertit chaque LED (RGB) en signal PWM au format GRB
    for (i = 0; i < NUM_LEDS; i++) {
        uint8_t data[3] = {led_array[i].g, // L?ordre GRB est exigé par WS2812
            led_array[i].r,
            led_array[i].b};

        for (j = 0; j < 3; j++) { // Parcourt les 3 composantes (G, R, B)
            for (k = 7; k >= 0; k--) { // Pour chaque bit (du plus fort au plus faible)
                if ((data[j] >> k) & 0x01)
                    ws2812_pwm_data[bit_idx++] = PWM_HIGH; // PWM_HIGH = logique '1'
                else
                    ws2812_pwm_data[bit_idx++] = PWM_LOW; // PWM_LOW = logique '0'
            }
        }
    }

    // Ajoute un signal de "reset" : au moins 50 µs de silence
    for (l = 0; l < 80; l++) {
        ws2812_pwm_data[bit_idx++] = 0; // Ajoute 80 valeurs nulles (80 × 1.25 µs ? 100 µs)
    }

    // Configuration et démarrage du DMA
    DCH0CONbits.CHEN = 0; // Désactive le canal DMA pour le reconfigurer
    DCH0SSA = KVA_TO_PA(&ws2812_pwm_data[0]); // Définit l?adresse source du transfert
    DCH0SSIZ = bit_idx * 2; // Taille à transférer (chaque PWM = 2 octets)
    DCH0CONbits.CHEN = 1; // Réactive le canal DMA

    DCH0ECONbits.CFORCE = 1; // Force le démarrage immédiat du DMA

    while (!DCH0INTbits.CHSDIF); // Attend que le transfert DMA soit terminé
    DCH0INTCLR = _DCH0INT_CHSDIF_MASK; // Réinitialise le flag de fin de transfert
}

// Fonction de conversion HSV (Teinte, Saturation, Valeur) vers RGB

rgb_t hsv_to_rgb(uint8_t h, uint8_t s, uint8_t v) {
    rgb_t rgb; // Structure qui contiendra la couleur en RGB

    if (s == 0) {
        // Si saturation nulle, on est dans une teinte de gris (pas de couleur)
        rgb.r = rgb.g = rgb.b = v; // Toutes les composantes prennent la valeur de luminosité
        return rgb; // Retourne la couleur
    }

    // Calcule dans quelle "région" du cercle chromatique on se trouve (il y en a 6)
    uint16_t region = h / 43; // Chaque région couvre 43 unités de teinte (255 / 6 ? 43)
    uint16_t remainder = (h % 43) * 6; // Reste de la division, utilisé pour interpolation fine  h/43 = x x + ? = h

    // Pré-calculs utilisés pour l'interpolation entre les couleurs
    uint16_t p = (v * (255 - s)) / 255;
    uint16_t q = (v * (255 - ((s * remainder) / 255))) / 255;
    uint16_t t = (v * (255 - ((s * (255 - remainder)) / 255))) / 255;

    // En fonction de la région de teinte, on applique un mélange RGB différent
    switch (region) {
        case 0:
            rgb.r = v; // Rouge max
            rgb.g = t; // Vert intermédiaire
            rgb.b = p; // Bleu minimum
            break;
        case 1:
            rgb.r = q;
            rgb.g = v;
            rgb.b = p;
            break;
        case 2:
            rgb.r = p;
            rgb.g = v;
            rgb.b = t;
            break;
        case 3:
            rgb.r = p;
            rgb.g = q;
            rgb.b = v;
            break;
        case 4:
            rgb.r = t;
            rgb.g = p;
            rgb.b = v;
            break;
        default: // case 5:
            rgb.r = v;
            rgb.g = p;
            rgb.b = q;
            break;
    }

    return rgb; // Retourne la couleur convertie
}
/*******************************************************************************
 End of File
 */