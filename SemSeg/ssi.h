#ifndef SEGCA_H_
#define SEGCA_H_ 
/*
Заголовочный файл библиотеки поразрядной динамической индикации семисегментного индикатора, общие настройки
1) Укажите порт, пин и регистр ввода вывода к которым подключены сегменты индикатора.
2) Библиотека настроенна на использование индикатора с общим анодом и транзисторных ключей n-p-n структуры
если необходимо подключить индикатор с общим катодом или заменить транзисторные ключи на p-n-p то необходимо заменить
в макроопределениях **_ON на **_OFF и **_OFF на **_ON соответственно
3) По умолчанию библиотека настроенна на работу с двумя разрядами, единицы и десятки. Если необходимы сотни и тысячи или только сотни
расскоментируйте все необходимые комментарии в файлах ssi.h и ssi.c и укажите количество разрядов в макросе NUMDIS
Если необходимо большее количество разрядов то их можно реализовать на основе уже имеющихся.
Не рекомендуется использовать более восьми разрядов иначе мерцание индикатора заметно для глаза.
*/

#include "main.h"

#define NUMDIS  2   // Число разрядов

// Макросы для назначения пинов контролера к сегментам индикатора
// Сегмент A
#define SEG_A       PD0         // Пин к которому подключён сегмент А
#define SEG_A_DDR   DDRD        // Регистр ввода вывод к которому подключён сегмент А
#define SEG_A_PORT  PORTD       // Порт к которому подключён сегмент А
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
#define DISCHARGE_UNIT_ON     DISCHARGE_UNIT_PORT   &=~(1<<DISCHARGE_UNIT)
#define DISCHARGE_UNIT_OFF    DISCHARGE_UNIT_PORT   |=(1<<DISCHARGE_UNIT)
// Десятки
#define DISCHARGE_DOZENT      PB1
#define DISCHARGE_DOZENT_DDR  DDRB
#define DISCHARGE_DOZENT_PORT PORTB
#define DISCHARGE_DOZENT_ON   DISCHARGE_DOZENT_PORT &=~(1<<DISCHARGE_DOZENT)
#define DISCHARGE_DOZENT_OFF  DISCHARGE_DOZENT_PORT |=(1<<DISCHARGE_DOZENT)
// Сотни. Расскоментировать если необходимы сотни
/*
#define DISCHARGE_HUNDREDS      PB2
#define DISCHARGE_HUNDREDS_DDR  DDRB
#define DISCHARGE_HUNDREDS_PORT PORTB
#define DISCHARGE_HUNDREDS_ON   DISCHARGE_HUNDREDS_PORT &=~(1<<DISCHARGE_HUNDREDS)
#define DISCHARGE_HUNDREDS_OFF  DISCHARGE_HUNDREDS_PORT |=(1<<DISCHARGE_HUNDREDS)
*/
// Тысячи. Расскоментировать если необходимы тысячи
/*
#define DISCHARGE_THOUSANDS      PB3
#define DISCHARGE_THOUSANDS_DDR  DDRB
#define DISCHARGE_THOUSANDS_PORT PORTB
#define DISCHARGE_THOUSANDS_ON   DISCHARGE_THOUSANDS_PORT &=~(1<<DISCHARGE_THOUSANDS)
#define DISCHARGE_THOUSANDS_OFF  DISCHARGE_THOUSANDS_PORT |=(1<<DISCHARGE_THOUSANDS)
*/

void ssi_init (void);                       // Функция инициализации библиотеки.
void ssi_print (unsigned int number);       // Данной функции передаём целочисленное число и выводим его на печать.
void ssi_digit_position (void);             // Данная функция должна быть вызванна в обработчике прерывания таймера
                                            // настройками таймера можно изменять частоту смены позиции на индикаторе
                                            // тем самым избавиться от мерцания индикатора.
 
#endif
