/*
 * SPI_config.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


//Define used for transfer Communication
#define CMD_MASTER_READ           ((u16)0x1234)
#define CMD_MASTER_WRITE          ((u16)0x5678)
#define CMD_LENGTH                 2
#define DATA_LENGTH                4
#define ACK_LEN                    2
#define SPI_ACK_BYTES              0xD5E5


#define GPIO_LED_PIN 1

#define SPI_CLK_PIN_A	5
#define SPI_MISO_PIN_A	6
#define SPI_MOSI_PIN_A  7



#endif /* SPI_CONFIG_H_ */
