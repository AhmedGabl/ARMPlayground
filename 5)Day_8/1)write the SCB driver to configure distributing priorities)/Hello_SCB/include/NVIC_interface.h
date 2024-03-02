/*
 * NVIC_interface.h
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


/*
 * NVIC_voidEnableInterrupt
 * parameters:
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptPosition);


/*
 * NVIC_voidDisableInterrupt
 * parameters:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptPosition);

/*
 * NVIC_voidSetPendingFlag
 * parameters:
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptPosition);


/*
 * NVIC_voidClearPendingFlag
 * parameters:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptPosition);

/*
 * NVIC_u8GetActiveFlag
 * parameters:
 * return value:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptPosition);

/*
 * NVIC_voidSetPriority
 * parameters:
 * return value:
 * description: Sets the priority for a specific interrupt
 */
void NVIC_voidSetPriority(u8 Copy_u8InterruptPosition, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

#endif /* NVIC_INTERFACE_H_ */
