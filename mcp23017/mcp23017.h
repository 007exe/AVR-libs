#ifndef MCP23017_H_
#define MCP23017_H_
#include "main.h"

#define MCP23017_AAA		0x00
#define MCP23017_ADDRES		0x40

// флаги чтения записи
#define MCP23017_W			0x00
#define MCP23017_R			0x01

// registers
#define MCP23017_IODIRA		0x00
#define MCP23017_IOLA		0x02
#define MCP23017_GPINTENA	0x04
#define MCP23017_DEFVALA	0x06
#define MCP23017_INTCONA	0x08
#define MCP23017_IOCONA		0x0A
#define MCP23017_GPPUA		0x0C
#define MCP23017_INTFA		0x0E
#define MCP23017_INTCAPA	0x10
#define MCP23017_GPIOA		0x12
#define MCP23017_OLATA		0x14

#define MCP23017_IODIRB		0x01
#define MCP23017_IOLB		0x02
#define MCP23017_GPINTENB	0x05
#define MCP23017_DEFVALB	0x07
#define MCP23017_INTCONB	0x09
#define MCP23017_IOCONB		0x0B
#define MCP23017_GPPUB		0x0D
#define MCP23017_INTFB		0x0F
#define MCP23017_INTCAPB	0x11
#define MCP23017_GPIOB		0x13
#define MCP23017_OLATB		0x15

#define MCP23017_INT_ERR	255

#define BANK	7
#define MIRROR	6
#define SEQOP	5
#define DISSLW	4
#define HAEN	3
#define ODR		2
#define INTPOL	1
#define Unimplemented	0

// запись значения врегистр А-адрес D-данные
void MCP23017_write_Register(char A, char D);

// чтение значения в регистр A-адрес
char MCP23017_read_Register (char A);

// Функции работают при настройке как BANC = 0
#define MCP23017_DDRA_W(x)	MCP23017_write_Register(MCP23017_IODIRA, ~x)
#define MCP23017_DDRA_R		MCP23017_read_Register(MCP23017_IODIRA)

#define MCP23017_PORTA_W(x)	MCP23017_write_Register(MCP23017_IOLA,x)
#define MCP23017_PORTA_R	MCP23017_read_Register(MCP23017_OLATA)

#define MCP23017_PINA_R		MCP23017_read_Register(MCP23017_GPIOA)

#define MCP23017_PUDA_W(x)	MCP23017_write_Register(MCP23017_GPPUA,x)
#define MCP23017_PUDA_R		MCP23017_read_Register(MCP23017_GPPUA)


#define MCP23017_DDRB_W(x)	MCP23017_write_Register(MCP23017_IODIRB, ~x)
#define MCP23017_DDRB_R		MCP23017_read_Register(MCP23017_IODIRB)

#define MCP23017_PORTB_W(x)	MCP23017_write_Register(MCP23017_IOLB,x)
#define MCP23017_PORTB_R	MCP23017_read_Register(MCP23017_OLATB)

#define MCP23017_PINB_R		MCP23017_read_Register(MCP23017_GPIOB)

#define MCP23017_PUDB_W(x)	MCP23017_write_Register(MCP23017_GPPUB,x)
#define MCP23017_PUDB_R		MCP23017_read_Register(MCP23017_GPPUB)

#endif
