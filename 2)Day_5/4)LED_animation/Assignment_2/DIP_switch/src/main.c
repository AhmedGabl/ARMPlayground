/*
 * ma;in.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"


void dirty_delay (u8 t){
	  for(volatile u32 i=0; i<t*200000u; i++);
	}


void flash(void);
void shift_left(void);
void Shift_Right(void);
void Leds_Converging(void);
void Leds_Diverging(void);
void Ping_Bong(void);
void Snake_effect(void);
void Leds_Converging_Diverging(void);


int main(void)
{

	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

	u8  temp1=0,temp2=0,temp3=0;

	GPIO_voidSetPinMode(GPIO_PORTA, 1, GPIO_PIN_MODE_PULLING_INPUT);
	GPIO_voidSetPinMode(GPIO_PORTA, 2, GPIO_PIN_MODE_PULLING_INPUT);
	GPIO_voidSetPinMode(GPIO_PORTA, 3, GPIO_PIN_MODE_PULLING_INPUT);

	GPIO_voidSetPinMode(GPIO_PORTA, 4, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 5, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 6, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 7, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 8, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 9, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 10,GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 11,GPIO_PIN_MODE_GP_PP_10MHZ);

	while(1){
	temp1 = GPIO_u8GetPinValue(GPIO_PORTA,1);
	temp2 = GPIO_u8GetPinValue(GPIO_PORTA,2);
	temp3 = GPIO_u8GetPinValue(GPIO_PORTA,3);

	temp1= temp1+ (temp2*2)+(temp3*4);

	if(temp1 == 1){
		flash();
	}else if(temp1 == 2){
		shift_left();
	}else if(temp1 == 3){
		Shift_Right();
	}else if(temp1 == 4){
		Leds_Converging();
	}else if(temp1 == 5){
		Leds_Diverging();
	}else if(temp1 == 6){
		Ping_Bong();
	}else if(temp1 == 7){
		Snake_effect();
	}else if(temp1 == 8){
		Leds_Converging_Diverging();
	}

	}
	return 0;
}



void flash(void){
//	while(1)
	{
GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_HIGH);
GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_HIGH);
GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_HIGH);
GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_HIGH);
GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_HIGH);
GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_HIGH);
dirty_delay(1);

GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_LOW);
GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_LOW);
GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_LOW);
GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_LOW);
GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);
GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_LOW);
GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_LOW);
GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_LOW);
dirty_delay(1);
	}
	}

void shift_left(void){
//	while(1)
	{
	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_LOW);
	//dirty_delay(1);
		}
	}

void Shift_Right(void){
	//while(1)
	{
	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_LOW);

	}
	}

void Leds_Converging(void){
	//while(1)
	{

	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);
		}
	}

void Leds_Diverging(void){
	//while(1)
	{

	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_LOW);

    GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_LOW);

		}
	}

void Ping_Bong(void){
	//while(1)
	{
		GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_LOW);

		GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_LOW);

		GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_LOW);

		GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_LOW);

		GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);

		GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_LOW);

		GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_LOW);

		GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_LOW);
//back
		GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_LOW);

		GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_LOW);

		GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_LOW);


		GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);

		GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_LOW);


		GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_LOW);


		GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_LOW);

		GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_HIGH);
		dirty_delay(1);
		GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_LOW);

		}
}

void Snake_effect(void){
	//while(1)
	{

	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_HIGH);
	dirty_delay(1);

	for(volatile u8 i=0;i<8;i++){
			GPIO_voidSetPinValue(GPIO_PORTA, 4+i,GPIO_LOW);
	}

	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
	dirty_delay(1);


	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_HIGH);
	dirty_delay(1);

	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_HIGH);
	dirty_delay(1);

	for(volatile u8 i=0;i<8;i++){
			GPIO_voidSetPinValue(GPIO_PORTA, 4+i,GPIO_LOW);
	}

	}

}

void Leds_Converging_Diverging(void){
	//while(1)
	{

	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 7, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 6, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_LOW);


	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 5, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 10,GPIO_LOW);

	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_HIGH);
	dirty_delay(1);
	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_LOW);
	GPIO_voidSetPinValue(GPIO_PORTA, 11,GPIO_LOW);


	}

}
