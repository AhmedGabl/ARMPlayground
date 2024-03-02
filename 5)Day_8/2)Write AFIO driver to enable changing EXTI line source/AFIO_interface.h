/*
 * AFIO_interface.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_


#define AFIO_PORT_A		0
#define AFIO_PORT_B		1
#define AFIO_PORT_C		2
#define AFIO_PORT_D		3
#define AFIO_PORT_E		4
#define AFIO_PORT_F		5
#define AFIO_PORT_G		6


/*
 * AFIO_selectSourceInput
 * parameters : o/p void      -   i/p Copy_u8EXTI_line, Copy_u8EXTI_PORT_NAME
 * description : selects port 'source' input to EXTI
 * */
void AFIO_selectSourceInput(u8 Copy_u8EXTI_line,u8 Copy_u8EXTI_PORT_NAME );



#endif /* AFIO_INTERFACE_H_ */
