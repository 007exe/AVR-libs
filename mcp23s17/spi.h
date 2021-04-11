#ifndef SPI_H_
#define SPI_H_
#include "main.h"
// Ножки интерфейса
#define	SS	2
#define	MOSI	3
#define MISO	4
#define SCK	5

// порт интерфейса 
#define SPI_DDR	DDRB
#define	SPI_PORT	PORTB

// Функция инициализации шины SPI
void SPI_MasterInit(void);

/* Функция передачи байта данных outData. Ожидает окончания 
передачи и возврашает принятый по ножке MOSI байт*/
unsigned char SPI_MasterTransmit(char outData);


#endif