#ifndef SPI_H_
#define SPI_H_
#include "main.h"
// ����� ����������
#define	SS	2
#define	MOSI	3
#define MISO	4
#define SCK	5

// ���� ���������� 
#define SPI_DDR	DDRB
#define	SPI_PORT	PORTB

// ������� ������������� ���� SPI
void SPI_MasterInit(void);

/* ������� �������� ����� ������ outData. ������� ��������� 
�������� � ���������� �������� �� ����� MOSI ����*/
unsigned char SPI_MasterTransmit(char outData);


#endif