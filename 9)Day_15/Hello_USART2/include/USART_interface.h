/*
 * USART_interface.h
 *
 *  Created on: Aug 19, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include  "BIT_MATH.h"

#define USART_CR1_UE   13
#define USART_CR1_RE  2
#define USART_CR1_TE  3
#define USART_CR1_RXNEIE  5


#define USART1_SR_RXNE	GET_BIT(USART1->SR,5)
#define USART2_SR_RXNE	GET_BIT(USART2->SR,5)
#define USART3_SR_RXNE	GET_BIT(USART3->SR,5)
#define UART4_SR_RXNE	GET_BIT(UART4->SR,5)
#define UART5_SR_RXNE	GET_BIT(UART5->SR,5)

#define USART1_SR_TC  GET_BIT(USART1->SR,6)

void USART_init(void);

void USART_initRXInterupt(void);


void USART1_send(unsigned char value);


u8 USART1_received(void);



#endif /* USART_INTERFACE_H_ */
