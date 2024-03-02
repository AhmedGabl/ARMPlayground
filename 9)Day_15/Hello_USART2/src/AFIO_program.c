/*
 * AFIO_program.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Ahmed Abogabl
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


/*
 * AFIO_selectSourceInput
 * parameters : o/p void      -   i/p Copy_u8EXTI_line, Copy_u8EXTI_PORT_NAME
 * description : selects port 'source' input to EXTI
 * */
void AFIO_selectSourceInput(u8 Copy_u8EXTI_line,u8 Copy_u8EXTI_PORT_NAME )
{
	if(Copy_u8EXTI_line < 4 ){
		AFIO_EXTICR[Copy_u8EXTI_line] = Copy_u8EXTI_PORT_NAME;
	}else if(Copy_u8EXTI_line  < 8){
		AFIO_EXTICR[Copy_u8EXTI_line] = Copy_u8EXTI_PORT_NAME;
	}else if(Copy_u8EXTI_line < 12 ){
		AFIO_EXTICR[Copy_u8EXTI_line] = Copy_u8EXTI_PORT_NAME;
	}else if(Copy_u8EXTI_line < 16){
		AFIO_EXTICR[Copy_u8EXTI_line] = Copy_u8EXTI_PORT_NAME;
	}
}

