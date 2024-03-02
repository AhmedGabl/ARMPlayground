/*
 * main.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"


void dirty_delay (void){
	  for(volatile u32 i=0; i<500000u; i++);
	}


int main(void)
{

	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	GPIO_voidSetPinMode(GPIO_PORTA, 1, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinValue(GPIO_PORTA, 1, GPIO_HIGH);

	dirty_delay();
	GPIO_voidSetPinValue(GPIO_PORTA ,1 ,GPIO_LOW);

	return 0;
}
