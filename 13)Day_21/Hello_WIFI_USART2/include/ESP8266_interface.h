/*
 * ESP8266_interface.h
 *
 *  Created on: Aug 27, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef ESP8266_INTERFACE_H_
#define ESP8266_INTERFACE_H_

#include "STD_TYPES.h"
///some parameter for the string functions

void ESP_voidInit(void);
void ESP_u8ConnectToWIFI(u8* SSID, u8* password);
void ESP_u8ConnectToSite(u8* IP);
void ESP_u8numOfDataToSend(u8* data);
void ESP_u8SendData(u8 *data);

#endif /* ESP8266_INTERFACE_H_ */
