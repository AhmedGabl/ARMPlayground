/*
 * SPI_program.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Abogabl
 */

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"


void SPI_SS_Enable (void)
{
	GPIO_voidSetPinValue(GPIO_PORTA,4,GPIO_LOW);
}

void SPI_SS_Disable (void)
{
	GPIO_voidSetPinValue(GPIO_PORTA,4,GPIO_HIGH);
}
void SPIConfig (void)
{
	RCC_voidPeripheralClockEnable(RCC_APB2,SPI1);

	SPI_config_Phase_Polarity(SPI_1,1,1);
	SPI_configDeviceMode(SPI_1,1);
	  SPI_1->CR1 |= (3<<3);  // BR[2:0] = 011: fPCLK/16, PCLK2 = 80MHz, SPI clk = 5MHz
	  SPI_1->CR1 &= ~(1<<7);  // LSBFIRST = 0, MSB first
	  SPI_1->CR1 |= (1<<8) | (1<<9);  // SSM=1, SSi=1 -> Software Slave Managemen
	  SPI_1->CR1 &= ~(1<<10);  // RXONLY = 0, full-duplex
	  SPI_1->CR1 &= ~(1<<11);  // DFF=0, 8 bit data
	  SPI_1->CR2 = 0;
}

void spi_gpio_init(void)
{
		RCC_voidInit();
		RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
		GPIO_voidSetPinMode(GPIO_PORTA,SPI_CLK_PIN_A,GPIO_PIN_MODE_AF_PP_2MHZ);
		GPIO_voidSetPinMode(GPIO_PORTA,SPI_MOSI_PIN_A,GPIO_PIN_MODE_AF_PP_2MHZ);
		GPIO_voidSetPinMode(GPIO_PORTA,SPI_MISO_PIN_A,GPIO_PIN_MODE_PULLING_INPUT);
		GPIO_voidSetPinMode(GPIO_PORTA,4,GPIO_PIN_MODE_GP_PP_2MHZ);
}


//Configure if the device eis master or slave
void SPI_configDeviceMode(SPI_REG_t	*SPIx,u32 master){
	if(master)
	{
		SET_BIT(SPIx->CR1,SPI_CR1_MSTR);
	}
	else
	{
		CLR_BIT(SPIx->CR1,SPI_CR1_MSTR);
	}
}
// config the polarity n phas for SPI
void SPI_config_Phase_Polarity(SPI_REG_t *SPIx,u32 phase_value,u32 polarity)
{
	if(phase_value)
		{
			SET_BIT(SPIx->CR1,SPI_CR1_CPHA);
		}
		else
		{
			CLR_BIT(SPIx->CR1,SPI_CR1_CPHA);
		}
	if(polarity)
		{
			SET_BIT(SPIx->CR1,SPI_CR1_CPOL);
		}
		else
		{
			CLR_BIT(SPIx->CR1,SPI_CR1_CPOL);
		}
}


//config datasize direction
void SPI_config_Datasize_direction(SPI_REG_t * SPIx,u32 datasize_16,u32 LSBfirst)
{
	if(datasize_16)
			{
				SET_BIT(SPIx->CR1,SPI_CR1_DFF);
			}
			else
			{
				CLR_BIT(SPIx->CR1,SPI_CR1_DFF);
			}
		if(LSBfirst)
			{
				SET_BIT(SPIx->CR1,SPI_CR1_LSBFIRST);
			}
			else
			{
				CLR_BIT(SPIx->CR1,SPI_CR1_LSBFIRST);
			}

}

//config NSS pin of the master
void SPI_config_nss_master(SPI_REG_t *SPIx,u32 SSM_enable)
{
	if(SSM_enable)
	{
		SET_BIT(SPIx->CR1,SPI_CR1_SSM);
		SET_BIT(SPIx->CR1,SPI_CR1_SSI);
	}
	else
	{
		CLR_BIT(SPIx->CR1,SPI_CR1_SSM);
	}
}


//config the NSS pin of the slave
void SPI_nss_slave(SPI_REG_t *SPIx,u32 SSM_enable)
{
	if(SSM_enable)
		{
			SET_BIT(SPIx->CR1,SPI_CR1_SSM);
		}
		else
		{
			CLR_BIT(SPIx->CR1,SPI_CR1_SSM);
		}
}

//enable the SPI device
void SPI_enable(SPI_REG_t *SPIx)
{
	if(!(GET_BIT(SPIx->CR1,SPI_CR1_SPE)))
		SET_BIT(SPIx->CR1,SPI_CR1_SPE);
}


//disable SPI device
void SPI_disable(SPI_REG_t *SPIx)
{
		CLR_BIT(SPIx->CR1,SPI_CR1_SPE);
}
void spi_master_tx(SPI_REG_t *SPIx,u8 *buffer,u32 len)
{
	u32 i=0;
		while (i<len)
		{
		   while (!((GET_BIT(SPIx->SR,SPI_SR_TXE)))) ;  // wait for TXE bit to set -> This will indicate that the buffer is empty
		   SPIx->DR = buffer[i];  // load the data into the Data Register
		   i++;
		}

		while (!(GET_BIT(SPIx->SR,SPI_SR_TXE))) ;  // wait for TXE bit to set -> This will indicate that the buffer is empty
		while (((GET_BIT(SPIx->SR,SPI_SR_BSY)))) ;  // wait for BSY bit to Reset -> This will indicate that SPI is not busy in communication

		//  Clear the Overrun flag by reading DR and SR
		u8 temp = SPIx->DR;
		   temp = SPIx->SR;
}

void spi_master_rx(SPI_REG_t *SPIx,u8 *rx_buffer, u32 len)
{
	while (len)
	{
		while (((GET_BIT(SPIx->SR,SPI_SR_BSY)))) ;  // wait for BSY bit to Reset -> This will indicate that SPI is not busy in communication
		SPIx->DR = 0;  // send dummy data
		while (!((GET_BIT(SPIx->SR,SPI_SR_RXNE))));  // Wait for RXNE to set -> This will indicate that the Rx buffer is not empty
	  *rx_buffer++ = (SPIx->DR);
		len--;
	}
}
