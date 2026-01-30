#ifndef __SK32MX795F512L_H
#define __SK32MX795F512L_H
/*--------------------------------------------------------*/
// Fichier SK32MX795F512L_V16.h
/*--------------------------------------------------------*/
//	Description : 	Définition des pattes	       
//	Auteur 		: 	F. Dominé
//      Création	: 	09.02.2012
//      Adaptation  :       12.02.2014 C. HUBER
//  LISTE DES MODIFICATIONS :
//      CHR  26.03.2014 : pont en H passage en LAT
//      CHR  27.03.2014 : Analog adaptation schéma B et suppression Analog2 et 3
//      CHR  03.04.2013 : SPI passage des CSx en LAT
//      CHR  10.04.2013 : Remplacement DDR par LAT
//
//      Version KIT     PCB 11020_B
//	Version		:	V1.6
//	Compilateur	:	XC32 V1.31
/*--------------------------------------------------------*/

/*--------------------------------------------------------*/
/* Analogique
/*--------------------------------------------------------*/
// CHR 27.03.2014 adaptation schéma B et suppression Analog2 et 3
#define Analog0		PORTBbits.RB0
//#define Analog1		PORTBbits.RB1
#define FT800_PD_W      LATBbits.LATB1
#define FT800_PD_R      PORTbits.RB1
#define FT800_PD_T      TRISBbits.TRISB1

/*--------------------------------------------------------*/
/* Clavier matriciel
/*--------------------------------------------------------*/
	/*----------------------------------------------------*/
	/* Colonnes
	/*----------------------------------------------------*/

        // CHR 10.04.2014 remplacement _T par W et ajout section T
	//#define COLONNE1     PORTBbits.RB2
        #define FT800_INT_R     PORTBbits.RB2
	//#define COLONNE2     PORTBbits.RB3
        #define FT800_CS_R     PORTBbits.RB3
	#define COLONNE3     PORTBbits.RB4
	#define COLONNE4     PORTBbits.RB5
	
	//#define COLONNE1_W   LATBbits.LATB2
        #define FT800_INT_W      LATBbits.LATB2 // Pour FT800
	//#define COLONNE2_W   LATBbits.LATB3
        #define FT800_CS_W       LATBbits.LATB3 // Pour FT800
	#define COLONNE3_W   LATBbits.LATB4
	#define COLONNE4_W   LATBbits.LATB5

        //#define COLONNE1_T   TRISBbits.TRISB2
        #define FT800_INT_T   TRISBbits.TRISB2
	//#define COLONNE2_T   TRISBbits.TRISB3
        #define FT800_CS_T   TRISBbits.TRISB3
	#define COLONNE3_T   TRISBbits.TRISB4
	#define COLONNE4_T   TRISBbits.TRISB5
	/*----------------------------------------------------*/
	// Lignes
	/*----------------------------------------------------*/
        // CHR 10.04.2014 remplacement _T par W et ajout section T

	#define LIGNE1       PORTGbits.RG6
	#define LIGNE2       PORTGbits.RG7
	#define LIGNE3       PORTBbits.RB14
	#define LIGNE4       PORTBbits.RB15
	
	#define LIGNE1_W     LATGbits.LATG6
	#define LIGNE2_W     LATGbits.LATG7
	#define LIGNE3_W     LATBbits.LATB14
	#define LIGNE4_W     LATBbits.LATB15

        #define LIGNE1_T     TRISGbits.TRISG6
	#define LIGNE2_T     TRISGbits.TRISG7
	#define LIGNE3_T     TRISBbits.TRISB14
	#define LIGNE4_T     TRISBbits.TRISB15
/*--------------------------------------------------------*/
/* PEC12 
/*--------------------------------------------------------*/
#define PEC12_A      PORTGbits.RG14
#define PEC12_B      PORTGbits.RG15
#define PEC12_PB     PORTGbits.RG12

/*--------------------------------------------------------*/
/* Touches 
/*--------------------------------------------------------*/
#define S_OK         PORTGbits.RG12
#define S_ESC_MENU   PORTGbits.RG13
#define S_PLUS       PORTGbits.RG14
#define S_MINUS      PORTGbits.RG15

/*--------------------------------------------------------*/
/* I2C
/*--------------------------------------------------------*/
#define I2C_SCL      PORTAbits.RA2
#define I2C_SDA      PORTAbits.RA3
#define I2C_SDA_T    LATAbits.LATA3

/*--------------------------------------------------------*/
/* SPI
/*--------------------------------------------------------*/
#define SPI_SCL      PORTDbits.RD10
#define SPI_SDI      PORTCbits.RC4
#define SPI_SDO      PORTDbits.RD0
	/*----------------------------------------------------*/
	/* Chip Select
	/*----------------------------------------------------*/

        // Sortie : utilisation de LAT
        // CHR 03.04.2013  : passage des CSx en LAT
	#define CS_LM70      LATDbits.LATD3
	#define CS_DAC       LATDbits.LATD4
	#define CS_SD        LATDbits.LATD5
	
/*--------------------------------------------------------*/
/* Ethernet
/*--------------------------------------------------------*/
#define ETH_TX_EN	PORTDbits.RD6
#define ETH_TX_CLK	PORTDbits.RD7
#define ETH_MDIO	PORTDbits.RD8
#define ETH_MDC		PORTDbits.RD11	
#define ETH_RD_ER	PORTBbits.RB11	
#define ETH_D0		PORTBbits.RB12	
#define ETH_D1		PORTBbits.RB13	
// Attention
#define ETH_POWERDOWN_INT   PORTAbits.RA14
#define ETH_AN_EN	PORTEbits.RE8	
#define ETH_AN0		PORTEbits.RE9	
#define ETH_TX_D1	PORTFbits.RF0	
#define ETH_TX_D0	PORTFbits.RF1	
#define ETH_CRS_DV	PORTGbits.RG8	
#define ETH_RST		PORTGbits.RG9	

/*----------------------------------------------------*/
/* SD Card 
/*----------------------------------------------------*/
#define SD_DETECT	PORTCbits.RC3

/*----------------------------------------------------*/
/* DAC
/*----------------------------------------------------*/
#define DAC_CLEAR	LATDbits.LATD9   // LAT !!!

/*--------------------------------------------------------*/
/* LEDs
/*--------------------------------------------------------*/

// Attention 11020_B modification du câblage
// -----------------------------------------
// Led0   RA0    D6
// Led1   RA1    D10
// Led2   RA4    D7
// Led3   RA5    D11
// Led4   RA6    D8
// Led5   RA7    D12
// Led6   RA15   D9
// Led7   RB10   D13   !!! port B

//On écrit dans le latch pour éviter les problèmes de R/W
#define LED0_W       LATAbits.LATA0  //Led0
#define LED1_W       LATAbits.LATA1  //Led1
#define LED2_W       LATAbits.LATA4  //Led2
#define LED3_W       LATAbits.LATA5  //Led3
#define LED4_W       LATAbits.LATA6  //Led4
#define LED5_W       LATAbits.LATA7  //Led5
#define LED6_W       LATAbits.LATA15 //Led6
#define LED7_W       LATBbits.LATB10 //Led7
//On lit directement sur le port, sinon on obtient la valeur
//précédemment écrite dans le latch!!
#define LED0_R       PORTAbits.RA0 //Led0
#define LED1_R       PORTAbits.RA1 //Led1
#define LED2_R       PORTAbits.RA4 //Led2
#define LED3_R       PORTAbits.RA5 //Led3
#define LED4_R       PORTAbits.RA6 //Led4
#define LED5_R       PORTAbits.RA7 //Led5
#define LED6_R       PORTAbits.RA15 //Led6
#define LED7_R       PORTBbits.RB10 //Led7

#define LED0_T     TRISAbits.TRISA0
#define LED1_T     TRISAbits.TRISA1
#define LED2_T     TRISAbits.TRISA4
#define LED3_T     TRISAbits.TRISA5
#define LED4_T     TRISAbits.TRISA6
#define LED5_T     TRISAbits.TRISA7
#define LED6_T     TRISAbits.TRISA15
#define LED7_T     TRISBbits.TRISB10

/*--------------------------------------------------------*/
/* USB
/*--------------------------------------------------------*/
#define USB_DETECT	PORTFbits.RF3
#define USB_PLUS	PORTGbits.RG2
#define USB_MINUS	PORTGbits.RG3

/*--------------------------------------------------------*/
/* RS232
/*--------------------------------------------------------*/
#define RS232_TX     PORTFbits.RF8
#define RS232_RX     PORTFbits.RF2
#define RS232_RTS    PORTDbits.RD15
#define RS232_CTS    PORTDbits.RD14

/*--------------------------------------------------------*/
/* LCD
/*--------------------------------------------------------*/
//On écrit dans le latch pour éviter les problèmes de R/W
#define LCD_RS_W       LATEbits.LATE0
#define LCD_RW_W       LATEbits.LATE1
#define LCD_E_W        LATEbits.LATE2
#define LCD_BL_W       LATEbits.LATE3
#define LCD_DB4_W      LATEbits.LATE4
#define LCD_DB5_W      LATEbits.LATE5
#define LCD_DB6_W      LATEbits.LATE6
#define LCD_DB7_W      LATEbits.LATE7
//On lit directement sur le port, sinon on obtient la valeur
//précédemment écrite dans le latch!!
#define LCD_RS_R       PORTEbits.RE0
#define LCD_RW_R       PORTEbits.RE1
#define LCD_E_R        PORTEbits.RE2
#define LCD_BL_R       PORTEbits.RE3
#define LCD_DB4_R      PORTEbits.RE4
#define LCD_DB5_R      PORTEbits.RE5
#define LCD_DB6_R      PORTEbits.RE6
#define LCD_DB7_R      PORTEbits.RE7

#define LCD_RS_T     TRISEbits.TRISE0
#define LCD_RW_T     TRISEbits.TRISE1
#define LCD_E_T      TRISEbits.TRISE2
#define LCD_BL_T     TRISEbits.TRISE3
#define LCD_DB4_T    TRISEbits.TRISE4
#define LCD_DB5_T    TRISEbits.TRISE5
#define LCD_DB6_T    TRISEbits.TRISE6
#define LCD_DB7_T    TRISEbits.TRISE7

/*--------------------------------------------------------*/
/* Ponts en H
/*--------------------------------------------------------*/
// Attention STBY en RB8
// Signaux de commande = sortie = LATCH
#define STBY_HBRIDGE	LATBbits.LATB8     // new
#define AIN1_HBRIDGE	LATDbits.LATD12    // new
#define AIN2_HBRIDGE	LATDbits.LATD13    // new
#define PWMA_HBRIDGE	PORTDbits.RD1
#define BIN1_HBRIDGE	LATCbits.LATC1
#define BIN2_HBRIDGE	LATCbits.LATC2
#define PWMB_HBRIDGE	PORTDbits.RD2

/*--------------------------------------------------------*/
/* XBee
/*--------------------------------------------------------*/
#define XBEE_TX      PORTFbits.RF5
#define XBEE_RX      PORTFbits.RF4
#define XBEE_RTS     PORTFbits.RF13
#define XBEE_CTS     PORTFbits.RF12
#define XBEE_ON_SLEEP	PORTGbits.RG0
#define XBEE_RESET	PORTGbits.RG1

/*--------------------------------------------------------*/
/* RTCC
/*--------------------------------------------------------*/
// Supprimé  (maintenant LED7)
//#define RTCC_MFP	PORTBbits.RB10


/*--------------------------------------------------------*/
/* Définition des fonctions prototypes
/*--------------------------------------------------------*/
void SK32MX795F512L_IO_Default(void);

#endif
