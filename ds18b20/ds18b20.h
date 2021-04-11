#ifndef DS18B20_H_
#define DS18B20_H_
 
#include "main.h"
//настройка порта к которому подключён датчик
#define OWDDRT DDRD
#define OWPIN PIND
#define OWBIT PD2

#define SKIPID 0xCC
#define CONVERT 0x44
#define READMEMORY 0xBE

float CheckTemperature(void); //функция проверки температуры
uint8_t ChecSkign(void); //функция проверки знака

#endif