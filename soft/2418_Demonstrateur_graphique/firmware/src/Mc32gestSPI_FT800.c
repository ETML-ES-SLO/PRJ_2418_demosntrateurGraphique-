// Mc32gestSpiDac.C
// Gestion master SPI avec slave DAC


#include "Mc32Delays.h"
#include "Mc32gestSpiFT800.h"
#include "Mc32SpiUtil.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"

// Initialisation de la communication SPI et du FT800
// ------------------------------------------------
unsigned short cmd_offset = 0;
unsigned short dl_offset = 0;

void InitFT800(void) {
    int i = 0;
    // Pulse pour le démmarage
    delay_msCt(20);
    PD_TFTOff();
    delay_msCt(20);
    PD_TFTOn();
    delay_msCt(20);

    // Première commandes nécéssaires à l'initialisation
    //    HostCommand(CLKEXT); pour EVE1
    //    HostCommand(CLK48M); pour EVE1

    HostCommand(0x68);
    HostCommand(0x00);
    delay_msCt(300);

    while (rd8(REG_ID) != 0x7C);
    while (rd16(REG_CPURESET) != 0x00);

    // Configure display registers - demonstration for WQVGA resolution
    wr16(REG_HCYCLE, 928); // number if horizontal cycles for display
    wr16(REG_HOFFSET, 88); // horizontal offset from starting signal
    wr16(REG_HSYNC0, 0); // hsync falls
    wr16(REG_HSYNC1, 48); // hsync rise
    wr16(REG_VCYCLE, 525); // number of vertical cycles for display
    wr16(REG_VOFFSET, 32); // vertical offset from start signal
    wr16(REG_VSYNC0, 0); // vsync falls
    wr16(REG_VSYNC1, 3); // vsync rise
    wr8(REG_SWIZZLE, 0); // output swizzle, Inverse R et B
    wr8(REG_PCLK_POL, 0); // Règle la polarité du clock
    wr8(REG_CSPREAD, 0); // output clock spread enable
    wr16(REG_HSIZE, 800); // width resolution
    wr16(REG_VSIZE, 480); // height resolution
    wr8(REG_DITHER, 1); // output number of bits

    // Nettoie l'écran et le met en rouge

    wr32(RAM_DL + 0, CLEAR_COLOR_RGB(255, 0, 0));
    wr32(RAM_DL + 4, CLEAR(1, 1, 1));
    int offset = 8;
    for (i = 0; i < 16; i++) {
        wr32(RAM_DL + offset, BITMAP_HANDLE(i));
        offset += 4;
        wr32(RAM_DL + offset, BITMAP_LAYOUT_H(0, 0));
        offset += 4;
        wr32(RAM_DL + offset, BITMAP_SIZE_H(0, 0));
        offset += 4;
    }

    wr32(RAM_DL + offset, DISPLAY());
    wr8(REG_DLSWAP, DLSWAP_FRAME);

    wr8(REG_GPIO_DIR, 0x80); // Met GPIO7 en sortie
    wr8(REG_GPIO, 0x80); // allume le backlight (met GPIO7 à 1)

    wr8(REG_PCLK, 2); // Après cette instruction, l'écran s'allume
    wr32(RAM_DL + 0, CLEAR_COLOR_RGB(255, 0, 0));
    wr32(RAM_DL + 4, CLEAR(1, 1, 1));
    wr32(RAM_DL + 8, DISPLAY());
    wr8(REG_DLSWAP, DLSWAP_FRAME);
}

void HostCommand(uint8_t command) {
    SPI_CS_TFTStateSet(0);

    tr8(command);
    tr8(0);
    tr8(0);

    SPI_CS_TFTStateSet(1);
}

void wr8(uint32_t addr, uint8_t value) {
    SPI_CS_TFTStateSet(0);

    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);
    tr8(value);

    SPI_CS_TFTStateSet(1);
}

void wr16(uint32_t addr, uint16_t value) {
    SPI_CS_TFTStateSet(0);

    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);
    tr16(value);

    SPI_CS_TFTStateSet(1);
}

void wr32(uint32_t addr, uint32_t value) {
    SPI_CS_TFTStateSet(0);

    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);
    tr32(value);

    SPI_CS_TFTStateSet(1);
}

uint8_t wr8s(uint32_t addr, const char *S) {
    int l, i;
    SPI_CS_TFTStateSet(0);

    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);

    l = strlen((const char *) S);
    for (i = 0; i <= l; i++) {
        tr8(S[i]);
    }
    for (; i % 4 > 0; i++) {
        tr8(0);
    }

    SPI_CS_TFTStateSet(1);
    return i;
}

uint8_t rd8(uint32_t addr) {
    SPI_CS_TFTStateSet(0);

    tr8(addr >> 16 & 0x3F);
    tr8(addr >> 8);
    tr8(addr);
    tr8(0); // dummy byte

    uint8_t LSB = spi_read1(0);

    SPI_CS_TFTStateSet(1);
    return LSB;
}

uint16_t rd16(uint32_t addr) {
    SPI_CS_TFTStateSet(0);

    tr8(addr >> 16 & 0x3F);
    tr8(addr >> 8);
    tr8(addr);
    tr8(0); // dummy byte
    uint8_t LSB = spi_read1(0);
    uint8_t MSB = spi_read1(0);
    SPI_CS_TFTStateSet(1);
    return (MSB << 8) | LSB;
}

uint32_t rd32(uint32_t addr) {
    SPI_CS_TFTStateSet(0);
    tr8(addr >> 16 & 0x3F);
    tr8(addr >> 8);
    tr8(addr);
    tr8(0); // dummy byte
    uint8_t Byte0 = spi_read1(0);
    uint8_t Byte1 = spi_read1(0);
    uint8_t Byte2 = spi_read1(0);
    uint8_t Byte3 = spi_read1(0);
    SPI_CS_TFTStateSet(1);
    return (Byte0 << 24) | (Byte1 << 16) | (Byte2 << 8) | Byte3;
}

void cmd(uint32_t command) {
    wr32(RAM_CMD + cmd_offset, command);
    cmd_incrementn(4);
}

void dl(uint32_t instruction) {
    wr32(RAM_DL + dl_offset, instruction);
    dl_incrementn(4);
}

void dl_incrementn(unsigned char n) {
    dl_offset = (dl_offset + n) % 4096;
}

void cmd_incrementn(unsigned char n) {
    cmd_offset = (cmd_offset + n) % 4096;
}
