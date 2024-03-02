/*
 * SHREG_program.c
 *
 *  Created on: Aug 18, 2022
 *      Author: Ahmed Abogabl
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SHREG_interface.h"
#include "SHREG_config.h"
#include "SHREG_private.h"

#include "GPIO_interface.h"
//#include "SYSTICK_interface.h"

void S_sendData(u8 Copy_u8Port,u8 Copy_u8DataPin, u8 Copy_u8ClkPin,u8 Copy_u8LatchPin,u16 Data){
//	STK_voidInit(SYSTICK_AHB_8);

	GPIO_voidSetPinMode(Copy_u8Port , Copy_u8DataPin , GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(Copy_u8Port , Copy_u8LatchPin , GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(Copy_u8Port , Copy_u8ClkPin , GPIO_PIN_MODE_GP_PP_10MHZ);

	GPIO_voidSetPinValue(Copy_u8Port,Copy_u8DataPin,GPIO_LOW);
	GPIO_voidSetPinValue(Copy_u8Port,Copy_u8ClkPin,GPIO_LOW);

	GPIO_voidSetPinValue(Copy_u8Port,Copy_u8LatchPin,GPIO_LOW);

	u8 PinState;
	for( u8 i=0 ;i <= 6; i++ ){

		GPIO_voidSetPinValue(Copy_u8Port,Copy_u8ClkPin,GPIO_LOW);

		if(Data & (1<<i)){
			PinState = 1;
		}else{
			PinState = 0;
		}
		GPIO_voidSetPinValue(Copy_u8Port,Copy_u8DataPin,PinState);
		GPIO_voidSetPinValue(Copy_u8Port,Copy_u8ClkPin,GPIO_HIGH);

		GPIO_voidSetPinValue(Copy_u8Port,Copy_u8DataPin,GPIO_LOW);

	}
	GPIO_voidSetPinValue(Copy_u8Port,Copy_u8ClkPin,GPIO_LOW);
	GPIO_voidSetPinValue(Copy_u8Port,Copy_u8LatchPin,GPIO_HIGH);
//	STK_voidSetBusyWait(100);

}
