#ifndef Mc32GestSpiDac_H
#define Mc32GestSpiDac_H
/*--------------------------------------------------------*/
/* Mc32GestSpiDac.h
/*--------------------------------------------------------*/
/*	Description :	Gestion DAC Spi du Kit (LTC2604)
/*
/*	Auteur 		: 	C. Huber
/*	Version		:	V1.0
/*	Compilateur	:	XC32 V1.31
//
/*--------------------------------------------------------*/



#include "Type_Def32.h"


// prototypes des fonctions
void InitLTC2604(void);
void SPI_WriteToDac(uint8 Noch, uint16 DacVal);


#endif
