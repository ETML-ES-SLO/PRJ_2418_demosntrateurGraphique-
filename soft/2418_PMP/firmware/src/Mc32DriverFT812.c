//----------------------------------------------------------------------------//
//          Mc32DriverFT812.c
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

//------------------------------------------------//
// Inclusions des fichiers header
//------------------------------------------------//

#include "Mc32DriverFT812.h"
#include "peripheral\SPI\plib_spi.h"

//------------------------------------------------//
// Inclusions des fichiers header
//------------------------------------------------//

//------------------------------------------------//
// Fonctions
//------------------------------------------------//
void ft812_init(void)
{
    
}

void spi1_wrtie8(uint8_t data)
{
    CS_LOW();
    
    int SpiBusy;
   
   PLIB_SPI_BufferWrite(SPI_ID_1, data);

   do {
     SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
   } while (SpiBusy == 1);
   
   CS_HIGH();
}

