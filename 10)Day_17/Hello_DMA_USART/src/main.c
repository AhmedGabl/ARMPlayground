/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"

#include "DMA_interface.h"

#include "USART_interface.h"
#include "USART_private.h"

u8 arr1[]="Hello from STM32 \r\n";

void dirty_delay (void)
	{
	  for(volatile u32 j=0; j<5000000u; j++);
	}

void DMA1_Channel4_IRQHandler(){
	dirty_delay();
DMA_voidClearIFCR_chx(3);
//if(!(GPIO_u8GetPinValue(GPIO_PORTA,1)))
//	GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_HIGH);
//	DMA_ChannelDisable(0);
//	DMA_voidReset_CCR(0);
//	DMA_voidReset_CNDTR(0);
//	DMA_voidClearIFCR_chx(0);
}

void main()
{
	//for(volatile u16 i=0; i<120 ;i++)
	//	arr1[i]=i;

	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	RCC_voidPeripheralClockEnable(RCC_AHB,DMA1);

	USART_init();
	//NVIC_voidEnableInterrupt(14);
	//transferring data using DMA

	DMA_voidChannel_Set_Addresses(3,&(USART1->DR),arr1,19);

	DMA_voidUSART1(3,14);

	//activitae channel
	DMA_voidChannelEnable(3);


while(1){

}

}











