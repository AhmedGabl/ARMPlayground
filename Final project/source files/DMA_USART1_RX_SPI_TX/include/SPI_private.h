/*
 * SPI_private.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include "STD_TYPES.h"

#define SPI1_BASE_ADDRESS 0x40013000
#define SPI2_BASE_ADDRESS 0x40003800
#define SPI3_BASE_ADDRESS 0x40003C00

typedef struct{
	volatile u32 CR1	 ;
	volatile u32 CR2	 ;
	volatile u32 SR	     ;
	volatile u32 DR	     ;
	volatile u32 CRCPR	 ;
	volatile u32 RXCRCR	 ;
	volatile u32 TXCRCR	 ;
	volatile u32 I2SCFGR ;
	volatile u32 I2SPR	 ;
}SPI_REG_t;

#define SPI_1		((volatile SPI_REG_t*)(SPI1_BASE_ADDRESS))
#define SPI_2		((volatile SPI_REG_t*)(SPI2_BASE_ADDRESS))
#define SPI_3		((volatile SPI_REG_t*)(SPI3_BASE_ADDRESS))


#endif /* SPI_PRIVATE_H_ */
