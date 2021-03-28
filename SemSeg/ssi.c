/*
Файл реализации библиотеки поразрядной динамической индикации семи сегментного индикатора.
Основные настройки находятся в файле ssi.h
*/
#include "ssi.h"

unsigned char discharge_switch  = 0;
unsigned char units = 0;
unsigned char dozens = 0;
//unsigned char hundreds = 0; // Расскоментировать если необходимы сотни
//unsigned char thousand = 0; // Расскоментировать если необходимы тысячи

void ssi_init (void)
{
    SEG_A_DDR   |=(1<<SEG_A);
    SEG_A_PORT  |=(1<<SEG_A);
    SEG_B_DDR   |=(1<<SEG_B);
    SEG_B_PORT  |=(1<<SEG_B);
    SEG_C_DDR   |=(1<<SEG_C);
    SEG_C_PORT  |=(1<<SEG_C);
    SEG_D_DDR   |=(1<<SEG_D);
    SEG_D_PORT  |=(1<<SEG_D);
    SEG_E_DDR   |=(1<<SEG_E);
    SEG_E_PORT  |=(1<<SEG_E);
    SEG_F_DDR   |=(1<<SEG_F);
    SEG_F_PORT  |=(1<<SEG_F);
    SEG_G_DDR   |=(1<<SEG_G);
    SEG_G_PORT  |=(1<<SEG_G);
/*
    SEG_DP_DDR  |=(1<<SEG_DP); // Расскоментировать если
    SEG_DP_PORT |=(1<<SEG_DP); // необходима точка
*/
    DISCHARGE_UNIT_DDR      |=(1<<DISCHARGE_UNIT);
    DISCHARGE_UNIT_PORT     |=(1<<DISCHARGE_UNIT);
    DISCHARGE_DOZENT_DDR    |=(1<<DISCHARGE_DOZENT);
    DISCHARGE_DOZENT_PORT   |=(1<<DISCHARGE_DOZENT);
/*
    DISCHARGE_HUNDREDS_DDR  |=(1<<DISCHARGE_HUNDREDS);     // Расскоментировать если
    DISCHARGE_HUNDREDS_PORT &=~(1<<DISCHARGE_HUNDREDS);    // необходимы сотни
*/
/*
    DISCHARGE_THOUSANDS_DDR |=(1<<DISCHARGE_THOUSANDS);    // Расскоментировать если
    DISCHARGE_THOUSANDS_PORT |=(1<<DISCHARGE_THOUSANDS);   // необходимы тысячи
*/
}

void segchar (unsigned seg)
{
    switch(seg)
    {
        case 0: {   SEG_A_ON;  SEG_B_ON;   SEG_C_ON;   SEG_D_ON;   SEG_E_ON;   SEG_F_ON;   SEG_G_OFF;  }    break;
        case 1: {   SEG_A_OFF; SEG_B_ON;   SEG_C_ON;   SEG_D_OFF;  SEG_E_OFF;  SEG_F_OFF;  SEG_G_OFF;  }    break;
        case 2: {   SEG_A_ON;  SEG_B_ON;   SEG_C_OFF;  SEG_D_ON;   SEG_E_ON;   SEG_F_OFF;  SEG_G_ON;   }    break;
        case 3: {   SEG_A_ON;  SEG_B_ON;   SEG_C_ON;   SEG_D_ON;   SEG_E_OFF;  SEG_F_OFF;  SEG_G_ON;   }    break;
        case 4: {   SEG_A_OFF; SEG_B_ON;   SEG_C_ON;   SEG_D_OFF;  SEG_E_OFF;  SEG_F_ON;   SEG_G_ON;   }    break;
        case 5: {   SEG_A_ON;  SEG_B_OFF;  SEG_C_ON;   SEG_D_ON;   SEG_E_OFF;  SEG_F_ON;   SEG_G_ON;   }    break;
        case 6: {   SEG_A_ON;  SEG_B_OFF;  SEG_C_ON;   SEG_D_ON;   SEG_E_ON;   SEG_F_ON;   SEG_G_ON;   }    break;
        case 7: {   SEG_A_ON;  SEG_B_ON;   SEG_C_ON;   SEG_D_OFF;  SEG_E_OFF;  SEG_F_OFF;  SEG_G_OFF;  }    break;
        case 8: {   SEG_A_ON;  SEG_B_ON;   SEG_C_ON;   SEG_D_ON;   SEG_E_ON;   SEG_F_ON;   SEG_G_ON;   }    break;
        case 9: {   SEG_A_ON;  SEG_B_ON;   SEG_C_ON;   SEG_D_ON;   SEG_E_OFF;  SEG_F_ON;   SEG_G_ON;   }    break;
    }
}

void ssi_print (unsigned int number)
{
    units = number%10;
    dozens = number/10;
//    hundreds = number/100;  // Расскоментировать если необходимы сотни
//    thousand = number/1000; // Расскоментировать если необходимы тысячи
}

void ssi_digit_position (void)
{
    if (discharge_switch == 0)
    {
//        SEG_DP_OFF;                 // Выключить точку
        DISCHARGE_UNIT_ON;
        DISCHARGE_DOZENT_OFF;
//        DISCHARGE_HUNDREDS_OFF;     // Расскоментировать если необходимы сотни
//        DISCHARGE_THOUSANDS_OFF;    // Расскоментировать если необходимы тысячи
        segchar(units);
    }

    if (discharge_switch == 1)
    {
//        SEG_DP_ON;                  // Включить точку
        DISCHARGE_UNIT_OFF;
        DISCHARGE_DOZENT_ON;
//        DISCHARGE_HUNDREDS_OFF;     // Расскоментировать если необходимы сотни
//        DISCHARGE_THOUSANDS_OFF;    // Расскоментировать если необходимы тысячи
        segchar(dozens);
    }
// Расскоментировать если необходимы сотни
/*
    if (discharge_switch == 2)
    {
//        SEG_DP_OFF;                 // Выключить точку
        DISCHARGE_UNIT_OFF;
        DISCHARGE_DOZENT_OFF;
        DISCHARGE_HUNDREDS_ON;
//        DISCHARGE_THOUSANDS_OFF;    // Расскоментировать если необходимы тысячи
        segchar(hundreds);
    }
*/
// Расскоментировать если необходимы тысячи
/*
    if (discharge_switch == 3)
    {
        SEG_DP_ON;                  // Выключить точку
        DISCHARGE_UNIT_OFF;
        DISCHARGE_DOZENT_OFF;
        DISCHARGE_HUNDREDS_OFF;
        DISCHARGE_THOUSANDS_ON;
        segchar(thousand);
    }
*/
    discharge_switch ++;
// 
    if (discharge_switch > (NUMDIS - 1)) discharge_switch = 0;
}
