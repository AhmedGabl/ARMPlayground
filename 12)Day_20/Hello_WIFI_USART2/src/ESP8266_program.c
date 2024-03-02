/*
 * ESP8266_program.c
 *
 *  Created on: Aug 27, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

#include "ESP8266_interface.h"
#include "ESP8266_config.h"
#include "ESP8266_private.h"


u8 AT[]="AT\r\n";
u8 ATE0[]="ATE0\r\n";

u8 AT_CWMODE[]="AT+CWMODE=1\r\n";
u8 AT_CWJAP[]="AT+CWJAP=\"";

u8 port_number[]="\",80\r\n";

u8 AT_CIPSTART[]="AT+CIPSTART=";
u8 TCP[]="\"TCP\",\"";
u8 end[] = "\"\r\n";

u8 AT_CIPSEND[]="AT+CIPSEND=";



void ESP_voidInit(void){

	u8	len = strlen(AT);
	for(u8 counter =0 ; counter< len ; counter++)
		USART1_send(AT[counter]);


	for(volatile u32 i=0; i<500000u; i++);
	len = strlen(ATE0);
		for(u8 counter =0 ; counter< len ; counter++)
			USART1_send(ATE0[counter]);


		for(volatile u32 i=0; i<500000u; i++);
	len = strlen(AT_CWMODE);
	for(u8 counter =0 ; counter <len ; counter++)
			USART1_send(AT_CWMODE[counter]);
}


void ESP_u8ConnectToWIFI(u8* SSID, u8* password){

	u8 len = strlen(AT_CWJAP);
	for(u8 counter =0 ; counter< len ; counter++)
		USART1_send(AT_CWJAP[counter]);


	len = strlen(SSID);
	for(u8 counter =0 ; counter< len ; counter++)
			USART1_send(SSID[counter]);

USART1_send('"');
USART1_send(',');
USART1_send('"');

	len = strlen(password);
	for(u8 counter =0 ; counter< len ; counter++)
		USART1_send(password[counter]);

//USART1_send('"');
//USART1_send(',');
//u8 temp[]="\"20:e8:82:e6:20:80";
//len =strlen(temp);
	//	for(u8 counter =0 ; counter< len ; counter++)
		//		USART1_send(temp[counter]);
	len = strlen(end);
	for(u8 counter =0 ; counter< len ; counter++)
	USART1_send(end[counter]);
}

void ESP_u8ConnectToSite(u8* IP){
	  u8  len = strlen(AT_CIPSTART);
	  for(u8 counter =0 ; counter <len ; counter++)
	  		USART1_send(AT_CIPSTART[counter]);

	  len = strlen(TCP);
	  for(u8 counter =0 ; counter< len ; counter++)
	  		USART1_send(TCP[counter]);

	  len = strlen(IP);
	  for(u8 counter =0 ; counter< len ; counter++)
	  		USART1_send(IP[counter]);

	  len = strlen(port_number);
	  for(u8 counter =0 ; counter< len ; counter++)
	  	USART1_send(port_number[counter]);//password[counter]);
}

void ESP_u8Send( u8* data){

	u8 len = strlen(AT_CIPSEND);
		 for(u8 counter =0 ; counter< len ; counter++)
		  	USART1_send(AT_CIPSEND[counter]);

//Calc the number of data byes to send/////////////////////
		  u8 num =strlen(data)+2;
		  u8 snum[5];
		  itoa(num, snum, 10);
			len = strlen(snum);
			 for(u8 counter =0 ; counter<= len ; counter++)
				  USART1_send(snum[counter]);
//////////////////////////////////////////////////////////////
		u8 end_t[] = "\r\n";
		  len = strlen(end_t);
		  for(u8 counter =0 ; counter< len ; counter++)
		  		USART1_send(end_t[counter]);
}

void ESP_u8SendData(u8 *data){
	u8  len = strlen(data);
			 for(u8 counter =0 ; counter<= len ; counter++)
				  USART1_send(data[counter]);

			 u8 end_t[] = "\r\n";
			 len = strlen(end_t);
			 for(u8 counter =0 ; counter< len ; counter++)
				  USART1_send(end_t[counter]);
}
