#include "ds18b20.h"

uint16_t data = 0; 

int8_t OneWireResetDevice(void)
{
    int8_t temp_stek = SREG;
    cli();
    int8_t check_device;
    OWDDRT |= 1 << OWBIT;
    _delay_us(485);
    OWDDRT &= ~(1 << OWBIT);
    _delay_us(65);
    if((OWPIN & (1 << OWBIT)) == 0x00)
    check_device = 1;
    else check_device = 0;
    SREG=temp_stek;
    _delay_us(500);
    return check_device;
}

void OneWireSendBit(int8_t bit)
{
    int8_t temp_stek = SREG;
    cli();
    OWDDRT |= 1 << OWBIT;
    _delay_us(2);
    if(bit)
    OWDDRT &= ~(1 << OWBIT);
    _delay_us(65);
    OWDDRT &= ~(1 << OWBIT);
    SREG=temp_stek;
}

void OneWireSendByte(uint8_t byte)
{
    for(int8_t i = 0; i < 8; i++)
    {
        if((byte & (1 << i)) == 1<<i)
        OneWireSendBit(1);
        else
        OneWireSendBit(0);
        _delay_us(5);
    }
}

int8_t OneWireReadBit (void)
{
    int8_t temp_stek = SREG;
    cli();
    int8_t bit;
    OWDDRT |= 1 << OWBIT;
    _delay_us(2);
    OWDDRT &= ~(1 << OWBIT);
    _delay_us(13);
    bit = (OWPIN & (1 << OWBIT)) >> OWBIT;
    _delay_us(45);
    SREG = temp_stek;
    return bit;
}

uint8_t OneWireReadByte()
{
    int8_t byte = 0;
    int8_t i;
    for(i = 0; i < 8; i++)
    byte |= OneWireReadBit()<<i;
    return byte;
}

float CheckTemperature(void)
{
    uint8_t lbyte = 0;
    uint16_t hbyte = 0;
    float TermData = 0;
    if(OneWireResetDevice() == 1)
    {
        OneWireSendByte(SKIPID);
        OneWireSendByte(CONVERT);
        _delay_ms(750);
        OneWireResetDevice();
        OneWireSendByte(SKIPID);
        OneWireSendByte(READMEMORY);
        lbyte = OneWireReadByte();
        hbyte = OneWireReadByte();
        data = (hbyte<<8)|lbyte;
    }
    if(data&(1 << 11))
    return TermData = (~(data) + 0b00000001) / 16.0;
    else return TermData = data / 16.0;
}

uint8_t ChecSkign(void)
{
    if(data & (1 << 11)) return 1; else return 0;
}