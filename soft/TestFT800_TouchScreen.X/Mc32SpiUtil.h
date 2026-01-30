#ifndef Mc32SpiUtil_H
#define Mc32SpiUtil_H
/*--------------------------------------------------------*/
/* Mc32SpiUtil.h
/*--------------------------------------------------------*/
/*	Description :	Utilitaire gestion SPI CCS like
/*
/*	Auteur 		: 	C. Huber
/*	Version		:	V1.0
/*	Compilateur	:	XC32 V1.31
//
/*--------------------------------------------------------*/



#include "Type_Def32.h"


// prototypes des fonctions
void spi_write1( uint8 Val);
void spi_write2( uint8 Val);
uint8 spi_read1( uint8 Val);
uint8 spi_read2( uint8 Val);

#endif
