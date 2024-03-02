/*
 * main.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"


void dirty_delay (void);
void Seven_Segment_Counter(u8 i);

int main(void)
{

	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
//takes the start pin in port A
	Seven_Segment_Counter(1);
	return 0;
}


void dirty_delay (void)
	{
	  for(volatile u32 i=0; i<100000u; i++);
	}


// function to count from 0-9 in a 7 segment display BCD
void Seven_Segment_Counter(u8 i)
{
	for(volatile u8 j=i ;j < i+4;j++)
	{
		GPIO_voidSetPinMode(GPIO_PORTA, j, GPIO_PIN_MODE_GP_PP_10MHZ);
	}

	while(1)
	{
	//0
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//1
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//2
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//3
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//4
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//5
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//6
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//7
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//8
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_HIGH);
	dirty_delay();
	//9
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_HIGH);
	dirty_delay();
	}
}
