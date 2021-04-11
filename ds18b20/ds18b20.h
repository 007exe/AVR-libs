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

float CheckTemperature(void);
uint8_t ChecSkign(void);

#endif