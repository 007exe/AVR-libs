#include "spi.h"

// ������� ������������� ���� SPI
void SPI_MasterInit(void){
	SPI_DDR|=(1<<SS)|(1<<MOSI)|(1<<SCK); //
	SPCR = (1<<SPE)|(1<<MSTR); // ��������� SPI, ����� ��������
	SPI_PORT&=~(1<<MOSI);// �������� �����
	SPI_PORT|=(1<<SS);// ��������� �����
}

/* ������� �������� ����� ������ outData. ������� ���������
�������� � ���������� �������� �� ����� MOSI ����*/
unsigned char SPI_MasterTransmit(char outData){
	SPDR = outData; // ������ ��������
	while(!(SPSR & (1<<SPIF))); // �������� ��������� ��������
	return SPDR; // ����������� ��������� �����
}
