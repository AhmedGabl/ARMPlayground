/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed Abogabl
 */

#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "ESP8266_interface.h"

#define  TRUE 1
#define  FALSE 0
#define  SIZE  100

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<network parameters>>>>>>>>>>>>>>>>
u8 SSID[]="shehab";
u8 Pass[]="12345678900";
u8 IP[] = "162.253.155.226";//"162.253.155.226:80";
u8 Data[]= "GET http://armalex828.freevar.com/status.txt";
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//functions prototypes
u8 isStrFound(u8* str, u8* strFound);
void empty_arr(u8 *arr , u8 size);

u8 temp , c=0 , len=0 ;
u8 buff[SIZE];


//interrupt recieve
void USART1_IRQHandler(void){
	if(USART1_SR_RXNE == 1)
	{
			buff[len]=USART1->DR;
			len++;
	if(isStrFound(buff,"OK")&& c<3 ){
		empty_arr(buff,SIZE);
		len=0;
		next_cmd();
	}else if(isStrFound(buff,"> ") && c==3){
		empty_arr(buff,SIZE);
		len=0;
		next_cmd();
	}else if (isStrFound(buff,"ERROR\r\n")||isStrFound(buff,"FAIL\r\n")) {
		c=0;
		empty_arr(buff,SIZE);
		len =0;
		next_cmd();
	}else if(isStrFound(buff,"+PID,1:1")){
		led(1);
		empty_arr(buff,SIZE);
		len =0;
	}else if(isStrFound(buff,"+PID,1:0")){
		led(0);
		empty_arr(buff,SIZE);
		len =0;
	}
}
	temp = USART1->DR;
}


void dirty_delay (void)
	{
	  for(volatile u32 i=0; i<200000u; i++);
	}

void led(u8 i){
	if(i)
			GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_HIGH);
	else
			GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_LOW);
}

void next_cmd(void){
	c++;
	switch(c){
		case 1:
		    ESP_u8ConnectToWIFI(SSID,Pass);
		    break;
		case 2:
			ESP_u8ConnectToSite(IP);
			break;
		case 3:
			ESP_u8Send(Data);
			break;
		case 4:
			ESP_u8SendData(Data);
			break;
}
}
void main(){
	RCC_voidInit();
	USART_init();
	ESP_voidInit();
    USART_initRXInterupt();
    GPIO_voidSetPinMode(GPIO_PORTA,0,GPIO_PIN_MODE_GP_PP_2MHZ);


	while(1){	}

}

u8 isStrFound(u8* str, u8* strFound) {
    u8 state = FALSE;
    for (u8 i = 0; str[i] != '\0'; i++) {
        if (str[i] == strFound[0]) {
            u8 j = 1;
            for (; strFound[j] != '\0'; j++) {
                i++;
                if (strFound[j] != str[i]) {
                    break;
                }
            }
            if (strFound[j] == '\0') {
                state = TRUE;
                break;
            }
        }
    }
    return state;
}

void empty_arr(u8 *arr, u8 size){
	for(u8 i=0;i<size;i++)
		 {arr[i]=0;}
}
