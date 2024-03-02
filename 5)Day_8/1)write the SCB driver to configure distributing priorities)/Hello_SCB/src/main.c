/*
 * ma;in.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SCB_interface.h"
#include "SCB_config.h"
#include "SCB_private.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"


int main(void)
{
	//RCC_voidInit();
	//RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);


	SCB_voidPriorityDistInit();
	NVIC_setPriorityDistState(SCB_u32ReturnPriorityDistState());


	//NVIC_voidSetPriority(6,3,3);
	//NVIC_voidSetPriority(7,1,1);

	return 0;
}
