//----------------------------------------------------------------------------//
//          Mc32DriverEveTft.h
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
// documetation : lien datasheet 
//----------------------------------------------------------------------------//

#ifndef _MC32DRIVEREVETFT_H
#define _MC32DRIVEREVETFT_H

//------------------------------------------------//
// Inclusion librairies
//------------------------------------------------//
#include <stdint.h>
#include <stdbool.h>

//------------------------------------------------//
// Param écran
//------------------------------------------------//


//------------------------------------------------//
// Définition des prototypes de fonctions
//------------------------------------------------//

//----------------------------------------------------------------------------------//
//-- nom fct : lcd_init 
//-- paramètre entrée : -
//-- paramètre sortie : -
//-- paramètre référence (IN-OUT) :   - 
//-- description : Initialisation du LCD et du chip FT812
//-- démonstration : - 
//-- aide - référence - lien : -
//----------------------------------------------------------------------------------//
void eve_init(void);

#endif _MC32DRIVEREVETFT_H

