#include "../device/flash.h"
#include "../device/oled.h"
#include "../device/button.h"
#include "../device/inits.h"
#include "debug.h"

void debug()
{
	uint8 key = 0;

	DisableInterrupts;
	flash_init();
	button_init();
	oled_init();

	flash_read();
	oled_fill(0x00);
	param_load(&s_parameter);
	EnableInterrupts;

	oled_display_16x8str(5, 2, "CENTER to Debug");
	oled_display_16x8str(5, 4, "UP");
	oled_display_16x8str(61, 4,"to Run");

	while (1)
	{
		key = button_scan();
		switch (key)
		{
			case BT_OK_PRESS: //调整参数
				oled_fill(0x00);
				param_set();
				oled_fill(0x00);
				oled_display_16x8str(5, 2, "CENTER to Debug");
				oled_display_16x8str(5, 4, "UP");
				oled_display_16x8str(61, 4,"to Run");
				break;
			case BT_UP_PRESS: //退出
				oled_fill(0x00);
				return;
		}
	}
}

void debug_delay(uint16 n)
{
	uint16 i;
	while (n--)
	{
		for (i = 0; i < 5000; i++)
		{
			asm("nop");
		}
	}
}