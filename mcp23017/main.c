#include "main.h"

int main(void)
{
I2C_Init();
DDRB=0xFF;
char i=1;

MCP23017_DDRA_W(0b00000000);
MCP23017_DDRB_W(0b11111111);
    while (1) 
    {
		MCP23017_PORTA_W (i);
		PORTB = MCP23017_PINB_R;
		_delay_ms(100);
		i<<=1;
		if (!i)i=1;
    }

}

