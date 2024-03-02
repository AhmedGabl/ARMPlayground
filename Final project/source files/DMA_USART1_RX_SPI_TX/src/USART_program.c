/*
 * USART_program.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Ahmed Abogabl
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"

void USART1_init(void)
{
	RCC_voidInit();

	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	RCC_voidPeripheralClockEnable(RCC_APB2,USART_1);

	GPIO_voidSetPinMode(GPIO_PORTA,9,GPIO_PIN_MODE_AF_PP_2MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA,10,GPIO_PIN_MODE_FLOATING_INPUT);

	USART1->BRR = USART_BAUDRATE;
	SET_BIT(USART1->CR1,USART_CR1_RE);
	SET_BIT(USART1->CR1,USART_CR1_TE);
	SET_BIT(USART1->CR1,USART_CR1_UE);

	   CLR_BIT(USART1->SR ,6);
}

void USART1_void_Tx_DMAEnable(void){
    /* DMA mode enabled for transmitting */
	   USART1->CR3  |= USART_CR3_DMAT;
}

void USART1_void_Rx_DMAEnable(void){
	/* DMA mode enabled for reception */
	   USART1->CR3  |= USART_CR3_DMAR;
}

void USART1_initRXInterupt(void){//u8 Copy_USARTNumber){
//	if(Copy_USARTNumber == "USART1")
	{
		SET_BIT(USART1->CR1,USART_CR1_RXNEIE);
		//to enable usart global interrupt
		NVIC_voidEnableInterrupt(37);//USART1_IRQn);

	}
}


void USART1_send(u8 value)
{
     USART1->DR = value;                 //transfer data to DR register
     while(GET_BIT(USART1->SR,7) == 0);     //USART->SR  TXE  wait until data transmission is complete
}


u8 USART1_received(void)
{
   while(GET_BIT(USART1->SR,5) == 0);          //RX buffer not empty  5->RXNE
	   return(0xFF & USART1->DR);        //Read data from data register
}

//clear SR TC  -->0
 void USART1_SR_TC(void){

 }
