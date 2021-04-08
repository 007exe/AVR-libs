#include "ds18b20.h"

    uint16_t data = 0;

//функция инициализации устройства на шине
int8_t OneWireResetDevice(void)
{
    int8_t temp_stek = SREG;//сохранить значение стека
    cli();//запретить прерывание
    int8_t check_device;
    DDRTEMP |= 1 << BITTEMP; //притянуть шину
    _delay_us(485);
    DDRTEMP &= ~(1 << BITTEMP);//отпустить шину
    _delay_us(65);
    if((PINTEMP & (1 << BITTEMP)) == 0x00)//проверка наличия устройства на шине
    check_device = 1;//устройство присутствует
    else check_device = 0;//устройства отсутствует
    SREG=temp_stek;//вернуть стек
    _delay_us(500);
    return check_device;
}
 
//функция отправки бита на устройство
void OneWireSendBit(int8_t bit)
{
    int8_t temp_stek = SREG;//сохранить значение стека
    cli();//запретить прерывания
    DDRTEMP |= 1 << BITTEMP; //притянуть шину
    _delay_us(2);
    if(bit)
    DDRTEMP &= ~(1 << BITTEMP);//опустить шину
    _delay_us(65);
    DDRTEMP &= ~(1 << BITTEMP);//отпустить шину
    SREG=temp_stek;//вернуть стек
}
 
//функция отправки байта на устройство
void OneWireSendByte(uint8_t byte)
{
    for(int8_t i = 0; i < 8; i++)
    {
        if((byte & (1 << i)) == 1<<i)// если бит равен 1 то
        OneWireSendBit(1);//послать 1
        else
        OneWireSendBit(0);//послать 0
        _delay_us(5);
    }
}
 
//функция чтения бита с устройства
int8_t OneWireReadBit (void)
{
    int8_t temp_stek = SREG;//сохранить стека
    cli();//запрктить прерывания
    int8_t bit;
    DDRTEMP |= 1 << BITTEMP;//притянуть шину
    _delay_us(2);
    DDRTEMP &= ~(1 << BITTEMP);//отпустить шину
    _delay_us(13);
    bit = (PINTEMP & (1 << BITTEMP)) >> BITTEMP;//читать бит
    _delay_us(45);
    SREG = temp_stek;//вернуть стек
    return bit;
}
 
//функция чтения байта с устройства
uint8_t OneWireReadByte()
{
    int8_t byte = 0;
    int8_t i;
    for(i = 0; i < 8; i++)//цикл чтения байта
    byte |= OneWireReadBit()<<i;//читать каждый бит сдвигая в лево
    return byte;
}
 
//функция измерения и приёма температуры от датчика
uint16_t CheckTemperature(void)
{
    uint8_t lbyte = 0;
    uint16_t hbyte = 0;
    float TermData = 0;
    if(OneWireResetDevice() == 1)//если устройство нашлось
    {
        OneWireSendByte(SKIPID);//комманда пропустить идентификацию
        OneWireSendByte(T_CONVERT);//комманда измерить температуру
        _delay_ms(750);//ждём 750 мили секунд для 12 битного режима (медленно зато точно 0,0625 (1/16) градуса цельсия)
        OneWireResetDevice();//проверить присутствие устройства
        OneWireSendByte(SKIPID);//комманда пропустить идентификацию
        OneWireSendByte(READ_DATA);//комманда передать байты ведущему устройству
        lbyte = OneWireReadByte();//читать младший байт
        hbyte = OneWireReadByte();//читать старший байт
        data = (hbyte<<8)|lbyte;//сдвинуть старший байт влево, младнший байт записать на его место
    }
    if(data&(1 << 11))
    TermData = (~(data) + 0b00000001) * 0.0625;//если температура отрицательная
    else TermData = data * 0.0625;//если температура положительная
    return 1000 * TermData;
}

//функция проверки знака
uint8_t ChecSkign(void)
{
    if(data & (1 << 11)) return 1; else return 0;
}

//функция инициализации датчика установка скорости
void DS_Init (uint8_t RESOLUTION)
{
    OneWireSendByte(SKIPID);//комманда пропустить идентификацию
    OneWireSendByte(RESOLUTION);
}