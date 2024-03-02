/*
 * DMA_interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_



//void DMA_voidInit(u32 arr1[] ,u32 arr2[]);
void DMA_voidM2M(u8 channel_number,u8 DMAx_Channelx_IRQn);


void DMA_voidChannel_Set_Addresses(u8 channel_number, const u32 * Peripheral_Adr, u32 * Memory_Adr, const u32 size);


void DMA_voidChannelEnable(u8 channel_number);

void DMA_ChannelDisable(u8 channel_number);

void DMA_voidReset_CCR(u8 channel_number);

void DMA_voidReset_CNDTR(u8 channel_number);



#endif /* DMA_INTERFACE_H_ */
