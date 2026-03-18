//----------------------------------------------------------------------------//
//          Mc32DriverFT812.h
//----------------------------------------------------------------------------//
// Description      :    Librairie pour driver graphique FT812
//
// Auteur           :   Karol Stopa
// Date de création :   11.03.2026
// Compilateur      :   XC32 v2.50
//
// MODIFICATIONS    :
// KSA 11.03.2026       Création fichiers Mc32DriverFT812.c et .h
//
//----------------------------------------------------------------------------//

#ifndef _MC32DRIVERFT812_H
#define _MC32DRIVERFT812_H

//------------------------------------------------//
// Inclusion librairies
//------------------------------------------------//
#include <stdint.h>
#include <stdbool.h>

//------------------------------------------------//
// Param écran
//------------------------------------------------//
#define HSIZE 0

//------------------------------------------------//
// Définition des adresse mémoire du driver FT812
//------------------------------------------------//
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

//------------------------------------------------//
// Macros
//------------------------------------------------//

// Chip select pour SPI
#define CS_LOW()        LATAbits.LATA0 = 0
#define CS_HIGH()       LATAbits.LATA0 = 1

// Chip graphique
#define PD_LOW()        LATAbits.LATA1 = 0  // Désactive chip graph.
#define PD_HIGH()       LATAbits.LATA1 = 1 // Active chip graphique

//------------------------------------------------//
// Définition des prototypes de fonctions
//------------------------------------------------//

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

//----------------------------------------------------------------------------------//
//-- nom fct : spi1_wrtie8  
//-- paramètre entrée : type générique - nom variable 
//-- paramètre sortie : type générique - nom variable 
//-- paramètre référence (IN-OUT) :   type générique - nom variable 
//-- description : fonctionnement de la fct en quelques mots 
//-- démonstration : calcul 
//-- aide - référence - lien : doc externe pour la compréhension de la fct 
//----------------------------------------------------------------------------------//
void spi1_wrtie8(uint8_t data);

//----------------------------------------------------------------------------------//
//-- nom fct : spi1_wrtie16 
//-- paramètre entrée : type générique - nom variable 
//-- paramètre sortie : type générique - nom variable 
//-- paramètre référence (IN-OUT) :   type générique - nom variable 
//-- description : fonctionnement de la fct en quelques mots 
//-- démonstration : calcul 
//-- aide - référence - lien : doc externe pour la compréhension de la fct 
//----------------------------------------------------------------------------------//
void spi1_wrtie16(void);

//----------------------------------------------------------------------------------//
//-- nom fct : spi1_wrtie32  
//-- paramètre entrée : type générique - nom variable 
//-- paramètre sortie : type générique - nom variable 
//-- paramètre référence (IN-OUT) :   type générique - nom variable 
//-- description : fonctionnement de la fct en quelques mots 
//-- démonstration : calcul 
//-- aide - référence - lien : doc externe pour la compréhension de la fct 
//----------------------------------------------------------------------------------//
void spi1_wrtie32(void);

#endif _MC32DRIVERFT812_H

