#include "navigate.h"
#include "../device/adc.h"
#include "interrupt.h"

void pit_loop(void)
{
	get_inductance();		  //��ȡ��ǰ���ֵ
	auto_navigate();		  //PID����,�Ƕȿ���
}

