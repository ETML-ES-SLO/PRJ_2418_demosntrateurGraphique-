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
void ft812_send_host_command(uint8_t command, uint8_t commandParam)
{
    CS_LOW();
    
    int SpiBusy;
   
   // MSB firt
    PLIB_SPI_BufferWrite(SPI_ID_1, (HOST_COMMAND_BEGINNING + command));
    PLIB_SPI_BufferWrite(SPI_ID_1, commandParam);
    PLIB_SPI_BufferWrite(SPI_ID_1, HOST_COMMAND_END);

   do {
     SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
   } while (SpiBusy == 1);
   
   CS_HIGH();
}

void ft812_init(void)
{
    
}

void spi1_wrtie8(uint8_t data8)
{
    CS_LOW();
    
    int SpiBusy;
   
   PLIB_SPI_BufferWrite(SPI_ID_1, data8);

   do {
     SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
   } while (SpiBusy == 1);
   
   CS_HIGH();
}

void spi1_wrtie16(uint16_t data16)
{
    CS_LOW();
    
    int SpiBusy;
    
    // MSB firt
    PLIB_SPI_BufferWrite(SPI_ID_1, (data16 >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (data16 & 0xFF));

    do {
        SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
    } while (SpiBusy == 1);
   
    CS_HIGH();
}

void spi1_wrtie32(uint32_t data32)
{
    CS_LOW();
    
    int SpiBusy;
   
    // MSB firt
    PLIB_SPI_BufferWrite(SPI_ID_1, (data32 >> 24) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (data32 >> 16) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (data32 >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (data32 & 0xFF));

    do {
        SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
    } while (SpiBusy == 1);
   
    CS_HIGH();
}
