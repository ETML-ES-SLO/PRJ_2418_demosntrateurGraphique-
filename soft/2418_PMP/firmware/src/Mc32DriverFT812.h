//----------------------------------------------------------------------------//
//          Mc32DriverFT812.h
//----------------------------------------------------------------------------//
// Description      :   Librairie pour driver graphique FT812
//
// Auteur           :   Karol Stopa
// Date de création :   11.03.2026
// Compilateur      :   XC32 v2.50
//
// MODIFICATIONS    :
// KSA 11.03.2026       Création fichiers Mc32DriverFT812.c et .h
//
// documetation : lien datasheet 
//----------------------------------------------------------------------------//

#ifndef _MC32DRIVERFT812_H
#define _MC32DRIVERFT812_H

//------------------------------------------------//
// Inclusion librairies
//------------------------------------------------//
#include <stdint.h>
#include <stdbool.h>

#define SELECT_KIT_ES_PIC32

//------------------------------------------------//
// Param écran
//------------------------------------------------//
#define LCD_HSIZE       800 // Largeur visible en pixel
#define LCD_HCYCLE      928 // Largeur total en pixel
#define LCD_HOFFSET     88  // Début zone visible en pixel
#define LCD_HSYNC0      0   // Début HSYNC
#define LCD_HSYNC1      48  // Fin HSYNC

#define LCD_VSIZE       480 // Hauteur visible en pixel
#define LCD_VCYCLE      525 // Hauteur total en pixel
#define LCD_VOFFSET     32  // Début zone visible en pixel
#define LCD_VSYNC0      0   // Début VSYNC
#define LCD_VSYNC1      3   // Fin VSYNC

#define LCD_PCLK        2   
#define LCD_SWIZZLE     0   // Mapping RBG standard
#define LCD_PCLK_POL    0   // Polarité pixel clock
#define LCD_CSPREAD     0   // Désactive le clock spreading
#define LCD_DITHER      0   // Active le dithering couleur

//------------------------------------------------//
// Param FT812
//------------------------------------------------//
#define HOST_COMMAND_END        0x00
#define HOST_COMMAND_BEGINNING  0x40
#define MEM_WRITE_BEGINNING     0x80
#define MEM_READ_DUMMY_BYTE     0x00

//------------------------------------------------//
// Host Command (HC) List
//------------------------------------------------//
// Power modes
#define HC_MODE_ACTIVE  0x00
#define HC_MODE_STANDBY 0x41
#define HC_MODE_SLEEP   0x42
#define HC_MODE_PWRDOWN 0x43
#define HC_MODE_PD_ROMS 0x49    // Pas de param crée

// Clock & Reset
#define HC_CLKEXT       0x44
#define HC_CLKINT       0x48
#define HC_CLKSEL       0x61    // Pas de param crée
#define HC_RST_PULSE    0x68

// Configuration
#define HC_CFG_PINDRIVE     0x70    // Pas de param crée
#define HC_CFG_PIN_PD_STATE 0x71    // Pas de param crée

//------------------------------------------------//
// Host Command Param (HCP) List
//------------------------------------------------//
#define HCP_PARAM_EMPTY 0x00

//------------------------------------------------//
// Définition des adresse mémoire du driver FT812
//------------------------------------------------//

// Adresses de configuration
#define REG_HSIZE       0x302034
#define REG_VSIZE       0x302048
#define REG_HCYCLE      0x30202C
#define REG_HOFFSET     0x302030
#define REG_HSYNC0      0x302038
#define REG_HSYNC1      0x30203C
#define REG_VCYCLE      0x302040
#define REG_VOFFSET     0x302044
#define REG_VSYNC0      0x30204C
#define REG_VSYNC1      0x302050
#define REG_PCLK        0x302070
#define REG_DLSWAP      0x302054
#define REG_SWIZZLE     0x302064
#define REG_PCLK_POL    0x30206C
#define REG_CSPREAD     0x302068
#define REG_DITHER      0x302060
#define RAM_DL          0x300000

// Autres lecture
#define REG_ID          0x302000
#define REG_FRAMES      0x302004
#define REG_CLOCK       0x302008
#define REG_FREQUENCY   0x30200C

//------------------------------------------------//
// Définition des valeurs mémoire du driver FT812
//------------------------------------------------//

#define REG_ID_VALUE    0x7C

//------------------------------------------------//
// Macros
//------------------------------------------------//

#ifdef SELECT_KIT_ES_PIC32 

// Chip select pour SPI
#define CS_LOW          LATAbits.LATA0 = 0
#define CS_HIGH         LATAbits.LATA0 = 1

// Chip graphique
#define PD_LOW          LATAbits.LATA1 = 0  // Désactive chip graph.
#define PD_HIGH         LATAbits.LATA1 = 1  // Active chip graphique

#endif 

//------------------------------------------------//
// Définition des prototypes de fonctions
//------------------------------------------------//

//----------------------------------------------------------------------------------//
//-- nom fct : ft812_memory_write8 
//-- paramètre entrée : command => Commande host
//--                    commandParam => Paramètre de la commande
//-- paramètre sortie : -
//-- paramètre référence (IN-OUT) :   - 
//-- description : Envoie de 24 bits par SPI pour envoie de commande sur FT812 
//-- démonstration : [0x40 + commande][param][0x00] 
//-- aide - référence - lien : Page.16 du datasheet DS_FT81x.pdf
//----------------------------------------------------------------------------------//
void ft812_memory_write8(uint32_t address, uint8_t data);

//----------------------------------------------------------------------------------//
//-- nom fct : ft812_memory_write8 
//-- paramètre entrée : command => Commande host
//--                    commandParam => Paramètre de la commande
//-- paramètre sortie : -
//-- paramètre référence (IN-OUT) :   - 
//-- description : Envoie de 24 bits par SPI pour envoie de commande sur FT812 
//-- démonstration : [0x40 + commande][param][0x00] 
//-- aide - référence - lien : Page.16 du datasheet DS_FT81x.pdf
//----------------------------------------------------------------------------------//
void ft812_memory_write16(uint32_t address, uint16_t data);

//----------------------------------------------------------------------------------//
//-- nom fct : ft812_memory_write8 
//-- paramètre entrée : command => Commande host
//--                    commandParam => Paramètre de la commande
//-- paramètre sortie : -
//-- paramètre référence (IN-OUT) :   - 
//-- description : Envoie de 24 bits par SPI pour envoie de commande sur FT812 
//-- démonstration : [0x40 + commande][param][0x00] 
//-- aide - référence - lien : Page.16 du datasheet DS_FT81x.pdf
//----------------------------------------------------------------------------------//
void ft812_memory_write32(uint32_t address, uint32_t data);

//----------------------------------------------------------------------------------//
//-- nom fct : ft812_send_host_command 
//-- paramètre entrée : command => Commande host
//--                    commandParam => Paramètre de la commande
//-- paramètre sortie : -
//-- paramètre référence (IN-OUT) :   - 
//-- description : Envoie de 24 bits par SPI pour envoie de commande sur FT812 
//-- démonstration : [0x40 + commande][param][0x00] 
//-- aide - référence - lien : Page.16 du datasheet DS_FT81x.pdf
//----------------------------------------------------------------------------------//
void ft812_send_host_command(uint8_t command, uint8_t commandParam);

//----------------------------------------------------------------------------------//
//-- nom fct : ft812_init 
//-- paramètre entrée : type générique - nom variable 
//-- paramètre sortie : type générique - nom variable 
//-- paramètre référence (IN-OUT) :   type générique - nom variable 
//-- description : fonctionnement de la fct en quelques mots 
//-- démonstration : calcul 
//-- aide - référence - lien : doc externe pour la compréhension de la fct 
//----------------------------------------------------------------------------------//
void ft812_init(void);

uint8_t ft812_memory_read8(uint32_t address);

#endif _MC32DRIVERFT812_H

