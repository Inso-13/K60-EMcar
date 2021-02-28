#include "navigate.h"

float X_error_pre;
float X_error;
int16 speed_error;
int16 Speed_out;
int16 Direct_out;
int16 pre_out;
uint32 speed;

void auto_navigate(void)
{
	if (s_parameter.STGY == 2)
	{
		auto_navigate_2();
	}
	else if (s_parameter.STGY == 3)
	{
		auto_navigate_3();
	}
	else
	{
		auto_navigate_1();
	}
}

void auto_navigate_1(void)
{
	float Kp_1 = s_parameter.Kp_1;
	float Kd_1 = s_parameter.Kd_1;

	speed = s_parameter.Vf;

	X_error_pre = X_error; //����ƫ��
	X_error = 1000 * (float)((left_inductance - right_inductance) / ((right_inductance + left_inductance + 1.0);

	if ((X_error * 10) < s_parameter.Kd_LM_1 && (X_error * 10) > -s_parameter.Kd_LM_1) //Kd_LM_1     17(ԭ��Ϊ1.7������int16��ԭ����֮ǰ��10)
	{
		Kd_1 = 0;
	}

	Direct_out = (int16)(Direct_center + Kp_1 * X_error + Kd_1 * (X_error - X_error_pre));

	if (Direct_out > Direct_max)
	{
		Direct_out = Direct_max; //���������
		speed = s_parameter.Vt;
	}
	if (Direct_out < Direct_min)
	{
		Direct_out = Direct_min; //С����С���
		speed = s_parameter.Vt;
	}
	if (left_inductance < s_parameter.Angle_1 || right_inductance < s_parameter.Angle_1)
	{
		if (left_inductance < right_inductance)
		{
			Direct_out = Direct_min; //��ת
		}
		else if (left_inductance > right_inductance)
		{
			Direct_out = Direct_max; //��ת
		}
		else if(!left_inductance)
		{
			Direct_out = Direct_center;
		}
		else
		{
			Direct_out = pre_out; //����ת
		}
		speed = s_parameter.Vt;
	}
	pre_out = Direct_out;

	if (Kd_1 == 0)
	{
		speed_error = 0;
	}
	else if (Direct_out > 735 && Direct_out < 795)
	{
		speed_error = (Direct_out - Direct_center) * s_parameter.Kv_1 * s_parameter.Bucha_1 / 100;
	}
	else
	{
		speed_error = (Direct_out - Direct_center) * s_parameter.Kv_1 / 10;
	}
	// if(Direct_out == Direct_min)
	// {
	// 	speed_error = 1200;
	// }
	// else if(Direct_out == Direct_max)
	// {
	// 	speed_error = -1200;
	// }
	// else
	// {
	// 	speed_error = 0;
	// }
	LPLD_FTM_PWM_ChangeDuty(FTM1, FTM_Ch1, Direct_out);
}

void auto_navigate_2(void)
{
	float Kp_2 = s_parameter.Kp_2;
	float Kd_2 = s_parameter.Kd_2;
	float Ki_2 = s_parameter.Ki_2;

	speed = s_parameter.Vf;

	X_error_pre = X_error; //����ƫ��
	X_error = (float)(left_inductance - right_inductance);
	Direct_out = (int16)(Direct_center + Kp_2 * X_error + Ki_2 * X_error * X_error * X_error + Kd_2 * (X_error - X_error_pre));

	if (Direct_out > Direct_max)
	{
		Direct_out = Direct_max; //���������
		speed = s_parameter.Vt;
	}
	if (Direct_out < Direct_min)
	{
		Direct_out = Direct_min; //С����С���
		speed = s_parameter.Vt;
	}

	LPLD_FTM_PWM_ChangeDuty(FTM1, FTM_Ch1, Direct_out);
}

void auto_navigate_3(void)
{
	float Kp_3 = s_parameter.Kp_3;
	float Kd_3 = s_parameter.Kd_3;
	float Ki_3 = s_parameter.Ki_3;

	speed = s_parameter.Vf;

	X_error_pre = X_error; //����ƫ��
	X_error = (left_inductance * 1.0) / right_inductance;
	Direct_out = (int16)(Direct_center + Kp_3 * X_error + Ki_3 * X_error * X_error * X_error + Kd_3 * (X_error - X_error_pre));

	if (Direct_out > Direct_max)
	{
		Direct_out = Direct_max; //���������
		speed = s_parameter.Vt;
	}
	if (Direct_out < Direct_min)
	{
		Direct_out = Direct_min; //С����С���
		speed = s_parameter.Vt;
	}

	LPLD_FTM_PWM_ChangeDuty(FTM1, FTM_Ch1, Direct_out);
}