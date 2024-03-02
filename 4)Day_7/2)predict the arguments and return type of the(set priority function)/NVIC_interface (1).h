/*
 * NVIC_interface.h
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_








/**
Description Set the priority for an interrupt or system exceptions
with programmable priority level.

Parameter Copy_u8InterruptPotiotion is the Number of the interrupt.
priority  is the priority for the interrupt. This
function automatically shifts the input priority value
left to put priority value in implemented bits.

Return None
 */
void void NVIC_SetPriority(u8 Copy_u8InterruptPotiotion, u32 priority);

///////////////////////////////////////////////////////or

/*
 * NVIC_voidSetPriority
 * parameters:
 * return value:
 * description: Sets the priority for a specific interrupt
 */
//void NVIC_voidSetPriority(u8 Copy_u8InterruptPosition, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);


/*
 * NVIC_voidEnableInterrupt
 * parameters:Copy_u8InterruptPotiotion
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptPotiotion);


/*
 * NVIC_voidDisableInterrupt
 * parameters:Copy_u8InterruptPotiotion
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptPotiotion);

/*
 * NVIC_voidSetPendingFlag
 * parameters:
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptPotiotion);


/*
 * NVIC_voidClearPendingFlag
 * parameters:Copy_u8InterruptPotiotion
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptPotiotion);

/*
 * NVIC_u8GetActiveFlag
 * parameters:Copy_u8InterruptPotiotion
 * return value:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptPotiotion);






#endif /* NVIC_INTERFACE_H_ */
