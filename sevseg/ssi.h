#ifndef SEGCA_H_
#define SEGCA_H_ 
/*
Заголовочный файл библиотеки поразрядной динамической индикации семисегментного индикатора, общие настройки
    1) Скопируйте в свой проект файлы ssi.c и ssi.h.
    2) Подключите заголовочный файл к своему проекту.
    3) В ssi.h укажите порт, пин и регистр ввода вывода к которым подключены сегменты индикатора.
    4) Библиотека настроенна на использование индикатора с общим анодом и транзисторных ключей p-n-p структуры,
    если необходимо подключить индикатор с общим катодом или заменить транзисторные ключи на n-p-n то необходимо 
    заменить в ssi.h макроопределения SEG_***_ON на SEG_***_OFF и SEG_***_OFF на SEG_***_ON соответственно для 
    индикатора с общим катодом. DISCHARGE_***_ON на DISCHARGE_***_OFF и DISCHARGE_***_OFF на DISCHARGE_***_ON 
    соответственно для n-p-n транзисторов.
    5) По умолчанию библиотека настроенна на работу с двумя разрядами, единицы и десятки. Если необходимы сотни и 
    тысячи или только сотни расскоментируйте все необходимые комментарии в файлах ssi.h и ssi.c и укажите количество 
    разрядов в макросе NUMDIS.
    Если необходимо большее количество разрядов то их можно реализовать на основе уже имеющихся.
    !!! Не рекомендуется использовать более восьми разрядов иначе мерцание индикатора заметно для глаза.
    6) Вызовите функцию SSI_Init () для инициализации.
    7) В вашем проекте настройте таймер и в его обработчике прерывания вызовите функцию SSI_DigitPosition ()
    Настройкой таймера можно подобрать частоту смены разрядов тем самым уменьшив моргание индикатора.
    8) Для вывода информации на индикатор вызовите функцию SSI_Print () передав ей переменную типа uint16_t или 
    просто запишите любое число ssi_print (11)
*/

#include "main.h"

#define NUMDIS  2//Число разрядов

// Макросы для назначения пинов контролера к сегментам индикатора
// Сегмент A
#define SEG_A       PD0//Пин к которому подключён сегмент А
#define SEG_A_DDR   DDRD//Регистр ввода вывод к которому подключён сегмент А
#define SEG_A_PORT  PORTD//Порт к которому подключён сегмент А
#define SEG_A_ON    SEG_A_PORT  &=~(1<<SEG_A)
#define SEG_A_OFF   SEG_A_PORT  |=(1<< SEG_A)
// Сегмент B
#define SEG_B       PD1
#define SEG_B_DDR   DDRD
#define SEG_B_PORT  PORTD
#define SEG_B_ON    SEG_B_PORT  &=~(1<<SEG_B)
#define SEG_B_OFF   SEG_B_PORT  |=(1<< SEG_B)
// Сегмент C
#define SEG_C       PD2
#define SEG_C_DDR   DDRD
#define SEG_C_PORT  PORTD
#define SEG_C_ON    SEG_C_PORT  &=~(1<<SEG_C)
#define SEG_C_OFF   SEG_C_PORT  |=(1<< SEG_C)
// Сегмент D
#define SEG_D       PD3
#define SEG_D_DDR   DDRD
#define SEG_D_PORT  PORTD
#define SEG_D_ON    SEG_D_PORT  &=~(1<<SEG_D)
#define SEG_D_OFF   SEG_D_PORT  |=(1<< SEG_D)
// Сегмент E
#define SEG_E       PD4
#define SEG_E_DDR   DDRD
#define SEG_E_PORT  PORTD
#define SEG_E_ON    SEG_E_PORT  &=~(1<<SEG_E)
#define SEG_E_OFF   SEG_E_PORT  |=(1<< SEG_E)
// Сегмент F
#define SEG_F       PD5
#define SEG_F_DDR   DDRD
#define SEG_F_PORT  PORTD
#define SEG_F_ON    SEG_F_PORT  &=~(1<<SEG_F)
#define SEG_F_OFF   SEG_F_PORT  |=1<< SEG_F
// Сегмент G
#define SEG_G       PD6
#define SEG_G_DDR   DDRD
#define SEG_G_PORT  PORTD
#define SEG_G_ON    SEG_G_PORT  &=~(1<<SEG_G)
#define SEG_G_OFF   SEG_G_PORT  |=(1<< SEG_G)
// Точка Сегмент DP. Расскоментировать если необходима точка
/*
#define SEG_DP       PD7
#define SEG_DP_DDR   DDRD
#define SEG_DP_PORT  PORTD
#define SEG_DP_ON   SEG_DP_PORT &=~(1<<SEG_DP)
#define SEG_DP_OFF  SEG_DP_PORT |=(1<< SEG_DP)
*/
// Макросы для назначения пинов контролера к разрядам индикатора
// Единицы
#define DISCHARGE_UNIT        PB0
#define DISCHARGE_UNIT_DDR    DDRB
#define DISCHARGE_UNIT_PORT   PORTB
#define DISCHARGE_UNIT_OFF    DISCHARGE_UNIT_PORT   &=~(1<<DISCHARGE_UNIT)
#define DISCHARGE_UNIT_ON     DISCHARGE_UNIT_PORT   |=(1<<DISCHARGE_UNIT)
// Десятки
#define DISCHARGE_DOZENT      PB1
#define DISCHARGE_DOZENT_DDR  DDRB
#define DISCHARGE_DOZENT_PORT PORTB
#define DISCHARGE_DOZENT_OFF  DISCHARGE_DOZENT_PORT &=~(1<<DISCHARGE_DOZENT)
#define DISCHARGE_DOZENT_ON   DISCHARGE_DOZENT_PORT |=(1<<DISCHARGE_DOZENT)
// Сотни. Расскоментировать если необходимы сотни
/*
#define DISCHARGE_HUNDREDS      PB2
#define DISCHARGE_HUNDREDS_DDR  DDRB
#define DISCHARGE_HUNDREDS_PORT PORTB
#define DISCHARGE_HUNDREDS_OFF  DISCHARGE_HUNDREDS_PORT &=~(1<<DISCHARGE_HUNDREDS)
#define DISCHARGE_HUNDREDS_ON   DISCHARGE_HUNDREDS_PORT |=(1<<DISCHARGE_HUNDREDS)
*/
// Тысячи. Расскоментировать если необходимы тысячи
/*
#define DISCHARGE_THOUSANDS      PB3
#define DISCHARGE_THOUSANDS_DDR  DDRB
#define DISCHARGE_THOUSANDS_PORT PORTB
#define DISCHARGE_THOUSANDS_OFF   DISCHARGE_THOUSANDS_PORT &=~(1<<DISCHARGE_THOUSANDS)
#define DISCHARGE_THOUSANDS_ON  DISCHARGE_THOUSANDS_PORT |=(1<<DISCHARGE_THOUSANDS)
*/

void SSI_Init (void);//функция инициализации библиотеки.
void SSI_Print (uint16_t number);//функция вывода числа на индикатор.
void SSI_DigitPosition(void);//функция переключения позиции разрядов вызывается в обработчике прерывания
 
#endif
