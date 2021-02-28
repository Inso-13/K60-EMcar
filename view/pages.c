#include "common.h"
#include "../device/oled.h"
#include "../device/button.h"
#include "../model/params.h"
#include "pages.h"
//��һҳ
uint8 set_page_first()
{
	uint8 page_num = PAGE_MIN;
	int8 exit_flag = 0;
	int8 button_value = 0;

	oled_fill(0x00);
	oled_display_16x8str(16, 1, "HUST-Smartcar");
	oled_display_16x8str(44, 3, "2020");
	oled_display_16x8str(30, 5, "Group 5");

	while (!exit_flag)
	{
		button_value = button_scan();

		switch (button_value)
		{
		case BT_UP_PRESS:
			break;
		case BT_DN_PRESS:
			break;
		case BT_RI_PRESS:
			page_num++;
			exit_flag = 1;
			break;
		case BT_LE_PRESS:
			page_num = PAGE_MAX;
			exit_flag = 1;
			break;
		default:
			break;
		}
	}

	return page_num;
}

//ȷ���޸Ĳ���ҳ
uint8 set_page_ent(PARAM *p_param)
{
	uint8 page_num = (PAGE_MAX - 1);
	int8 exit_flag = 0;
	int8 button_value = 0;
	int8 display_flag = 0;

	oled_fill(0x00);
	oled_display_16x8str(5, 1, "Save Changes?");

	while (!exit_flag)
	{
		if (display_flag == 1)
		{
			oled_display_16x8str(5, 5, "Succeed");
			display_flag = 0;
		}
		button_value = button_scan();

		switch (button_value)
		{
		case BT_UP_PRESS:
			break;
		case BT_DN_PRESS:
			break;
		case BT_RI_PRESS:
			page_num++;
			exit_flag = 1;
			break;
		case BT_LE_PRESS:
			page_num--;
			exit_flag = 1;
			break;
		case BT_OK_PRESS:
			param_save(p_param);
			display_flag = 1;
			break;
		default:
			break;
		}
	}

	return page_num;
}

//�������һҳ�����˳�����ҳ
uint8 set_page_last()
{
	uint8 page_num = PAGE_MAX;
	int8 exit_flag = 0;
	int8 button_value = 0;

	oled_fill(0x00);
	oled_display_16x8str(45, 3, "Exit?");

	while (!exit_flag)
	{
		button_value = button_scan();

		switch (button_value)
		{
		case BT_UP_PRESS:
			break;
		case BT_DN_PRESS:
			break;
		case BT_RI_PRESS:
			page_num = PAGE_MIN;
			exit_flag = 1;
			break;
		case BT_LE_PRESS:
			page_num--;
			exit_flag = 1;
			break;
		case BT_OK_PRESS:
			page_num = EXIT_SET;
			exit_flag = 1;
			break;
		default:
			break;
		}
	}

	return page_num;
}

//��ͬ���Բ���ҳ��ʹ��16x8���ַ�
uint8 set_page_16x8common(char *pstr_a, int16 *param_a,
						  char *pstr_b, int16 *param_b,
						  char *pstr_c, int16 *param_c,
						  char *pstr_d, int16 *param_d,
						  uint8 page_num)
{

	int8 head_num = 1;
	int8 bits_num = 1;
	int8 exit_flag = 0;
	int8 button_value = 0;
	int8 set_flag = 0;

	char pstr[4][20];
	int16 param[4];

	param[0] = *param_a;
	param[1] = *param_b;
	param[2] = *param_c;
	param[3] = *param_d;

	strcpy((int8 *)pstr[0], (int8 *)pstr_a);
	strcpy((int8 *)pstr[1], (int8 *)pstr_b);
	strcpy((int8 *)pstr[2], (int8 *)pstr_c);
	strcpy((int8 *)pstr[3], (int8 *)pstr_d);

	oled_fill(0x00);
	oled_display_16x8str(0, 0, pstr[0]);
	oled_print_16x8short(80, 0, param[0]);
	oled_display_16x8str(0, 2, pstr[1]);
	oled_print_16x8short(80, 2, param[1]);
	oled_display_16x8str(0, 4, pstr[2]);
	oled_print_16x8short(80, 4, param[2]);
	oled_display_16x8str(0, 6, pstr[3]);
	oled_print_16x8short(80, 6, param[3]);

	oled_display_16x8str_hl(0, 2 * (head_num - 1), pstr[head_num - 1]);

	while (!exit_flag)
	{

		button_value = button_scan();

		if (set_flag == 0)
		{
			switch (button_value)
			{
			case BT_UP_PRESS:
				oled_display_16x8str(0, 2 * (head_num - 1), pstr[head_num - 1]); //�ϴ�ѡ�в˵�ȥ��������ʾ
				if (head_num > 1)
				{
					head_num--; //������ǵ�һ���������ƶ�
				}
				else
				{
					head_num = 4; //����ǵ�һ�����ƶ������һ��
				}
				oled_display_16x8str_hl(0, 2 * (head_num - 1), pstr[head_num - 1]); //����ѡ�в˵����ӷ�����ʾ
				break;
			case BT_DN_PRESS:
				oled_display_16x8str(0, 2 * (head_num - 1), pstr[head_num - 1]); //�ϴ�ѡ�в˵�ȥ��������ʾ
				if (head_num < 4)
				{
					head_num++; //����������һ���������ƶ�
				}
				else
				{
					head_num = 1; //��������һ�����ƶ�����һ��
				}
				oled_display_16x8str_hl(0, 2 * (head_num - 1), pstr[head_num - 1]); //����ѡ�в˵����ӷ�����ʾ
				break;
			case BT_LE_PRESS:
				page_num--; //�л�����һҳ
				exit_flag = 1;
				break;
			case BT_RI_PRESS:
				page_num++; //�л�����һҳ
				exit_flag = 1;
				break;
			case BT_OK_PRESS:
				oled_display_16x8str(0, 2 * (head_num - 1), pstr[head_num - 1]); //ȥ���˵����ķ�����ʾ
				bits_num = 1;
				oled_print_16x8short_hl(80, 2 * (head_num - 1), param[head_num - 1], bits_num);
				set_flag = 1; //����ȷ�ϼ�����༭ģʽ
				break;
			default:
				break;
			}
		}
		else if (set_flag == 1) //����༭ģʽ
		{
			switch (button_value)
			{
			case BT_LE_PRESS:
				if (bits_num > 1)
				{
					bits_num--;
				}
				else
				{
					bits_num = 5;
				}
				oled_print_16x8short_hl(80, 2 * (head_num - 1), param[head_num - 1], bits_num);
				break;
			case BT_RI_PRESS:
				if (bits_num < 5)
				{
					bits_num++;
				}
				else
				{
					bits_num = 1;
				}
				oled_print_16x8short_hl(80, 2 * (head_num - 1), param[head_num - 1], bits_num);
				break;
			case BT_UP_PRESS:
				switch (bits_num)
				{
				case 1:
					param[head_num - 1] += 10000;
					break;
				case 2:
					param[head_num - 1] += 1000;
					break;
				case 3:
					param[head_num - 1] += 100;
					break;
				case 4:
					param[head_num - 1] += 10;
					break;
				case 5:
					param[head_num - 1] += 1;
					break;
				default:
					break;
				}
				oled_print_16x8short_hl(80, 2 * (head_num - 1), param[head_num - 1], bits_num);
				break;
			case BT_DN_PRESS:
				switch (bits_num)
				{
				case 1:
					param[head_num - 1] -= 10000;
					break;
				case 2:
					param[head_num - 1] -= 1000;
					break;
				case 3:
					param[head_num - 1] -= 100;
					break;
				case 4:
					param[head_num - 1] -= 10;
					break;
				case 5:
					param[head_num - 1] -= 1;
					break;
				default:
					break;
				}
				oled_print_16x8short_hl(80, 2 * (head_num - 1), param[head_num - 1], bits_num);
				break;
			case BT_OK_PRESS:
				oled_print_16x8short(80, 2 * (head_num - 1), param[head_num - 1]);
				oled_display_16x8str_hl(0, 2 * (head_num - 1), pstr[head_num - 1]);
				set_flag = 0; //����ȷ�ϼ��˳��༭ģʽ
				break;
			default:
				break;
			}
		}
	}
	oled_fill(0x00);
	*param_a = param[0];
	*param_b = param[1];
	*param_c = param[2];
	*param_d = param[3];

	strcpy((int8 *)pstr_a, (int8 *)pstr[0]);
	strcpy((int8 *)pstr_b, (int8 *)pstr[1]);
	strcpy((int8 *)pstr_c, (int8 *)pstr[2]);
	strcpy((int8 *)pstr_d, (int8 *)pstr[3]);

	return page_num;
}

//page1
uint8 set_page_1()
{
	return set_page_first();
}

//page2
uint8 set_page_2(PARAM *p_param)
{
	return set_page_16x8common("Kp_1", &(p_param->Kp_1),
							   "Kd_1", &(p_param->Kd_1),
							   "Vf", &(p_param->Vf),
							   "Vt", &(p_param->Vt),
							   2);
}

//page3
uint8 set_page_3(PARAM *p_param)
{
	return set_page_16x8common(
		"Angle_1", &(p_param->Angle_1),
		"Kd_LM_1", &(p_param->Kd_LM_1),
		"Kv_1", &(p_param->Kv_1),
		"Dif_V_1", &(p_param->Dif_V_1),
		3);
}

//page4
uint8 set_page_4(PARAM *p_param)
{
	return set_page_16x8common(
		"Bucha_1", &(p_param->Bucha_1),
		"Ki_2", &(p_param->Ki_2),
		"Kp_2", &(p_param->Kp_2),
		"Kd_2", &(p_param->Kd_2),
		4);
}

//page5
uint8 set_page_5(PARAM *p_param)
{
	return set_page_16x8common(
		"Ki_3", &(p_param->Ki_3),
		"Kp_3", &(p_param->Kp_3),
		"Kd_3", &(p_param->Kd_3),
		"STGY", &(p_param->STGY),
		5);
}

//page6
uint8 set_page_6(PARAM *p_param)
{
	return set_page_16x8common(
		"delta_speed", &(p_param->delta_speed),
		"null_5_1", &(p_param->null_5_1),
		"Lbalance", &(p_param->Lbalance),
		"center", &(p_param->center),
		6);
}

//page7
uint8 set_page_7(PARAM *p_param)
{
	return set_page_ent(p_param);
}

//page8
uint8 set_page_8()
{
	return set_page_last();
}