// Mc32gestSpiDac.C
// Gestion master SPI avec slave DAC

// Pilote du DAC LTC2604
// Auteur C. Huber  30.04.2012

#include <plib.h>
#include "Mc32gestSpiDac.h"
#include "Mc32SpiUtil.h"
#include "SK32MX795F512L_V16.h"

// Definitions du bus
// #define SPI_SCL      PORTDbits.RD10  pin 70
// #define SPI_SDI      PORTCbits.RC4   pin 9
// #define SPI_SDO      PORTDbits.RD0   pin 72
// #define CS_DAC       LATDbits.LATD4  pin 81

// Initialisation de la communication SPI et du DAC
// ------------------------------------------------


void InitLTC2604(void)  {

   uint32  config = SPI_OPEN_MODE8 | SPI_OPEN_ON | SPI_OPEN_CKP_HIGH |
                    SPI_OPEN_MSTEN ;
   
   uint32 ConfigReg;
   //Initialisation SPI DAC
   CS_DAC = 1;
   // Impulsion reset du DAC
   DAC_CLEAR = 0;
   delay_us(500);
   DAC_CLEAR = 1;
   // LTC2604 MAX 50 MHz choix 20 MHz
   SpiChnOpen(SPI_CHANNEL1, config, 4);   // 20 MHz

   // Controle le la configuration
   ConfigReg = SPI1CON;

}


 // Envoi d'une valeur sur le DAC  LTC2604
// Indication du canal 0 à 3
void SPI_WriteToDac(uint8 NoCh, uint16 DacVal)
{

//Déclaration des variables
   uint8 MSB;
   uint8 LSB;
   uint32  config = SPI_OPEN_MODE8 | SPI_OPEN_ON | SPI_OPEN_CKP_HIGH |
                    SPI_OPEN_MSTEN ;

   // Reconfiguration LTC2604 MAX 50 MHz choix 20 MHz
   SpiChnOpen(SPI_CHANNEL1, config, 4);   // 20 MHz
   
   //Sélection du canal
   //3 -> Set and Update, 0/1/2/3 Sélection canal A/B/C/D, F tous canaux
   NoCh = NoCh + 0x30;

   // Selon canal
   MSB =  DacVal >> 8;
   LSB =  DacVal;

   CS_DAC = 0;
   spi_write1(NoCh);
   spi_write1(MSB);
   spi_write1(LSB);
 
   //Fin de transmission
   CS_DAC = 1;

} // SPI_WriteToDac
   



 



