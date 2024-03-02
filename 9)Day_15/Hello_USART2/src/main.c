/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "EXTI_interface.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void dirty_delay (void)
	{
	  for(volatile u32 i=0; i<500000u; i++);
	}

u8 temp,len,len2 ;
char string[] = "==>Hello from stm32     \n";
char string2[] = "==>Echo from stm32     \n";

//interrupt recieve
void USART1_IRQHandler(void){
	if( USART1_SR_RXNE == 1){
		for(u8 counter=0 ;counter<len2;counter++){
			USART1_send( string2[counter]);
		}
		temp = USART1->DR;
	}
}

void main()
{
	len = strlen(string);
	len2 = strlen(string2);

	USART_init();
    USART_initRXInterupt();
//	NVIC_EnableIRQ(USART1_IRQn);

	while(1){

			for(u8 counter =0 ; counter< len ; counter++)
			{
				USART1_send(string[counter]);

			}
dirty_delay();
/*               //polling recieve
			if(USART1_received()=='1')
			{
			for(u8 counter=0 ;counter<len2;counter++)
		     {
			  USART1_send( string2[counter]);
			 }
			}
*/
	}
}











