#include "main.h"

int main(void)
{
	SPI_MasterInit();
	DDRD=0xFF;
	char i=1;

	MCP23S17_DDRA_W(0b11111111);
	MCP23S17_DDRB_W(0b00000000);
	while (1)
	{
		MCP23S17_PORTA_W (i);
		PORTD = MCP23S17_PINB_R;
		_delay_ms(100);
		i<<=1;
		if (!i)i=1;
	}

}

