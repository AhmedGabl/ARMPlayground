/*
 * SCB_program.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Ahmed Abogabl
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SCB_config.h"
#include "SCB_interface.h"
#include "SCB_private.h"


/*
 * SCB_voidPriorityDistInit
 * Parameters: void
 * description: Sets the Priority Model for group & sub-priorities
 */
void SCB_voidPriorityDistInit(void){
	SCB_AIRCR = NVIC_PRIORITY_DISTRIBUTION;
}

/*
 * NVIC_u32ReturnState
 * Parameters:i/p void		 o/p u32
 * description: returns the groupn subgroups priority state
 */
u32 SCB_u32ReturnPriorityDistState(void){
	return NVIC_PRIORITY_DISTRIBUTION;
}


