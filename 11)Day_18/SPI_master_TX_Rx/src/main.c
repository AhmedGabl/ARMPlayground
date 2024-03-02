
#include  "GPIO_interface.h"
#include "RCC_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void delay_gen(void);
void led_toggle(u8 *GPIOx, u8 pin_no);

u8 TestReady = 0;

//slave will reply this data when master issue read command
u8 slave_reply_data[] = {0x55, 0xaa, 0x55, 0xaa};

//Master read/write Buffer
u8 master_write_data[] = {0xa, 0xb, 0xc, 0xd};
u8 master_read_buffer[4];


int main(void)
{
	u8 addrcmd[CMD_LENGTH];
    u8 ack_buf[2];

	RCC_voidInit();
    spi_gpio_init();
    SPIConfig();
    SPI_enable(SPI_1);
  	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_LED_PIN,GPIO_PIN_MODE_GP_PP_10MHZ);

{
		addrcmd[0] = (u8) CMD_MASTER_WRITE;//0x5678
		addrcmd[1] = (u8) (CMD_MASTER_WRITE >> 8);

		//first send master write cmd to slave
		 spi_master_tx(SPI_1,addrcmd, CMD_LENGTH);

		 //spi_master_rx
	    spi_master_rx(SPI_1,&ack_buf, ACK_LEN);

		//Did we recive valid ack from slave
		if(ack_buf[1] == 0xE5 && (u8)ack_buf[2] == 0xD5)
			led_toggle(GPIO_PORTA, GPIO_LED_PIN);
	}

	return 0;
}

void delay_gen(void)
{
	u32 i;
	for(i=0; i <= 500000; i++);
}


void led_toggle(u8 *GPIOx, u8 pin_no)
{
	while(1){
	 GPIO_voidSetPinValue(GPIOx, pin_no, 1);
	delay_gen();
	GPIO_voidSetPinValue(GPIOx, pin_no, 0);
	}
}
