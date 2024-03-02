/*
 * DMA_program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"
#include "USART_interface.h"

#define USART1->S

void DMA_voidUSART1(u8 channel_number,u8 DMAx_Channelx_IRQn){

	DMA->channel[channel_number].CCR |= 0x000010B2;
	// NVIC setup

	NVIC_voidSetPriority(DMAx_Channelx_IRQn,0,0);
	NVIC_voidEnableInterrupt(DMAx_Channelx_IRQn);
//	NVIC_SetPriority(DMA1_Channel1_IRQn, 0);
	//NVIC_EnableIRQ(DMA1_Channel1_IRQn);
}


void DMA_voidReset_CCR(u8 channel_number){
	DMA->channel[channel_number].CCR    &= ~0x7FFF;
}
void DMA_voidReset_CNDTR(u8 channel_number){
	DMA->channel[channel_number].CNDTR  &= ~0xFFFF;
}

/*
 * @brief   DMA Channel set addresses function
 * @note    Sets the addresses of the memory and peripheral ports,
 *          and number of data items to be transfered in a specific channel
 * @param   DMA_Channel, Peripheral_Adr, Memory_Adr, size
 * @retval  None
 */
void DMA_voidChannel_Set_Addresses(u8 channel_number, const u32 * Peripheral_Adr, u32 * Memory_Adr, const u32 size)
{
    /* Set address for peripheral */
	DMA->channel[channel_number].CPAR   = (u32)Peripheral_Adr;

    /* Set address for memory */
	DMA->channel[channel_number].CMAR   = (u32)Memory_Adr;

    /* Set no. of data to transfer */
	DMA->channel[channel_number].CNDTR  = size;
}

/**
 * @brief   Enable DMA
 * @note
 * @param   DMAx_Channely   where: x= 1 or 2 , y= 1 ..7 for DMA1 and 1 ..5 for DMA2
 * @retval  None
 */

void DMA_voidChannelEnable(u8 channel_number)//DMA_Channel_TypeDef *DMA_Channel,uint8_t DMA_Num, uint8_t Ch_Num)
{
  //Clears the GIF, TEIF, HTIF and TCIF flags in the DMA_ISR register */
	//if(DMA_Num == 1)
		DMA->IFCR |= (1 << (4*(channel_number)) );
//	else DMA2->IFCR |= (1 << (4*(Ch_Num-1)) );
 // Channel enable
		SET_BIT(DMA->channel[channel_number].CCR,0);
//	 |=  DMA_CCR1_EN;
}


/**
 * @brief   Disable DMA
 * @note
 * @param   DMAx_Channely   where: x= 1 or 2 , y= 1 ..7 for DMA1 and 1 ..5 for DMA2
 * @retval  None
 */
void DMA_ChannelDisable(u8 channel_number){
	CLR_BIT(DMA->channel[channel_number].CCR,0);
//  DMA_Channel->CCR &= ~DMA_CCR1_EN;
}

void DMA_voidClearIFCR_chx(u8 channel_number){
	DMA->IFCR |= (1 << (4*(channel_number)) );
}
