/*
 * SPI_config.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#define CMD_LENGTH      2
#define ACK_LEN         4

#define DATA_LENGTH     4

#define CMD_MASTER_WRITE  0x5678
#define CMD_MASTER_READ  0x1234

#define GPIO_LED_PIN 1

#define SPI_CLK_PIN_A	5
#define SPI_MISO_PIN_A	6
#define SPI_MOSI_PIN_A  7


#endif /* SPI_CONFIG_H_ */
