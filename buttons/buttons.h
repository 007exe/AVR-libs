#ifndef BUTTONS_H_
#define BUTTONS_H_ 
#include "main.h"
//макро подстановки для настройки портов и пинов к котором подключены кнопки
#define BUTTON_1		PB0
#define BUTTON_1_PIN	PINB
#define BUTTON_1_DDR	DDRB
#define BUTTON_1_PORT	PORTB

#define BUTTON_2		PB1
#define BUTTON_2_PIN	PINB
#define BUTTON_2_DDR	DDRB
#define BUTTON_2_PORT	PORTB

#define BUTTON_3		PB2
#define BUTTON_3_PIN	PINB
#define BUTTON_3_DDR	DDRB
#define BUTTON_3_PORT	PORTB

void ButtonInit(void);//инициализация кнопок
uint8_t PressButton(uint8_t index);//функция принемает индекс кнопки и возращает его если кнопка нажата
#endif