/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "DMA_interface.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "SPI_interface.h"

#define  TRUE 1
#define  FALSE 0
#define  DATA_LEN 5

//buff array
u8 buff[50];
//functions prototypes
void USART1_RX_DMA(u8 len);
void SPI_TX(u8 len);

void DMA1_Channel5_IRQHandler(){
	//clear the RX channel
DMA_voidClearIFCR_chx(4);
DMA_ChannelDisable(4);
// check if valid data
SPI_TX(DATA_LEN);
}

void DMA1_Channel3_IRQHandler(){
DMA_voidClearIFCR_chx(2);
DMA_ChannelDisable(2);
//on led after the transmition is complete
	GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_HIGH);
}

void main()
{
	//init periphrals clk
	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	RCC_voidPeripheralClockEnable(RCC_AHB,DMA1);
	//led pin initialization
	GPIO_voidSetPinMode(GPIO_PORTA,0,GPIO_PIN_MODE_GP_PP_10MHZ);

	USART1_RX_DMA(DATA_LEN);

}

void USART1_RX_DMA(u8 len){
	USART1_init();
	USART1_void_Rx_DMAEnable();
	//RX USART data using DMA
	DMA_voidChannel_Set_Addresses(4,buff,&(USART1->DR),len);
	DMA_voidEnableInterrupt(4,15);
	DMA_voidIncrementPer(4);
	DMA_voidClearIncrementMem(4);
	DMA_voidChannelEnable(4);
}

void SPI_TX(u8 len){
	spi_gpio_init();
	SPIConfig();
	SPI_enable(SPI_1);
	SPI_Tx_DMA_enable(SPI_1);

	//TX SPI master using DMA
	DMA_voidChannel_Set_Addresses(2,&(SPI_1->DR),buff,len);
	DMA_voidEnableInterrupt(2,13);
	DMA_voidChannelEnable(2);

}
