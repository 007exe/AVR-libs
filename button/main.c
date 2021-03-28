#include "main.h"
#include "button.h"

int main(void){

	DDRD = 0b11111111;  //Настраиваем порт D на выход.
	PORTD = 0b00000000; //Устанавливаем логические нули на всех выходах порта D.
    DDRB = 0b00000000;  //Настраиваем порт B на вход.
    PORTB = 0b11111111; //Включаем подтягивающий резистор на нулевом входе порта B.

    while (1){
        if (button_status(PINB, PINB0) == 0){
            PORTD |=(1 << PD0);
        }
        else{
            PORTD &=~(1 << PD0);
        }
        if (button_status(PINB, PINB1) == 0){
            PORTD |=(1 << PD1);
        }
        else{
            PORTD &=~(1 << PD1);
        }
        if (button_status(PINB, PINB2) == 0){
            PORTD |=(1 << PD2);
        }
        else{
            PORTD &=~(1 << PD2);
        }
        if (button_status(PINB, PINB3) == 0){
            PORTD |=(1 << PD3);
        }
        else{
            PORTD &=~(1 << PD3);
        }
        if (button_status(PINB, PINB4) == 0){
            PORTD |=(1 << PD4);
        }
        else{
            PORTD &=~(1 << PD4);
        }
        if (button_status(PINB, PINB5) == 0){
            PORTD |=(1 << PD5);
        }
        else{
            PORTD &=~(1 << PD5);
        }
        if (button_status(PINB, PINB6) == 0){
            PORTD |=(1 << PD6);
        }
        else{
            PORTD &=~(1 << PD6);
        }
        if (button_status(PINB, PINB7) == 0){
            PORTD |=(1 << PD7);
        }
        else{
            PORTD &=~(1 << PD7);
        }
    }
}
