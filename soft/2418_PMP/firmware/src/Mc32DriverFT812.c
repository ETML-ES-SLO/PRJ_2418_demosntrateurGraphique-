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

void ft812_memory_write8(uint32_t address, uint8_t data)
{
    CS_LOW();
    
    int SpiBusy;

    // MSB firt
    PLIB_SPI_BufferWrite(SPI_ID_1, 
            ((address >> 16) & 0xFF) + MEM_WRITE_BEGINNING);
    
    PLIB_SPI_BufferWrite(SPI_ID_1, (address >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (address & 0xFF));
    
    // Send data
    PLIB_SPI_BufferWrite(SPI_ID_1, data);

    do {
        SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
    } while (SpiBusy == 1);
   
    CS_HIGH();    
}

void ft812_memory_write16(uint32_t address, uint16_t data)
{
    CS_LOW();
    
    int SpiBusy;

    // MSB firt
    PLIB_SPI_BufferWrite(SPI_ID_1, 
            ((address >> 16) & 0xFF) + MEM_WRITE_BEGINNING);
    
    PLIB_SPI_BufferWrite(SPI_ID_1, (address >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (address & 0xFF));
    
    // Send data
    PLIB_SPI_BufferWrite(SPI_ID_1, (data >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (data & 0xFF));

    do {
        SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
    } while (SpiBusy == 1);
   
    CS_HIGH();    
}

void ft812_memory_write32(uint32_t address, uint32_t data)
{
    CS_LOW();
    
    int SpiBusy;

    // MSB firt
    PLIB_SPI_BufferWrite(SPI_ID_1, 
            ((address >> 16) & 0xFF) + MEM_WRITE_BEGINNING);
    
    PLIB_SPI_BufferWrite(SPI_ID_1, (address >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (address & 0xFF));
    
    // Send data
    PLIB_SPI_BufferWrite(SPI_ID_1, (data >> 24) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (data >> 16) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (data >> 8) & 0xFF);
    PLIB_SPI_BufferWrite(SPI_ID_1, (data & 0xFF));

    do {
        SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
    } while (SpiBusy == 1);
   
    CS_HIGH();    
}

void ft812_init(void)
{
    //--------------------//
    //  Host command
    //--------------------//
    ft812_send_host_command(HC_CLKINT, HCP_PARAM_EMPTY);
    delay_msCt(1);
    ft812_send_host_command(HC_RST_PULSE, HCP_PARAM_EMPTY);
    delay_msCt(1);
    ft812_send_host_command(HC_MODE_ACTIVE, HCP_PARAM_EMPTY);
    delay_msCt(20);
    
    //--------------------//
    //  Registres LCD
    //--------------------//
    
    // Horizontal Timing
    ft812_memory_write16(REG_HSIZE, 800);   // Largeur visible en pixel
    ft812_memory_write16(REG_HCYCLE, 928);  // Largeur total en pixel
    ft812_memory_write16(REG_HOFFSET, 88);  // Début zone visible en pixel
    ft812_memory_write16(REG_HSYNC0, 0);    // Début HSYNC
    ft812_memory_write16(REG_HSYNC1, 48);   // Fin HSYNC
    
    // Vertical Timing
    ft812_memory_write16(REG_VSIZE, 480);   // Hauteur visible en pixel
    ft812_memory_write16(REG_VCYCLE, 525);  // Hauteur total en pixel
    ft812_memory_write16(REG_VOFFSET, 32);  // Début zone visible en pixel
    ft812_memory_write16(REG_VSYNC0, 0);    // Début VSYNC
    ft812_memory_write16(REG_VSYNC1, 3);    // Fin VSYNC
    
    // Clock Setting
    ft812_memory_write8(REG_PCLK, 2);
    ft812_memory_write8(REG_SWIZZLE, 0);    // Mapping RBG standard
    ft812_memory_write8(REG_PCLK_POL, 0);   // Polarité pixel clock
    ft812_memory_write8(REG_CSPREAD, 0);    // Désactive le clock spreading
    ft812_memory_write8(REG_DITHER, 1);     // Active le dithering couleur
}

void ft812_init_with_basic_display(void)
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
