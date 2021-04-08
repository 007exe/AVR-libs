﻿#include "main.h"

void timer_ini (void)       // Инициализация таймера
{
    TCCR1B |= (1<<WGM12);   // Устанавливаем режим CTC (сброс по совпадению).
    TIMSK  |= (1<<OCIE1A);  // Устанавливаем бит разрешения по прерыванию 1го счётчика по совпадению с OCRE1A (H и L).
    OCR1AH = 0b01111010;    // Запись в регистр для сравнения старшая часть 
    OCR1AL = 0b00010010;    // Запись в регистр для сравнения млатшая часть
    TCCR1B |= (1<<CS10);    // Делитель на 256
}

ISR (TIMER1_COMPA_vect)     // Обработчик прерывания таймера
{
    ssi_digit_position ();
}

int main(void)
{
    timer_ini();            // Вызов инициализации таймера
    ssi_init ();            // Инициализируем библиотеку индикатора
    sei();                  // Разрешаем глобальные прерывания.
    DDRD |=(1 << PD7);
    PORTD &=~(1 << PD7);
    DS_Init (RESOLUTION_12BIT);

    while (1)
    {
        if (ChecSkign() == 0) PORTD &=~(1 << PD7); else PORTD |=(1 << PD7);
        ssi_print(CheckTemperature()/100);
    }
}