//----------------------------------------------------------------------------//
//          Mc32DriverEveTft.c
//----------------------------------------------------------------------------//
// Description      :   Librairie crée pour le LCD 5.0-800480F-CTXL-T
//
// Auteur           :   Karol Stopa
// Date de création :   25.03.2026
// Compilateur      :   XC32 v2.50
//
// MODIFICATIONS    :
// KSA 25.03.2026       Création fichiers Mc32DriverEveTft.c et .h
//
//----------------------------------------------------------------------------//

//------------------------------------------------//
// Inclusions des fichiers header
//------------------------------------------------//

#include "Mc32DriverEveTft.h"
#include "Mc32DriverFT812.h"
#include "peripheral\SPI\plib_spi.h"

//------------------------------------------------//
// Fonctions
//------------------------------------------------//

void eve_init(void)
{
    // Initialisation du chip graphique
    ft812_init();
}
