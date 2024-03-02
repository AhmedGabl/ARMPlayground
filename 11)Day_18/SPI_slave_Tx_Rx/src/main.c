#include  "GPIO_interface.h"
#include "RCC_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void led_toggle(u8 *GPIOx, u8 pin_no);
void delay_gen(void);

u8 master_write_data[] = {0xa, 0xb, 0xc, 0xd};
u8 master_read_buffer[4];

u8 slave_tx_buffer[DATA_LENGTH] = {0x55, 0xaa, 0x55, 0xaa};
u8 slave_rx_buffer[DATA_LENGTH];

int main(void)
{
	u8 ack_bytes[ACK_LEN];
	ack_bytes[0] = (u8)SPI_ACK_BYTES;
	ack_bytes[1] = (u8)(SPI_ACK_BYTES>>8);

	u16 master_cmd;
	u8 rcv_cmd[2];

	RCC_voidInit();
    spi_gpio_init();
    SPIConfig();
    SPI_enable(SPI_1);

  	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_LED_PIN,GPIO_PIN_MODE_GP_PP_10MHZ);

	 spi_master_rx(SPI_1, rcv_cmd, CMD_LENGTH);

	 master_cmd = (u16)(rcv_cmd[1] << 8 | rcv_cmd[0]);
		//it is a Valid Command
	if(master_cmd == CMD_MASTER_WRITE || master_cmd == CMD_MASTER_READ )
			{
				spi_master_tx(SPI_1, ack_bytes, 2);
				led_toggle(GPIO_PORTA, GPIO_LED_PIN);
			}

	return 0;
}

void delay_gen(void)
{
	u32 i;
	for(i=0; i <= 5000000; i++);
}


void led_toggle(u8 *GPIOx, u8 pin_no)
{
	while(1)
	{	GPIO_voidSetPinValue(GPIOx, pin_no, 1);
	delay_gen();
	GPIO_voidSetPinValue(GPIOx, pin_no, 0);
	}
}
