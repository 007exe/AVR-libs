#include "button.h"

unsigned char status_button = 0;

unsigned char button_status (unsigned char PINx, unsigned char PINxn){
    if ((1 << PINxn) & PINx){
        status_button = 1;
    }
    else{
        status_button = 0;
    }
return status_button;
}