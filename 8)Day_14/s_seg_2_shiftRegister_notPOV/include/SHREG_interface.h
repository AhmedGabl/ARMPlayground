/*
 * SHREG_interface.h
 *
 *  Created on: Aug 18, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef SHREG_INTERFACE_H_
#define SHREG_INTERFACE_H_

void S_sendData(u8 Copy_u8Port,u8 Copy_u8DataPin1,u8 Copy_u8DataPin2, u8 Copy_u8ClkPin,u8 Copy_u8LatchPin,u16 Data1,u16 Data2);

//  low then hight to reset
//void S_reset(u8 Copy_u8Port, u8 Copy_u8Pin);









// control if the out gets out or not      Latch ic
// low  to get the data out in the output pins
//void S_EnableOutput(u8 Copy_u8Port, u8 Copy_u8Pin);


//get only serial data   put hight
//void S_DisableOutput(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif /* SHREG_INTERFACE_H_ */
