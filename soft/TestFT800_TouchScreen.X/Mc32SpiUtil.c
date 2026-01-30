// Mc32SpiUtil.C
// Utilitaire  SPI
//
//	Description : 	fonctions SPI CCS like
//	Auteur 		: 	C. HUBER
//      Création	: 	08.04.2014

//  LISTE DES MODIFICATIONS :

//      Version KIT     PCB 11020_B
//	Version		:	V1.0
//	Compilateur	:	XC32 V1.31
/*--------------------------------------------------------*/

// Attention les fonctions de lectures ne fonctionnent pas !!

#include <plib.h>
#include "Mc32SpiUtil.h"
#include "SK32MX795F512L_V16.h"



void spi_write1( uint8 Val){
   int SpiBusy;
   SpiChnPutC(SPI_CHANNEL1, Val);
   do {
     SpiBusy =  SpiChnIsBusy(SPI_CHANNEL1) ;
   } while (SpiBusy == 1);
}

void spi_write2( uint8 Val){
   int SpiBusy;
   SpiChnPutC(SPI_CHANNEL2, Val);
   do {
     SpiBusy =  SpiChnIsBusy(SPI_CHANNEL2) ;
   } while (SpiBusy == 1);
}
// a méditer
#define rcvr_spi_m(p)   SPI2BUF = 0xFF; while (!SPI2STATbits.SPIRBF); *(p) = (PF_BYTE)SPI2BUF;

uint8 spi_read1( uint8 Val){
   int SpiDataReady;
   uint32 lu;

   SpiChnPutC(SPI_CHANNEL1, Val);
   // Attente DataReady
   do {
        SpiDataReady =  SpiChnDataRdy(SPI_CHANNEL1) ;
   } while (SpiDataReady == 0);
   lu = SpiChnReadC(SPI_CHANNEL1);
   return lu;
}

 uint8 spi_read2( uint8 Val){
   int SpiDataReady;
   uint32 lu;

   SpiChnPutC(SPI_CHANNEL2, Val);
    do {
        SpiDataReady =  SpiChnDataRdy(SPI_CHANNEL2) ;
   } while (SpiDataReady == 0);
   lu = SpiChnReadC(SPI_CHANNEL2);
   return lu;
}



