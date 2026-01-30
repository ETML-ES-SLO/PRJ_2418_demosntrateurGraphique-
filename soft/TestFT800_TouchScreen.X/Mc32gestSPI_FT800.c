// Mc32gestSpiDac.C
// Gestion master SPI avec slave DAC




#include <plib.h>
#include "Mc32gestSpiDac.h"
#include "SK32MX795F512L_V16.h"
#include "Mc32Delays.h"
#include "Mc32gestSpiFT800.h"
#include "Mc32SpiUtil.h"

// Definitions du bus
// #define SPI_SCL      PORTDbits.RD10  pin 70
// #define SPI_SDI      PORTCbits.RC4   pin 9
// #define SPI_SDO      PORTDbits.RD0   pin 72
// #define CS#          LATBbits.LATB3  pin 22
// #define INT#         LATBbits.LATB2  pin 23
// #define PD#          LATBbits.LATB1  pin 24

// Definition des modes
#define ACTIVE  0x00
#define STANDBY 0x41
#define SLEEP   0x42
#define PWRDOWN 0x50
#define CLKEXT  0x44
#define CLK48M  0x62
#define CLK36M  0x61
#define CORERST 0x68

// Initialisation de la communication SPI et du FT800
// ------------------------------------------------
unsigned short cmd_offset = 0;
void InitFT800(void)
{

   uint32  config = SPI_OPEN_MODE8 | SPI_OPEN_ON | SPI_OPEN_CKE_REV |
                    SPI_OPEN_MSTEN ;

   uint32 ConfigReg;

   uint8 ChipId = 0, scratch8;
   // FT800 < 11MHz
   SpiChnOpen(SPI_CHANNEL1, config, 8);   // 10 MHz

   // Controle la configuration
   ConfigReg = SPI1CON;

   FT800_PD_W = 0;
   delay_ms(20);
   FT800_PD_W = 1;
   delay_ms(20);

   HostCommand(ACTIVE);

   HostCommand(CLKEXT);

   HostCommand(CLK48M);

   // Configure display registers - demonstration for WQVGA resolution
    wr16(REG_HSIZE, 320); // width resolution
    wr16(REG_VSIZE, 240); // height resolution
    wr16(REG_HCYCLE, 408); // number if horizontal cycles for display
    wr16(REG_HSYNC0, 0); // hsync falls
    wr16(REG_HSYNC1, 41); // hsync rise
    wr16(REG_HOFFSET, 70); // horizontal offset from starting signal
    wr16(REG_VCYCLE, 263); // number of vertical cycles for display
    wr16(REG_VSYNC0, 0); // vsync falls
    wr16(REG_VSYNC1, 10); // vsync rise
    wr16(REG_VOFFSET, 13); // vertical offset from start signal
    wr8(REG_CSPREAD, 0); // output clock spread enable
    wr8(REG_DITHER, 0); // output number of bits
    wr16(REG_OUTBITS, 0x01B6); // output bits resolution
    wr8(REG_SWIZZLE, 0x0000); // output swizzle

   wr8(REG_PCLK_POL, 1);

   wr8(REG_ROTATE, 0);

   wr32(RAM_DL+0, CLEAR_COLOR_RGB(255,0,0));
   wr32(RAM_DL+4, CLEAR(1,1,1));
   wr32(RAM_DL+8, DISPLAY());

   wr8(REG_DLSWAP, DLSWAP_FRAME);
   wr8(REG_GPIO_DIR, 0xFC);
   wr8(REG_GPIO, 0xFF);

   wr8(REG_PCLK, 5);

   cmd_wait();

   SpiChnOpen(SPI_CHANNEL1, config, 3);   // 10 MHz

   delay_ms(20);    // Pour laisser le chip s'initialiser 
}

void HostCommand(uint8 command)
{
   FT800_CS_W = 0;

   tr8(command);
   tr8(0);
   tr8(0);

   FT800_CS_W = 1;
}

void wr8(uint32 addr, uint8 value)
{
    FT800_CS_W = 0;

    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);
    tr8(value);

    FT800_CS_W = 1;
}
void wr16(uint32 addr, uint16 value)
{
    FT800_CS_W = 0;

    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);
    tr16(value);

    FT800_CS_W = 1;
}
void wr32(uint32 addr, uint32 value)
{
    FT800_CS_W = 0;

    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);
    tr32(value);
    
    FT800_CS_W = 1;
}
uint8 wr8s(uint32 addr, const uint8 *S)
{
    int l, i;
    FT800_CS_W = 0;

    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);

    l = strlen(S);
    for(i=0;i<=l;i++){
        tr8(S[i]);
    }
    for(;i%4>0;i++){
        tr8(0);
    }

    FT800_CS_W = 1;
    return i;
}
uint8 rd8(uint32 addr)
{
    FT800_CS_W = 0;

    tr8(addr >> 16);
    tr8(addr >> 8);
    tr8(addr);
    tr8(0); // dummy byte

    uint8 LSB = spi_read1(0);

    FT800_CS_W = 1;
    return LSB;
}
uint16 rd16(uint32 addr)
{
    FT800_CS_W = 0;

    tr8(addr >> 16);
    tr8(addr >> 8);
    tr8(addr);
    tr8(0); // dummy byte
    uint8 LSB = spi_read1(0);
    uint8 MSB = spi_read1(0);
    FT800_CS_W = 1;
    return LSB + (MSB << 8);
}

void cmd(uint32 command)
{
    wr32(RAM_CMD + cmd_offset, command);
    cmd_incrementn(4);
}

void cmd_incrementn(unsigned char n)
{
    cmd_offset=(cmd_offset+n)%4096;
}
