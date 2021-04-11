#include "main.h"

void timer_ini (void)
{
    TCCR1B |= (1<<WGM12);
    TIMSK  |= (1<<OCIE1A);
    OCR1AH = 0b01111010;
    OCR1AL = 0b00010010;
    TCCR1B |= (1<<CS10);
}

ISR (TIMER1_COMPA_vect)
{
    ssi_digit_position ();
}

int main(void)
{
    timer_ini();
    ssi_init ();
    sei();
    DDRD |=(1 << PD7);
    PORTD &=~(1 << PD7);

    while (1)
    {
        if (ChecSkign() == 0) PORTD &=~(1 << PD7); else PORTD |=(1 << PD7);
        ssi_print(CheckTemperature()*10);
    }
}