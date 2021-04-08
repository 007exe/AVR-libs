#ifndef DS18B20_H_
#define DS18B20_H_
 
#include "main.h"

#define PORTTEMP PORTD
#define DDRTEMP DDRD
#define PINTEMP PIND
#define BITTEMP 2

#define SKIPID 0xCC //команда пропустить индентификацию
#define T_CONVERT 0x44 //команда измерения температуры
#define READ_DATA 0xBE //команда передать байты

#define RESOLUTION_9BIT 0x1F //разрешение преобразования 9 бит - 0,5 (1/2)
#define RESOLUTION_10BIT 0x3F //разрешение преобразования 10 бит - 0,25 (1/4)
#define RESOLUTION_11BIT 0x5F //разрешение преобразования 11 бит - 0,125 (1/8)
#define RESOLUTION_12BIT 0x7F //разрешение преобразования 12 бит - 0,0625 (1/16) (по умолчанию)

void DS_Init (uint8_t RESOLUTION);
uint16_t CheckTemperature(void);
uint8_t ChecSkign(void);

#endif