/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "OS_interface.h"

// functions to count from 0-9 in a 7 segment display BCD

void seg_0(void);
void seg_1(void);
void seg_2(void);
void seg_3(void);
void seg_4(void);
void seg_5(void);
void seg_6(void);
void seg_7(void);
void seg_8(void);
void seg_9(void);

u16 SevSeg[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

 u8 temp = 20 ;

 void counter(void){
	 if(temp == 0)
		 temp=20;

	 	 temp--;

 }

void s_seg_1(void){
	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);
	switch (temp%10){
	case 0:
	seg_0();
	break;
	case 1:
	seg_1();
	break;
	case 2:
		seg_2();
	break;
	case 3:
		seg_3();
	break;
	case 4:
		seg_4();
	break;
	case 5:
		seg_5();
	break;
	case 6:
		seg_6();
	break;
	case 7:
		seg_7();
	break;
	case 8:
		seg_8();
	break;
	case 9:
		seg_9();
	break;
	}
	//  GPIO_voidSetPinValue(GPIO_PORTA, 10, GPIO_HIGH);
}

void s_seg_2(void){
    GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_LOW);
	switch ((temp/10)){
	case 0:
		seg_0();
		break;
	case 1:
	seg_1();
	break;
	case 2:
		seg_2();
	break;
	case 3:
		seg_3();
	break;
	case 4:
		seg_4();
	break;
	case 5:
		seg_5();
	break;
	case 6:
		seg_6();
	break;
	case 7:
		seg_7();
	break;
	case 8:
		seg_8();
	break;
	case 9:
		seg_9();
	break;
	}
	//GPIO_voidSetPinValue(GPIO_PORTA, 11, GPIO_HIGH);
}


int main(void)
{
	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

	for(volatile u8 i=0 ; i < 10 ; i++){
	GPIO_voidSetPinMode(GPIO_PORTA, i, GPIO_PIN_MODE_GP_PP_10MHZ);
	}

	OS_voidCreateTask(0, 2,0, s_seg_1);
	OS_voidCreateTask(1, 2,1, s_seg_2);
	OS_voidCreateTask(2, 1000,1000, counter);


	OS_voidStartScheduler();

	while(1){

	}

	return 0;
}

void seg_0(void){
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[0]);
}

void seg_1(void){
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[1]);
}
void seg_2(void){
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[2]);
}
void seg_3(void){
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[3]);
}
void seg_4(void){
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[4]);
}
void seg_5(void){
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[5]);
}
void seg_6(void){
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[6]);
}

void seg_7(void){
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[7]);
}
void seg_8(void){
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[8]);
}

void seg_9(void){
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[9]);
}
