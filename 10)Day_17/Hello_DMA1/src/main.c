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

u32 arr1[1000];
u32 arr2[1000];


void DMA1_Channel1_IRQHandler(){
//	if(!(GPIO_u8GetPinValue(GPIO_PORTA,1)))
	GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_HIGH);
//	DMA_ChannelDisable(0);
	DMA_voidReset_CCR(0);
	DMA_voidReset_CNDTR(0);
	DMA->IFCR = 0x1;
}

void main()
{
	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	RCC_voidPeripheralClockEnable(RCC_AHB,DMA1);
	GPIO_voidSetPinMode(GPIO_PORTA,0,GPIO_PIN_MODE_GP_PP_2MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA,1,GPIO_PIN_MODE_GP_PP_2MHZ);


	for(volatile u16 i=0; i<1000 ;i++)
		arr1[i]=i;


	DMA_voidChannel_Set_Addresses(0,arr1,arr2,1000);
	DMA_voidM2M(0,11);

	GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_LOW);
	DMA_voidChannelEnable(0);


	GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);
	for(volatile u32 i=0;i<1000;i++)
		arr2[i]=arr1[i];
	GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_HIGH);

	//if(arr2[10]==10)
	//		GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_HIGH);

//if(arr2[10]==10)//!(GPIO_u8GetPinValue(GPIO_PORTA,0)))
//		GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_HIGH);

while(1){

}

}











