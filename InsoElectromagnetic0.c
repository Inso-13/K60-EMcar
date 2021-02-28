#include "InsoElectromagnetic0.h"

void main(void)
{
	debug();
	inits();

	while (1)
	{
		oled_print_short(45, 2, left_inductance);
		oled_print_short(45, 5, right_inductance);
		LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, speed + speed_error);
		LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, speed - speed_error + s_parameter.delta_speed);
	}
}
