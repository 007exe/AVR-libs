#include "mcp23s17.h"

// запись значения в регистр А-адрес D-данные
void MCP23S17_write_Register(uint8_t A, uint16_t D)
{
SPI_PORT&=~(1<<SS);
SPI_MasterTransmit(MCP23S17_ADDRES|MCP23S17_AAA|MCP23S17_W);
SPI_MasterTransmit(A);
SPI_MasterTransmit(D);
SPI_PORT|=(1<<SS);
}

// чтение значения из регистра A-адрес
uint8_t MCP23S17_read_Register (uint8_t A)
{
	char R;
	SPI_PORT&=~(1<<SS);
	SPI_MasterTransmit(MCP23S17_ADDRES|MCP23S17_AAA|MCP23S17_R);
	SPI_MasterTransmit(A);
	R = SPI_MasterTransmit(0);
	SPI_PORT|=(1<<SS);
	return R;
}
