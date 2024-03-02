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


u16 SevSeg[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
//u16 SevSeg[9] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01101111};

u8 temp = 20 ;

 void counter(void){

	 if(temp == 0){
		 temp=20;}
	 	 temp--;
 }
 void dirty_delay (void)
 	{
 	  for(volatile u32 j=0; j<1000000u; j++);
 	}
//data  0 shiftclk 1  //latch2
void s_seg(void){
	S_sendData(GPIO_PORTA,0,3,1,2,SevSeg[temp%10],SevSeg[temp/10]);
}

int main(void)
{
	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

	for( u8 i=0 ; i < 4 ; i++){
	GPIO_voidSetPinMode(GPIO_PORTA, i, GPIO_PIN_MODE_GP_PP_10MHZ);
	}

	//OS_voidCreateTask(0, 2,0, s_seg_1);
	//OS_voidCreateTask(1, 2,1, s_seg_2);
	//OS_voidCreateTask(2, 1000,1000, counter);
	//OS_voidStartScheduler();

	while(1){
		s_seg();
		dirty_delay();
		counter();
	}
	return 0;
}
