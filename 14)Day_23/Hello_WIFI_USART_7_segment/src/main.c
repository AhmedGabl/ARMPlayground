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

u16 SevSeg[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

//functions prototypes
u8 isStrFound(u8* str, u8* strFound);
void empty_arr(u8 *arr , u8 size);
void Seven_seg(void);

u8 temp , c=0 , len=0 ;
u8 buff[SIZE];


//interrupt recieve
void USART1_IRQHandler(void){
	if(USART1_SR_RXNE == 1)
	{
			buff[len]=USART1->DR;
			len++;
	if(isStrFound(buff,"OK\r\n")&& c<3 ){
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
	}else if(isStrFound(buff,"+PID,1:")){
		Seven_seg();
		empty_arr(buff,SIZE);
		len =0;
	}
}
	temp = USART1->DR;
}



void Seven_seg(void){
	if(isStrFound(buff,"+PID,1:0"))
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[0]);
	else if(isStrFound(buff,"+PID,1:1"))
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[1]);
	else if(isStrFound(buff,"+PID,1:2"))
		GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[2]);
	else if(isStrFound(buff,"+PID,1:3"))
		GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[3]);
	else if(isStrFound(buff,"+PID,1:4"))
		GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[4]);
	else if(isStrFound(buff,"+PID,1:5"))
		GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[5]);
	else if(isStrFound(buff,"+PID,1:6"))
		GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[6]);
	else if(isStrFound(buff,"+PID,1:7"))
		GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[7]);
	else if(isStrFound(buff,"+PID,1:8"))
		GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[8]);
	else if(isStrFound(buff,"+PID,1:9"))
		GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, SevSeg[9]);
}

void dirty_delay (void)
	{
	  for(volatile u32 i=0; i<200000u; i++);
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
			ESP_u8numOfDataToSend(Data);
			break;
		case 4:
			ESP_u8SendData(Data);
			break;
}
}
void main(){
	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

		for(volatile u8 i=0 ; i < 10 ; i++){
		GPIO_voidSetPinMode(GPIO_PORTA, i, GPIO_PIN_MODE_GP_PP_10MHZ);
		}

	USART_init();
	ESP_voidInit();
    USART_initRXInterupt();
//    GPIO_voidSetPinMode(GPIO_PORTA,0,GPIO_PIN_MODE_GP_PP_10MHZ);


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
