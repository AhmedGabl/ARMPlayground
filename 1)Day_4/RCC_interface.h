/*
 * RCC_interface.h
 *
 *  Created on: Aug 3, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

// Macro definitions

#define RCC_AHB			0
#define RCC_APB1		1
#define RCC_APB2		2

#define RCC_MCO_NO		(-2)
#define RCC_SYS_CLK		(-1)
#define RCC_HSI			0
#define RCC_HSE			1
#define RCC_PLL			2


#define RCC_AHB_PRE_NO	0
#define RCC_AHB_PRE_2	8
#define RCC_AHB_PRE_4	9
#define RCC_AHB_PRE_8	10
#define RCC_AHB_PRE_16	11

typedef enum{
	NO,
	PRE2 = 8,
	PRE4,
	PRE8,
	PRE16,
}RCC_AHB_PRE;



// APB2 Peripherals
typedef enum{
	DMA1,
	DMA2,
	SRAM,
	RES1,
	FLITF,
	RES2,
	CRCE,
	RES3,
	FSMC,
	RES4,
	SDIO,
//APB2ENR
	AFIO,
	Res5,
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE, //M
	GPIOF,
	GPIOG,
	ADC1,
	ADC2,
	TIM1,
	SPI1,
	TIM8,
	USART,
	ADC3,
	RES6,
	RES7,
	RES8,
	TIM9,
	TIM10,
	TIM11,
//APB1ENR
	TIM2,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	RES9,
	RES10,
	WWDG,
	RES11,
	RES12,
	SPI2,
	SPI3,
	RES13,
	USART2,
	USART3,
	USART4,
	USART5,
	I2C1,
	I2C2,
	USB,
	RES14,
	CAN,
	RES15,
	BKP,
	PWR,
	DAC,
}Peripherals_t;

// Public functions decleration



void RCC_voidInit(void);

/*
 * Name: RCC_voidPeripheralClockEnable
 * Return type: void
 * Arguments: 	Copy_u8BusName: u8, (AHB, APB1, APB2)
 * 				Copy_u8PerphiralName: Peripherals_t, (enum values)
 * description: Enables Prephiral clock for a certain Prephiral
 */
void RCC_voidPeripheralClockEnable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName);

void RCC_voidPeripheralClockDisable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName);


#endif /* RCC_INTERFACE_H_ */
