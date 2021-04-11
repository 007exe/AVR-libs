#include "mcp23s17.h"

// запись значения врегистр А-адрес D-данные
void MCP23S17_write_Register(char A, char D)
{
SPI_PORT&=~(1<<SS); // опускаем линию
SPI_MasterTransmit(MCP23S17_ADDRES|MCP23S17_AAA|MCP23S17_W);
SPI_MasterTransmit(A);
SPI_MasterTransmit(D);
SPI_PORT|=(1<<SS);
}

// чтение значения в регистр A-адрес
char MCP23S17_read_Register (char A)
{
	char R;
	SPI_PORT&=~(1<<SS);
	SPI_MasterTransmit(MCP23S17_ADDRES|MCP23S17_AAA|MCP23S17_R);
	SPI_MasterTransmit(A);
	R = SPI_MasterTransmit(0);
	SPI_PORT|=(1<<SS);
	return R;
}
