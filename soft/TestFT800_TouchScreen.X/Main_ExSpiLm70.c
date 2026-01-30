/*--------------------------------------------------------*/
// Fichier 		Main_ExSpiLm70
/*--------------------------------------------------------*/
//	Description : 	Exercice  SPI master avec slave DAC et LM70
//
//	Auteur 		: 	C. Huber
//      Création	: 	12.05.2014
// Modifications :
//      C. HUBER    12.03.2014    ajout config aux #pragma
//                                Effet : SYS_CLK = PB_CLK = 80 MHz

#include <GenericTypeDefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <plib.h>

#include "SK32MX795F512L_V16.h"
#include "Mc32Delays.h"
#include "Mc32gestSpiDac.h"
#include "Mc32gestSpiFT800.h"
//=====================================----------------------------------------
// Fuses configuration
//=====================================----------------------------------------
// Set configuration fuses (but only once)

// @@@@@@@@@ ATTENTION XC32 #pragma config

// Set clock configuration
#pragma config POSCMOD = HS // Primary Oscillator mode = HS
#pragma config FSOSCEN = OFF // Secondary Oscillator Disable
#pragma config IESO = OFF // Internal External Switch Over bit Disable
#pragma config FNOSC = PRIPLL // Primary oscillator (XT, HS, EC) w/ PLL
#pragma config OSCIOFNC = OFF // Disabled output on clko pin
#pragma config FCKSM = CSDCMD // Clock Switching Disabled, Clock Monitoring Disabled

// Set system PLL configuration (Quartz 8 MHz pour SysClk à 80 Mhz)
#pragma config FPLLIDIV = DIV_2 // Divide by 2 clock for input to pll ->4MHz
#pragma config FPLLMUL = MUL_20 // Multiply by 20 -> pll output = 80MHz
#pragma config FPLLODIV = DIV_1 // System clock = pll Divide by 1 = 80MHz

// Set peripheral clk div
#pragma config FPBDIV = DIV_8    // Divide by 8 @@@ semble prendre 1


// Set power up timer
// #pragma  PUT = ON   // N'existe pas ???

// set USB
#pragma config FVBUSONIO = OFF // VBUS_ON pin is controlled by the Port Function
#pragma config FUSBIDIO = OFF // USBID pin is controlled by the Port Function

// Set CAN
#pragma config FCANIO = ON // Default CAN IO Pins

// Set Ethernet
#pragma config FETHIO = ON // Default Ethernet IO Pins
#pragma config FMIIEN = ON // MII enabled

// set watchdog
#pragma  config FWDTEN = OFF // Disabled

// Set code protect
#pragma config CP = OFF // Disabled

// Set boot flash code protect
#pragma config BWP = OFF // Disabled

// Set ICD3 channel
#pragma config ICESEL = ICS_PGx2 // ICE pins are shared with PGC2, PGD2

// Set debug bit
#pragma config DEBUG = ON // Enabled

//=====================================----------------------------------------
// définitions des constantes et des variables
//=====================================----------------------------------------

// Variable partagée entre main et interruption
volatile int DispToDo = 0;
volatile float LM70Temp = 15.3;
volatile sint16 LM70RawTemp = 0x55AA;




//=====================================----------------------------------------
// prototypes (nécessaires si des fonctions sont appelées avant d'être définies,
//     par exemple pour les interruptions)
//=====================================----------------------------------------


//=====================================----------------------------------------
// définitions et mise en place des fonctions d'interruptions
// les fonctions d'interruptions peuvent être définies n'importe où dans le code,
// mais généralement elles sont définies au début de la partie programme
//=====================================----------------------------------------


//=====================================----------------------------------------
// définitions pour les Timers
//=====================================----------------------------------------

#define SYS_FREQ (80000000L)    //80 MHz
#define PB_DIV 1
#define PB_FREQ (SYS_FREQ / PB_DIV)

//#define OPT_RIGHTX 2048UL
#define wait3secs(); delay_ms(3000);

//=====================================----------------------------------------
// fonction main
//=====================================----------------------------------------
void main (void){

   char Buffer[21];
  // disable JTAG port to free RA0, RA1, RA4 et RA5
  mJTAGPortEnable(0);

  // memory wait states fine tuning
  int Pb_Freq = SYSTEMConfigPerformance(SYS_FREQ);
  // remarque cette fonction impose PB_CLOCK = SYS_CLOCK;

// Default SK32MX775F512L i/os config and values
  SK32MX795F512L_IO_Default();  

  // Init FT800
  InitFT800();
  // Configuration Timer1 cycle 100 us
  

  // Set up the timer interrupt with a priority of 6
  
    // LOGO test
    



    while(1)
    {

        /*cmd(CMD_DLSTART);
        cmd(CLEAR(1, 1, 1));
        cmd_text(10, 10, 31, 0, "Hello ceci est un test!");
        cmd(DISPLAY()); // display the image
        cmd(CMD_SWAP);
        cmd_exec();*/

        cmd(CMD_DLSTART);
        cmd(COLOR_RGB(255,255,0));
        //cmd(POINT_SIZE(30));
        cmd(VERTEX2II(0,0,0,0));
        cmd(DISPLAY()); // display the image
        cmd(CMD_SWAP);
        cmd_exec();
    }

}  // End main


// Réponse à l'interruption du Timer1 (cycle de 100 us)

 

 