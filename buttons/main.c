#include "main.h"

int main(void){

	ButtonInit();//инициализация кнопок

	DDRD |= (1 << PD5)|(1 << PD6)|(1 << PD7);//Пятый, шестой и седьмой пин порта D на выход
	PORTD &=~(1 << PD5)&(1 << PD6)&(1 << PD7);//Низкий уровень на пятом, шестом и седьмом пине порта D

    while (1)
	{
		if(PressButton(1)==1) PORTD |=(1<<PD5); else PORTD &=~(1 << PD5);//Проверка первой кнопи за индексом 1
		if(PressButton(2)==2) PORTD |=(1<<PD6); else PORTD &=~(1 << PD6);//Проверка второй кнопи за индексом 2
		if(PressButton(3)==3) PORTD |=(1<<PD7); else PORTD &=~(1 << PD7);//Проверка третьей кнопи за индексом 3
    }
}
