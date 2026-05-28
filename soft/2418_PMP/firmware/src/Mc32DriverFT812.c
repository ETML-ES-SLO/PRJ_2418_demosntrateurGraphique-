//----------------------------------------------------------------------------//
//          Mc32DriverFT812.c
//----------------------------------------------------------------------------//
// Description      :   Librairie pour driver graphique FT812
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
#include "Mc32Delays.h"

//------------------------------------------------//
// Fonctions
//------------------------------------------------//


void ft812_send_host_command(uint8_t command, uint8_t commandParam)
{
    // Déclarations de variables
    int SpiBusy;
    
    // Algorithme pour l'envoi sur SPI
    CS_LOW;
   
    PLIB_SPI_BufferWrite(SPI_ID_1, command);
    PLIB_SPI_BufferWrite(SPI_ID_1, commandParam);
    PLIB_SPI_BufferWrite(SPI_ID_1, HOST_COMMAND_END);

   do {
     SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
   } while (SpiBusy == 1);
   
   CS_HIGH;
}

void ft812_memory_write8(uint32_t address, uint8_t data)
{
    // Déclarations de variables
    int SpiBusy;
    
    // Algorithme pour l'envoi sur SPI
    CS_LOW;

    // MSB firt
    PLIB_SPI_BufferWrite(SPI_ID_1, (address >> 16) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (address >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (address & 0xFF));
    
    // Send data
    PLIB_SPI_BufferWrite(SPI_ID_1, data);

    do {
        SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
    } while (SpiBusy == 1);
   
    CS_HIGH;    
}

void ft812_memory_write16(uint32_t address, uint16_t data)
{
    // Déclarations de variables
    int SpiBusy;
    
    // Algorithme pour l'envoi sur SPI
    CS_LOW;

    // MSB firt
    PLIB_SPI_BufferWrite(SPI_ID_1, (address >> 16) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (address >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (address & 0xFF));
    
    // Send data (litlle-endian)
    PLIB_SPI_BufferWrite(SPI_ID_1, (data & 0xFF));
    PLIB_SPI_BufferWrite(SPI_ID_1, (data >> 8) & 0xFF);
    
    do {
        SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
    } while (SpiBusy == 1);
   
    CS_HIGH;    
}

void ft812_memory_write32(uint32_t address, uint32_t data)
{
    // Déclarations de variables
    int SpiBusy;
    
    // Algorithme pour l'envoi sur SPI
    CS_LOW;

    // MSB firt
    PLIB_SPI_BufferWrite(SPI_ID_1, (address >> 16) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (address >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (address & 0xFF));
    
    // Send data (litlle-endian)
    PLIB_SPI_BufferWrite(SPI_ID_1, (data & 0xFF));
    PLIB_SPI_BufferWrite(SPI_ID_1, (data >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (data >> 16) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (data >> 24) & 0xFF);

    do {
        SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
    } while (SpiBusy == 1);
   
    CS_HIGH;    
}

void ft812_init(void)
{
    // Allume le chip graphique
    PD_HIGH;
    delay_msCt(25);
    
    //--------------------//
    //  Host command
    //--------------------//
    ft812_send_host_command(HC_CLKINT, HCP_PARAM_EMPTY);
    delay_msCt(1);
    ft812_send_host_command(HC_RST_PULSE, HCP_PARAM_EMPTY);
    delay_msCt(5);
    ft812_send_host_command(HC_MODE_ACTIVE, HCP_PARAM_EMPTY);
    delay_msCt(20);
    
    //--------------------//
    //  Registres LCD
    //--------------------//
    
    // Horizontal Timing
    ft812_memory_write16(REG_HSIZE, LCD_HSIZE);
    ft812_memory_write16(REG_HCYCLE, LCD_HCYCLE);
    ft812_memory_write16(REG_HOFFSET, LCD_HOFFSET);
    ft812_memory_write16(REG_HSYNC0, LCD_HSYNC0);
    ft812_memory_write16(REG_HSYNC1, LCD_HSYNC1);
    
    // Vertical Timing
    ft812_memory_write16(REG_VSIZE, LCD_VSIZE);
    ft812_memory_write16(REG_VCYCLE, LCD_VCYCLE);
    ft812_memory_write16(REG_VOFFSET, LCD_VOFFSET);
    ft812_memory_write16(REG_VSYNC0, LCD_VSYNC0);
    ft812_memory_write16(REG_VSYNC1, LCD_VSYNC1);
    
    // Clock Setting
    ft812_memory_write8(REG_PCLK, 0); // (REG_PCLK, LCD_PCLK)
    ft812_memory_write8(REG_SWIZZLE, LCD_SWIZZLE);
    ft812_memory_write8(REG_PCLK_POL, LCD_PCLK_POL);
    ft812_memory_write8(REG_CSPREAD, LCD_CSPREAD);
    ft812_memory_write8(REG_DITHER, LCD_DITHER);
    
    //++
    /*
    ft812_memory_write8(0x302090, 0x80);   // GPIO_DIR
    ft812_memory_write8(0x302094, 0x80);   // GPIO
    ft812_memory_write8(0x302054, 2);      // DLSWAP_FRAME
    ft812_memory_write8(0x302070, LCD_PCLK);   // PCLK en dernier
    */
}

uint8_t ft812_memory_read8(uint32_t address)
{
    // Déclarations de variables
    int SpiBusy;
    uint8_t readData;
    
    // Vider les octets RX parasites adresse
    while (!PLIB_SPI_ReceiverFIFOIsEmpty(SPI_ID_1))
    {
        uint8_t dump = PLIB_SPI_BufferRead(SPI_ID_1);
        (void)dump;
    }
    
    // Algorithme pour l'envoi sur SPI
    CS_LOW;

    // MSB firt | Envoie adresse à lire
    PLIB_SPI_BufferWrite(SPI_ID_1, (address >> 16) & 0x3F);
    PLIB_SPI_BufferWrite(SPI_ID_1, (address >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (address & 0xFF));
    
    // Envoie octet dummy pour lecture
    PLIB_SPI_BufferWrite(SPI_ID_1, MEM_READ_DUMMY_BYTE);
    
    // Attend fin envoie
    while(PLIB_SPI_IsBusy(SPI_ID_1));
    
    //Vider les octets RX parasites adresse
    while (!PLIB_SPI_ReceiverFIFOIsEmpty(SPI_ID_1))
    {
        uint8_t dump = PLIB_SPI_BufferRead(SPI_ID_1);
        (void)dump;
    }
    
    // Lécture data -----
    
    // Envoie octet dummy pour gen. d'une clock sur le SPI
    PLIB_SPI_BufferWrite(SPI_ID_1, MEM_READ_DUMMY_BYTE);
    
    // Attend fin envoie
    while(PLIB_SPI_IsBusy(SPI_ID_1));
    
    // Attend arrivée dans fifo
    //while (PLIB_SPI_ReceiverFIFOIsEmpty(SPI_ID_1));
    readData = PLIB_SPI_BufferRead(SPI_ID_1);  
    
    CS_HIGH;
    
    return readData;
}