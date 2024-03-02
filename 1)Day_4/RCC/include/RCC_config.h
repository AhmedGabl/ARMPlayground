/*
 * RCC_config.h
 *
 *  Created on: Aug 3, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


#define RCC_HSE_ON			1 			// Enable status of HSE	1: ON, 0: OFF
#define RCC_HSI_ON			1
#define RCC_PLL_ON			1

#define RCC_TRIMMING_VAL	16

#define RCC_HSE_BYPASS		0
#define RCC_CSS_ON			0



#define RCC_SYSTEM_CLOCK_SWITCH		RCC_HSE
#define RCC_AHB_PRESCALER	RCC_AHB_PRE_NO
#define RCC_APB1_PRESCALER	1
#define RCC_APB2_PRESCALER	1
#define RCC_ADC_PRESCALER	1

#define RCC_PLL_SRC			RCC_HSE
#define RCC_PLL_HSE_DIV		0
#define RCC_PLL_MUL			2
#define RCC_MCO_SRC			RCC_HSE



#endif /* RCC_CONFIG_H_ */
