#include "buttons.h"

void ButtonInit(void)
{
	BUTTON_1_DDR &=~(1 << BUTTON_1);
	BUTTON_2_DDR &=~(1 << BUTTON_2);
	BUTTON_3_DDR &=~(1 << BUTTON_3);
	BUTTON_1_PORT |=(1 << BUTTON_1);
	BUTTON_2_PORT |=(1 << BUTTON_2);
	BUTTON_3_PORT |=(1 << BUTTON_3);
}

uint8_t PressButton (uint8_t index)
{
	uint8_t result=0, butcount=0, butstate=0;
	
	switch(index)
	{
		case 1:
			while (butstate==0)
			{
				if(!(BUTTON_1_PIN&(1<<BUTTON_1)))
				{
					if(butcount < 5) butcount++;
					else
					{
						result = 1;
						butstate=1;
					}
				}
				else
				{
					if(butcount > 0) butcount--;
					else butstate=1;
				}
			}
		break;
		case 2:
			while (butstate==0)
			{
				if(!(BUTTON_2_PIN&(1<<BUTTON_2)))
				{
					if(butcount < 5) butcount++;
					else
					{
						result = 2;
						butstate=1;
					}
				}
				else
				{
					if(butcount > 0) butcount--;
					else butstate=1;
				}
			}
		break;
		case 3:
			while (butstate==0)
			{
				if(!(BUTTON_3_PIN&(1<<BUTTON_3)))
				{
					if(butcount < 5) butcount++;
					else
					{
						result = 3;
						butstate=1;
					}
				}
				else
				{
					if(butcount > 0) butcount--;
					else butstate=1;
				}
			}
		break;
	}
	return result;
}