#include "mcp23017.h"

// запись значения врегистр А-адрес D-данные
void MCP23017_write_Register(char A, char D)
{
	I2C_StartCondition();									// генерируем условия СТАРТ
	I2C_SendByte(MCP23017_ADDRES|MCP23017_AAA|MCP23017_W);	// адрес устройства + бит записи w
	I2C_SendByte(A);										// отправка Адрес регистра
	I2C_StartCondition();									// генерация условия СТАРТ (РЕСТАРТ)
	I2C_SendByte(MCP23017_ADDRES|MCP23017_AAA|MCP23017_W);	// адрес устройства + бит записи w
	I2C_SendByte(D);										// отправляем байт данных
	I2C_StopCondition();									// генерация условия СТОП
}

// чтение значения в регистр A-адрес
char MCP23017_read_Register (char A)
{
	char R;
	I2C_StartCondition();									// генерируем условие СТАРТ
	I2C_SendByte(MCP23017_ADDRES|MCP23017_AAA|MCP23017_W);	// адрес устройства + бит записи w
	I2C_SendByte(A);										// отправка Адрес регистра
	I2C_StartCondition();									// генерация условия СТАРТ (РЕСТАРТ)
	I2C_SendByte(MCP23017_ADDRES|MCP23017_AAA|MCP23017_R);	// адрес устройства + бит записи R
	R = I2C_ReadByte();										// Читаем байт данных
	I2C_StopCondition();									// генерация условия СТОП
	return R;
}