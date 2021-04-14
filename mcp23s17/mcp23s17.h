#ifndef MCP23S17_H_
#define MCP23S17_H_
#include "main.h"

#define MCP23S17_AAA		0x00
#define MCP23S17_ADDRES		0x40

// флаги чтения записи
#define MCP23S17_W			0x00
#define MCP23S17_R			0x01

// registers
#define MCP23S17_IODIRA		0x00
#define MCP23S17_IOLA		0x02
#define MCP23S17_GPINTENA	0x04
#define MCP23S17_DEFVALA	0x06
#define MCP23S17_INTCONA	0x08
#define MCP23S17_IOCONA		0x0A
#define MCP23S17_GPPUA		0x0C
#define MCP23S17_INTFA		0x0E
#define MCP23S17_INTCAPA	0x10
#define MCP23S17_GPIOA		0x12
#define MCP23S17_OLATA		0x14

#define MCP23S17_IODIRB		0x01
#define MCP23S17_IOLB		0x02
#define MCP23S17_GPINTENB	0x05
#define MCP23S17_DEFVALB	0x07
#define MCP23S17_INTCONB	0x09
#define MCP23S17_IOCONB		0x0B
#define MCP23S17_GPPUB		0x0D
#define MCP23S17_INTFB		0x0F
#define MCP23S17_INTCAPB	0x11
#define MCP23S17_GPIOB		0x13
#define MCP23S17_OLATB		0x15

#define MCP23S17_INT_ERR	255

#define BANK	7
#define MIRROR	6
#define SEQOP	5
#define DISSLW	4
#define HAEN	3
#define ODR		2
#define INTPOL	1
#define Unimplemented	0

// запись значения в регистр А-адрес D-данные
void MCP23S17_write_Register(uint8_t A, uint16_t D);

// чтение значения из регистра A-адрес
uint8_t MCP23S17_read_Register (uint8_t A);

// функции работают при настройке как BANC = 0
#define MCP23S17_DDRA_W(x)	MCP23S17_write_Register(MCP23S17_IODIRA,~x)
#define MCP23S17_DDRA_R		MCP23S17_read_Register(MCP23S17_IODIRA)

#define MCP23S17_PORTA_W(x)	MCP23S17_write_Register(MCP23S17_IOLA,x)
#define MCP23S17_PORTA_R	MCP23S17_read_Register(MCP23S17_OLATA)

#define MCP23S17_PINA_R		MCP23S17_read_Register(MCP23S17_GPIOA)

#define MCP23S17_PUDA_W(x)	MCP23S17_write_Register(MCP23S17_GPPUA,x)
#define MCP23S17_PUDA_R		MCP23S17_read_Register(MCP23S17_GPPUA)


#define MCP23S17_DDRB_W(x)	MCP23S17_write_Register(MCP23S17_IODIRB,~x)
#define MCP23S17_DDRB_R		MCP23S17_read_Register(MCP23S17_IODIRB)

#define MCP23S17_PORTB_W(x)	MCP23S17_write_Register(MCP23S17_IOLB,x)
#define MCP23S17_PORTB_R	MCP23S17_read_Register(MCP23S17_OLATB)

#define MCP23S17_PINB_R		MCP23S17_read_Register(MCP23S17_GPIOB)

#define MCP23S17_PUDB_W(x)	MCP23S17_write_Register(MCP23S17_GPPUB,x)
#define MCP23S17_PUDB_R		MCP23S17_read_Register(MCP23S17_GPPUB)

#endif
