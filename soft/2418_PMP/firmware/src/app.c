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
#include <xc.h>
#include <stdint.h>
#include "Mc32DriverFT812.h"
#include <stdbool.h>

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// Adresses F812
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
#define RAM_DL          0x300000

// Broches /CS et /PD
/*
#define CS_LOW()        LATAbits.LATA0 = 0
#define CS_HIGH()       LATAbits.LATA0 = 1
#define PD_LOW()        LATAbits.LATA1 = 0
#define PD_HIGH()       LATAbits.LATA1 = 1
*/

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


void APP_Initialize ( void )
{
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

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
       
            ft812_init();
            
            // -------- DISPLAY LIST (écran bleu) --------
            // CLEAR_COLOR_RGB(0,0,255)
            ft812_memory_write8(0x300000, 0xFF);    // Blue
            ft812_memory_write8(0x300001, 0x00);    // Green
            ft812_memory_write8(0x300002, 0x00);    // Red
            ft812_memory_write8(0x300003, 0x02);    // Command clear_color
            
            // CLEAR(1,1,1)
            ft812_memory_write8(0x300004, 0x07);
            ft812_memory_write8(0x300005, 0x00);
            ft812_memory_write8(0x300006, 0x00);
            ft812_memory_write8(0x300007, 0x26);

            // DISPLAY()
            ft812_memory_write8(0x300008, 0x00);
            ft812_memory_write8(0x300009, 0x00);
            ft812_memory_write8(0x30000A, 0x00);
            ft812_memory_write8(0x30000B, 0x00);

            // -------- APPLY DISPLAY LIST --------
            ft812_memory_write8(0x302054, 0x02);        // DLSWAP ? active la display list

            // -------- ACTIVE DALLE --------
            ft812_memory_write8(0x302090, 0x80);        // GPIO_DIR ? GPIO7 sortie
            ft812_memory_write8(0x302094, 0x80);        // GPIO ? active DISP

            // -------- BACKLIGHT --------
            // PWM_HZ = 1000 (0x03E8)
            ft812_memory_write8(0x3020D0, 0xE8);        // fréquence PWM
            ft812_memory_write8(0x3020D1, 0x03);
            
            // PWM_DUTY = 128 (~100%)
            ft812_memory_write8(0x3020D4, 0x80);        // intensité backlight
        
            if (appInitialized)
            {
            
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            
            break;
        }

        /* TODO: implement your application state machine.*/
        

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

 

/*******************************************************************************
 End of File
 */
