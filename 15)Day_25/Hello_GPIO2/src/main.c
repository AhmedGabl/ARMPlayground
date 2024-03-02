/*
 * ma;in.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"

int main(void)
{

	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

	GPIO_voidSetPinMode(GPIO_PORTA, 2, GPIO_PIN_MODE_GP_PP_10MHZ);

	GPIO_voidSetPinValue(GPIO_PORTA,2,GPIO_HIGH);

	while(1){}
	return 0;
}
