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
#include "SHREG_interface.h"
// functions to count from 0-9 in a 7 segment display BCD


u16 SevSeg[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

u8 temp = 9 ;

void dirty_delay (void)
	{
	  for(volatile u32 i=0; i<500000u; i++);
	}

 void counter(void){
	 temp--;
	 if(temp == 0)
		 temp=9;
 }

void s_seg_1(void){
	switch (temp){
	case 0:
		S_sendData(GPIO_PORTA,0,1,2,SevSeg[0]);
	break;
	case 1:
		S_sendData(GPIO_PORTA,0,1,2,SevSeg[1]);
	break;
	case 2:
		S_sendData(GPIO_PORTA,0,1,2,SevSeg[2]);
	break;
	case 3:
		S_sendData(GPIO_PORTA,0,1,2,SevSeg[3]);
	break;
	case 4:
		S_sendData(GPIO_PORTA,0,1,2,SevSeg[4]);
	break;
	case 5:
		S_sendData(GPIO_PORTA,0,1,2,SevSeg[5]);
	break;
	case 6:
		S_sendData(GPIO_PORTA,0,1,2,SevSeg[6]);
	break;
	case 7:
		S_sendData(GPIO_PORTA,0,1,2,SevSeg[7]);
	break;
	case 8:
		S_sendData(GPIO_PORTA,0,1,2,SevSeg[8]);
	break;
	case 9:
		S_sendData(GPIO_PORTA,0,1,2,SevSeg[9]);
	break;
	}
}


int main(void)
{
	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

	for(volatile u8 i=0 ; i < 10 ; i++){
	GPIO_voidSetPinMode(GPIO_PORTA, i, GPIO_PIN_MODE_GP_PP_10MHZ);
	}

//	OS_voidCreateTask(0, 2,0, s_seg_1);
//	OS_voidCreateTask(1, 2,1, s_seg_2);
//	OS_voidCreateTask(1, 1000,1000, counter);
//	OS_voidStartScheduler();

	while(1){
s_seg_1();
dirty_delay();
counter();
	}
	return 0;
}
