/*
 * SPI_interface.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_private.h"
#include "STD_TYPES.h"


#define SPI_8BIT_DF_ENABLE 0
#define SPI_16BIT_DF_ENABLE 1

//bit definitions for CR1 register
#define  SPI_CR1_CPHA	  0
#define  SPI_CR1_CPOL	  1
#define  SPI_CR1_MSTR	  2
#define  SPI_CR1_SPE      6
#define  SPI_CR1_LSBFIRST 7
#define  SPI_CR1_SSI      9
#define  SPI_CR1_SSM      9
#define  SPI_CR1_DFF	  11

//bit definitions for CR2 register
#define  SPI_CR2_RXDMAEN  0
#define  SPI_CR2_TXDMAEN  1
#define  SPI_CR2_SSOE     2
#define  SPI_CR2_ERRIE    5
#define  SPI_CR2_RXNEIE   6
#define  SPI_CR2_TXEIE    7

//bit definitions for SR rgister
#define  SPI_SR_RXNE	0
#define  SPI_SR_TXE		1
#define  SPI_SR_CHSIDE	2
#define  SPI_SR_UDR		3
#define  SPI_SR_CRCERR	4
#define  SPI_SR_MODF	5
#define  SPI_SR_OVR		6
#define  SPI_SR_BSY		7

//SPI_port pins
#define SPI_CLK_PIN_A	5
#define SPI_MISO_PIN_A	6
#define SPI_MOSI_PIN_A  7
//*/


void SPI_SS_Enable (void);
void SPI_SS_Disabe (void);


void spi_gpio_init(void);

void SPIConfig (void);


//Configure if the device is master or slave
void SPI_configDeviceMode(SPI_REG_t	*SPIx,u32 master);

// config the polarity n phas for SPI
void SPI_config_Phase_Polarity(SPI_REG_t *SPIx,u32 phase_value,u32 polarity);


//config datasize direction
void SPI_config_Datasize_direction(SPI_REG_t * SPIx,u32 datasize_16,u32 LSBfirst);

//config NSS pin of the master
void SPI_config_nss_master(SPI_REG_t *SPIx,u32 SSM_enable);

//config the NSS pin of the slave
void SPI_nss_slave(SPI_REG_t *SPIx,u32 SSM_enable);

//enable the SPI device
void SPI_enable(SPI_REG_t *SPIx);

//disable SPI device
void SPI_disable(SPI_REG_t *SPIx);

u8 hal_spi_is_bus_busy(SPI_REG_t *SPIx);

//master Tx
void spi_master_tx(SPI_REG_t *SPIx,u8 *buffer,u32 len);

void spi_master_rx(SPI_REG_t *SPIx,u8 *rx_buffer, u32 len);


#endif /* SPI_INTERFACE_H_ */
