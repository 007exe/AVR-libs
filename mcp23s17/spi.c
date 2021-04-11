#include "spi.h"

// Функция инициализации шины SPI
void SPI_MasterInit(void){
	SPI_DDR|=(1<<SS)|(1<<MOSI)|(1<<SCK); //
	SPCR = (1<<SPE)|(1<<MSTR); // Включение SPI, режиа ведущего
	SPI_PORT&=~(1<<MOSI);// опускаем линию
	SPI_PORT|=(1<<SS);// поднимаем линию
}

/* Функция передачи байта данных outData. Ожидает окончания
передачи и возврашает принятый по ножке MOSI байт*/
unsigned char SPI_MasterTransmit(char outData){
	SPDR = outData; // начало передачи
	while(!(SPSR & (1<<SPIF))); // ожидание окончания передачи
	return SPDR; // возвращение принятого байта
}
