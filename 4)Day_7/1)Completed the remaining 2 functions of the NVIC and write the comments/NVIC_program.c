/*
 * NVIC_program.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed Abogabl
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


/*
 * NVIC_voidEnableInterrupt
 * parameters:Copy_u8InterruptPotiotion
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptPotiotion){

	if(Copy_u8InterruptPotiotion < 32){
		NVIC_ISER0 = 1 << Copy_u8InterruptPotiotion;
	}else if(Copy_u8InterruptPotiotion < 60){
		NVIC_ISER1 = 1 << (Copy_u8InterruptPotiotion - 32);
	}
}

/*
 * NVIC_voidDisableInterrupt
 * parameters:Copy_u8InterruptPotiotion
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptPotiotion){

	if(Copy_u8InterruptPotiotion < 32){
		NVIC_ICER0 = 1 << Copy_u8InterruptPotiotion;
	}else if(Copy_u8InterruptPotiotion < 60){
		NVIC_ICER1 = 1 << (Copy_u8InterruptPotiotion - 32);
	}

}

/*
 * NVIC_voidSetPendingFlag
 * parameters:Copy_u8InterruptPotiotion
 * description: Sets the NVIC pending pin for a specific interrupt
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptPotiotion){

	if(Copy_u8InterruptPotiotion < 32){
		NVIC_ISPR0 = 1 << Copy_u8InterruptPotiotion;
	}else if(Copy_u8InterruptPotiotion < 60){
		NVIC_ISPR1 = 1 << (Copy_u8InterruptPotiotion - 32);
	}

}


/*
 * NVIC_voidClearPendingFlag
 * parameters:Copy_u8InterruptPotiotion
 * description: clears the NVIC pending pin for a specific interrupt
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptPotiotion){
	if(Copy_u8InterruptPotiotion < 32){
		NVIC_ICPR0 = 1 << Copy_u8InterruptPotiotion;
	}else if(Copy_u8InterruptPotiotion < 60){
		NVIC_ICPR1 = 1 << (Copy_u8InterruptPotiotion - 32);
	}
}

/*
 * NVIC_u8GetActiveFlag
 * parameters:Copy_u8InterruptPotiotion
 * return value:the flag
 * description:reads bit of the corresponding interrupt if active 1 or not 0
 */
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptPotiotion){
	u8 temp;
	if(Copy_u8InterruptPotiotion < 32){
		temp = GET_BIT(NVIC_SetPriority(),Copy_u8InterruptPotiotion);
	}else if(Copy_u8InterruptPotiotion < 60){
		temp = GET_BIT(NVIC_IABR1,Copy_u8InterruptPotiotion);
	}
	return temp;
}
