/*
 * DMA_private.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_



#define DMA_BASE_ADDRESS  0x40020000
//#define DMA2_BASE_ADDRESS  0x40020400



typedef struct{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 RES;
}DMA_channel_t;

typedef struct{
		volatile u32 ISR;
		volatile u32 IFCR;

		volatile DMA_channel_t channel[7];

}DMA_REG_t;


#define DMA	((volatile DMA_REG_t*)DMA_BASE_ADDRESS)
//#define DMA2	((volatile DMA_REG_t*)DMA2_BASE_ADDRESS)//for hight density devices


#endif /* DMA_PRIVATE_H_ */
