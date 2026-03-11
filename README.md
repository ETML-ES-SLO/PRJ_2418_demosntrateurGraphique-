# 2418 Demonstrateur graphique
## Objectif

Développer une librairie complète pour pouvoir piloter l'écran **NHD-5.0R-FT812** avec le kit PIC32 de MINF.

## Versioning

**IDE**			: MPLABX IDE v6.15
**Configurateur**	: Harmony v2.06
**Compilateur**		: XC32 v2.50
**OS**			: Windows 10

## Mise en place d'une librairie (Mc32DriverFT812)
### Adresses F812

Toutes les adresses de la FT812 proviennent du datasse **DS_FT81x** de **Bridgetek**.

| Nom du registre   | Adresse       | Description                           |
| ----------------- | ------------- |:-------------------------------------:|
| REG_HSIZE         | 0x302034      | Horizontal display pixel count        |
| REG_VSIZE         | 0x302048      | Vertical display line count           |
| REG_HCYCLE        | 0x30202C      | Horizontal total cycle count          |
| REG_HOFFSET       | 0x302030      | Horizontal display start offset       |
| REG_HSYNC0        | 0x302038      | Horizontal sync fall offset           |
| REG_HSYNC1        | 0x30203C      | Horizontal sync rise offset           |
| REG_VCYCLE        | 0x302040      | Vertical total cycle count            |
| REG_VOFFSET       | 0x302044      | Vertical display start offset         |
| REG_VSYNC0        | 0x30204C      | Vertical sync fall offset             |
| REG_VSYNC1        | 0x302050      | Vertical sync rise offset             |
| REG_PCLK          | 0x302070      | PCLK frequency divider, 0 = disable   |
| REG_DLSWAP        | 0x302054      | Display list swap control             |
| RAM_DL            | 0x300000      | Display List RAM                      |