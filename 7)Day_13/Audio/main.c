/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"

//#include "OS_interface.h"

#include "Experience.h"

void SendAudio(void){
	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
	static u16 x = 0;
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, Experience_raw[x++]);

	if(x == Experience_raw_len)
		x=0;

	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);
}

int main(void)
{

	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

	for(u8 i=0; i<8; i++){
		GPIO_voidSetPinMode(GPIO_PORTA, i, GPIO_PIN_MODE_GP_PP_10MHZ);
	}

	GPIO_voidSetPinMode(GPIO_PORTA, 8, GPIO_PIN_MODE_GP_PP_10MHZ);

//	OS_voidCreateTask(0, 100, 0, SendAudio);
//	OS_voidStartScheduler();

	STK_voidSetPeriodicInterval(100, SendAudio);


//	OS_voidCreateTask(0, 1, 5, LED_TOG0);
//	OS_voidCreateTask(1, 2, 1, LED_TOG1);
//	OS_voidCreateTask(2, 4, 3, LED_TOG2);
//
//	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
//	OS_voidStartScheduler();

	while(1);

	return 0;
}

