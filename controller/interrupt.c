#include "navigate.h"
#include "../device/adc.h"
#include "interrupt.h"

void pit_loop(void)
{
	get_inductance();		  //获取当前电感值
	auto_navigate();		  //PID计算,角度控制
}

