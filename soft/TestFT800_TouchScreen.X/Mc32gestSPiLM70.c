// Mc32gestSpiDac.C
// Gestion master SPI avec slave DAC




#include <plib.h>
#include "Mc32gestSpiDac.h"
#include "SK32MX795F512L_V16.h"



// Definitions du bus
// #define SPI_SCL      PORTDbits.RD10  pin 70
// #define SPI_SDI      PORTCbits.RC4   pin 9
// #define SPI_SDO      PORTDbits.RD0   pin 72
// #define CS_LM70      LATDbits.LATD3  pin 78

// Initialisation de la communication SPI et du DAC
// ------------------------------------------------

void SPI_InitLM70(void)  {

   int isDataAvlbl, Trash;
  
   uint32  config = SPI_OPEN_MODE8 | SPI_OPEN_ON | SPI_OPEN_MSTEN ;
  
   // LM70 MAX 6.25 MHz choix 5 MHz (80/16 = 5.0)
   SpiChnOpen(SPI_CHANNEL1, config, 16);

    
   // Purge le tampon si il y des donnée
   isDataAvlbl=SpiChnDataRdy(SPI_CHANNEL1);
   while (isDataAvlbl != 0) {
       Trash = SpiChnReadC(SPI_CHANNEL1);
       isDataAvlbl = SpiChnDataRdy(SPI_CHANNEL1);
   }
  
   // action de configuration
   CS_LM70 = 0;
   Trash = spi_read1(0xFF);
   Trash = spi_read1(0xFF);
   Trash = spi_read1(0);  // pour écrire 0
   Trash = spi_read1(0);  // pour écrire 0

   //Fin de transmission
   CS_LM70 = 1;
  
}




// Lecture du registre de temperature du LM70
// Version avec reconfiguration pour partage bus spi avec un autre composant
sint16 SPI_ReadRawTempLM70(void)
{

   //Déclaration des variables
   int isDataAvlbl, Trash;
   uint8 MSB;
   uint8 LSB;
   sint16 RawTemp;
   uint32  config = SPI_OPEN_MODE8 | SPI_OPEN_ON | SPI_OPEN_MSTEN ;

   // LM70 MAX 6.25 MHz choix 5 MHz (80/16 = 5.0)
   SpiChnOpen(SPI_CHANNEL1, config, 16);


   // Purge le tampon si il y des donnée
   isDataAvlbl=SpiChnDataRdy(SPI_CHANNEL1);
   while (isDataAvlbl != 0) {
       Trash = SpiChnReadC(SPI_CHANNEL1);
       isDataAvlbl=SpiChnDataRdy(SPI_CHANNEL1);
   }

   CS_LM70 = 0;
   MSB = spi_read1(0xFF);
   LSB = spi_read1(0xFF);
   //Fin de transmission
   CS_LM70 = 1;

   RawTemp = MSB;
   RawTemp = RawTemp << 8;
   RawTemp = RawTemp | LSB;
   return RawTemp;
} // SPI_ReadRawTempLM70
   

// Passage par référence car problème avec return lors affectation
// a une variable globale dans réponse à interruption

void LM70_ConvRawToDeg( sint16 RowTemp, float *pTemp)
{
   
}

 



