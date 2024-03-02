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



void SPIConfig (void)
{
	RCC_voidPeripheralClockEnable(RCC_APB2,SPI1);
	SPI_config_Phase_Polarity(SPI_1,1,1);
	SPI_configDeviceMode(SPI_1,0);
	  SPI_1->CR1 |= (3<<3);  // BR[2:0] = 011: fPCLK/16, PCLK2 = 80MHz, SPI clk = 5MHz
	  SPI_1->CR1 &= ~(1<<7);  // LSBFIRST = 0, MSB first
	  SPI_1->CR1 |= (1<<8) | (1<<9);  // SSM=1, SSi=1 -> Software Slave Management
	  SPI_1->CR1 &= ~(1<<10);  // RXONLY = 0, full-duplex
	  SPI_1->CR1 &= ~(1<<11);  // DFF=0, 8 bit data
	  SPI_1->CR2 = 0;
}

void spi_gpio_init(void)
{
	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	RCC_voidPeripheralClockEnable(RCC_APB2,SPI1);
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

//Enables the Tx buffer empty interrupt (TXE)
void SPI_enable_txe_interrupt(SPI_REG_t *SPIx)
{
	SET_BIT(SPIx->CR2,SPI_CR2_TXEIE);
}

//disables the Tx buffer empty interrupt (TXE)
void SPI_disable_txe_interrupt(SPI_REG_t *SPIx)
{
	CLR_BIT(SPIx->CR2,SPI_CR2_TXEIE);
}
void SPI_enable_rxne_interrupt(SPI_REG_t *SPIx)
{
	SET_BIT(SPIx->CR2,SPI_CR2_RXNEIE);
}

//disables the Tx buffer empty interrupt (TXE)
void SPI_disable_rxne_interrupt(SPI_REG_t *SPIx)
{
	CLR_BIT(SPIx->CR2,SPI_CR2_RXNEIE);
}

u8 hal_spi_is_bus_busy(SPI_REG_t *SPIx)
{
	if(GET_BIT(SPIx->SR,SPI_SR_BSY))
			return 1; // SPI bus is  busy
		else
			return 0;// SPI bus is free
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
//slave tx
/*
void SPI_slave_tx(SPI_REG_t *SPIx,u8 *tx_buffer,u32 len)
{
	spi_handle->pRxBuffPtr =tx_buffer;
	spi_handle->TxXferCount=len;
	spi_handle->TxXferSize =len;

	//dummy
	spi_handle->pRxBuffPtr =tx_buffer;
	spi_handle->RxXferCount=len;
	spi_handle->RxXferSize =len;

	//driver is busy in RX
	spi_handle->State = SPI_STATE_BUSY_TX;

	SPI_enable(spi_handle->Instance);

	//now enable both TXE and RXNE  interrupt
    SPI_enable_rxne_interrupt(spi_handle->Instance);
	SPI_enable_txe_interrupt(spi_handle->Instance);
}*/
/*
void SPI_slave_rx(SPI_REG_t *SPIx,u8 *rcv_buffer,u32 len)
{
	spi_handle->pTxBuffPtr =rcv_buffer;
	spi_handle->RxXferCount = len;
	spi_handle->RxXferSize =len;

	spi_handle->State = SPI_STATE_BUSY_RX;

	SPI_enable(spi_handle->Instance);

	SPI_enable_rxne_interrupt(spi_handle->Instance);
}
*/
/*
void 	i2c_spi_irq_handler(spi_handle_t *hspi)
{
	u32 temp1=0,temp2=0;

	//check to see RXNE is set in the status register
	temp1 =GET_BIT(hspi->Instance->SR,SPI_SR_RXNE);
	//check whether RXNEIE bit is enabled in the control register
	temp1 =GET_BIT(hspi->Instance->CR2,SPI_CR2_RXNEIE);

	if ((temp1 != RESET )&&(temp2 != RESET))
	{	//RXNE flag is set
		//handle the RX of the data bytes
		SPI_hanlde_rx_interrupt(hspi);
	return;
	}
    	temp1 =GET_BIT(hspi->Instance->SR,SPI_SR_TXE);
		//check whether RXNEIE bit is enabled in the control register
		temp1 =GET_BIT(hspi->Instance->CR2,SPI_CR2_TXEIE);

		if ((temp1 != RESET )&&(temp2 != RESET))
		{	//TXE flag is set
			//handle the TX of the data bytes
			SPI_hanlde_tx_interrupt(hspi);
		return;
		}
}
*/

/*
void SPI_hanlde_rx_interrupt(spi_handle_t *hspi)
{
	//recieve data in 8 bit
		if(hspi->Init.SPI_DataSize == SPI_8BIT_DF_ENABLE)
		{
			if(hspi->pRxBuffPtr++)
		  (*hspi->pRxBuffPtr++) = hspi->Instance->DR;
			hspi->RxXferCount--;
		}
		else
		{
			*((u16 *) hspi->pRxBuffPtr )= *((u16*)hspi->pTxBuffPtr++);
			hspi->pRxBuffPtr+=2;
			hspi->RxXferCount-=2;
		}
		if(hspi->RxXferCount == 0)
		{
			SPI_rx_close_interrupt(hspi);
		}

}*/
/*
void SPI_hanlde_tx_interrupt(spi_handle_t *hspi)
{
	//transmit data in 8 bit
	if(hspi->Init.SPI_DataSize == SPI_8BIT_DF_ENABLE)
	{
		hspi->Instance->DR = (*hspi->pTxBuffPtr++);
		hspi->TxXferCount--;
	}
	else
	{
		hspi->Instance->DR = *((u16*)hspi->pTxBuffPtr++);
		hspi->pRxBuffPtr+=2;
		hspi->TxXferCount-=2;
	}
	if(hspi->TxXferCount == 0)
	{
		SPI_tx_close_interrupt(hspi);
	}

}
*/
