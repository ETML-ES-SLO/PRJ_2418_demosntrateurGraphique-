#ifndef Mc32GestSpiLM70_H
#define Mc32GestSpiLM70_H
/*--------------------------------------------------------*/
/* Mc32GestSpiLM70.h
/*--------------------------------------------------------*/
/*	Description :	Gestion par SPI du capteur temperature LM70 du Kit
/*
/*	Auteur 		: 	C. Huber
/*	Version		:	V1.1    09.05.2014
/*	Compilateur	:	XC32 V1.31
//
/*--------------------------------------------------------*/



#include "Type_Def32.h"


// prototypes des fonctions
void SPI_InitLM70(void);
sint16 SPI_ReadRawTempLM70(void);
// Passage par référence car problème avec return lors affectation
// a une variable globale dans réponse à interruption
void LM70_ConvRawToDeg( sint16 RowTemp, float *pTemp);

#endif
