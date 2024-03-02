/*
 * SCB_interface.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef SCB_INTERFACE_H_
#define SCB_INTERFACE_H_



#define		NVIC_GROUP_4_BITS		0x05FA0300
#define		NVIC_GROUP_3_BITS		0x05FA0400
#define		NVIC_GROUP_2_BITS		0x05FA0500
#define		NVIC_GROUP_1_BITS		0x05FA0600
#define		NVIC_GROUP_0_BITS		0x05FA0700

//#define		NVIC_GROUP_4_BITS		0
//#define		NVIC_GROUP_3_BITS		1
//#define		NVIC_GROUP_2_BITS		2
//#define		NVIC_GROUP_1_BITS		3
//#define		NVIC_GROUP_0_BITS		4


/*
 * NVIC_voidInit
 * Parameters: void
 * description: Sets the Priority Model for group & sub-priorities
 */
void SCB_voidPriorityDistInit(void);


/*
 * NVIC_u32ReturnState
 * Parameters:i/p void		 o/p u32
 * description: returns the groupn subgroups priority state
 */
u32 SCB_u32ReturnPriorityDistState(void);


#endif /* SCB_INTERFACE_H_ */
