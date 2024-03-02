/*
 * USART_private.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef USART_PRIVATE_C_
#define USART_PRIVATE_C_


#define USART1_BASE_ADDRESS		0x40013800
#define USART2_BASE_ADDRESS		0x40004400
#define USART3_BASE_ADDRESS		0x40004800
#define UART4_BASE_ADDRESS		0x40004C00
#define UART5_BASE_ADDRESS		0x40005000


typedef struct{

	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_t;

#define USART1		((volatile USART_t*)USART1_BASE_ADDRESS)
#define USART2		((volatile USART_t*)USART2_BASE_ADDRESS)
#define USART3		((volatile USART_t*)USART3_BASE_ADDRESS)
#define UART4		((volatile USART_t*)UART4_BASE_ADDRESS)
#define UART5		((volatile USART_t*)UART5_BASE_ADDRESS)




#endif /* USART_PRIVATE_C_ */
