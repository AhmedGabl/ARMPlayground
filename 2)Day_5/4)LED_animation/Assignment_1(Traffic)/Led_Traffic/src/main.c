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
	  for(volatile u32 i=0; i<200000u; i++);
	}


void Count_sec(u8 i,u8 i2,u8 time);
void traffic(void);


int main(void)
{

	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

	GPIO_voidSetPinMode(GPIO_PORTA, 9, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 10, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 11, GPIO_PIN_MODE_GP_PP_10MHZ);

	for(volatile u8 i=0 ; i < 4;i++)
		{
			GPIO_voidSetPinMode(GPIO_PORTA, 1+i, GPIO_PIN_MODE_GP_PP_10MHZ);
			GPIO_voidSetPinMode(GPIO_PORTA, 5+i, GPIO_PIN_MODE_GP_PP_10MHZ);
		}

		traffic();

	return 0;
}

void traffic(void){

	while(1){
			//green
			GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
			Count_sec(1,5,10);
			GPIO_voidSetPinValue(GPIO_PORTA ,9 ,GPIO_LOW);
			//yellow
			GPIO_voidSetPinValue(GPIO_PORTA, 10, GPIO_HIGH);
			Count_sec(1,5,3);
			GPIO_voidSetPinValue(GPIO_PORTA ,10 ,GPIO_LOW);
			//red
			GPIO_voidSetPinValue(GPIO_PORTA, 11, GPIO_HIGH);
			Count_sec(1,5,10);
			GPIO_voidSetPinValue(GPIO_PORTA ,11 ,GPIO_LOW);
}
}



void Count_sec(u8 i,u8 i2,u8 time)
{
	if(time ==10)
	{
	//10
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	//dirty_delay();

	GPIO_voidSetPinValue(GPIO_PORTA, i2, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i2+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i2+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i2+3, GPIO_LOW);
	dirty_delay();
	GPIO_voidSetPinValue(GPIO_PORTA, i2, GPIO_LOW);

	//9
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_HIGH);
	dirty_delay();
	//8
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_HIGH);
	dirty_delay();
	//7
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//6
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//5
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//4
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//3
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//2
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//1
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();
	//0
	GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
	dirty_delay();

	}

	else if(time==3)
	{
		//3
		GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
		GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_HIGH);
		GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
		dirty_delay();
		//2
		GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_HIGH);
		GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
		dirty_delay();
		//1
		GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_HIGH);
		GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
		dirty_delay();
		//0
		GPIO_voidSetPinValue(GPIO_PORTA, i, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_PORTA, i+1, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_PORTA, i+2, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_PORTA, i+3, GPIO_LOW);
		dirty_delay();
	}
}
