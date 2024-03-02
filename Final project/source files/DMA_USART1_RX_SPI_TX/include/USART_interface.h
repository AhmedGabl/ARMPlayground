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

#define USART_CR3_DMAR 0x0040
#define USART_CR3_DMAT 0x0080

#define USART1_SR_RXNE	GET_BIT(USART1->SR,5)
#define USART2_SR_RXNE	GET_BIT(USART2->SR,5)
#define USART3_SR_RXNE	GET_BIT(USART3->SR,5)
#define UART4_SR_RXNE	GET_BIT(UART4->SR,5)
#define UART5_SR_RXNE	GET_BIT(UART5->SR,5)

/*
 * description :-initialize USART TX  RX polling
 * */
void USART1_init(void);

/*
 * description :- initialize RX interrupt
 * */
void USART1_initRXInterupt(void);

/*
 * description :- send data
 * */
void USART1_send(u8 value);

/*
 * description :- receive data
 * */
u8 USART1_received(void);

void USART1_void_Tx_DMAEnable(void);

void USART1_void_Rx_DMAEnable(void);

#endif /* USART_INTERFACE_H_ */
