﻿#include "main.h"

void timer_ini (void)       // Инициализация таймера
{
    TCCR1B |= (1<<WGM12);   // Устанавливаем режим CTC (сброс по совпадению).
    TIMSK  |= (1<<OCIE1A);  // Устанавливаем бит разрешения по прерыванию 1го счётчика по совпадению с OCRE1A (H и L).
    OCR1AH = 0b01111010;    // Запись в регистр для сравнения старшая часть 
    OCR1AL = 0b00010010;    // Запись в регистр для сравнения млатшая часть
    TCCR1B |= (1<<CS11);    // Устанавливаем делитель
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

    while (1)
    {
        for (int i=0; i<99; i++)
        {
            _delay_ms(300);
            ssi_print(i);   // Вызываем функцию для вывода на LED дисплей
        }
    }
}
