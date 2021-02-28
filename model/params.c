#include "../device/flash.h"
#include "../device/button.h"
#include "../view/pages.h"
#include "params.h"

PARAM s_parameter;
extern FlashDataType g_flashDataBuffer[FLASH_BUFFER_SIZE];

//��flash���������
void param_load(PARAM *p_param)
{
	flash_read();
	p_param->Kp_1 = (int16)g_flashDataBuffer[0];
	p_param->Kd_1 = (int16)g_flashDataBuffer[1];
	p_param->Vf = (int16)g_flashDataBuffer[2];
	p_param->Vt = (int16)g_flashDataBuffer[3];
	p_param->Angle_1 = (int16)g_flashDataBuffer[4];
	p_param->Kd_LM_1 = (int16)g_flashDataBuffer[5];
	p_param->Kv_1 = (int16)g_flashDataBuffer[6];
	p_param->Dif_V_1 = (int16)g_flashDataBuffer[7];
	p_param->Bucha_1 = (int16)g_flashDataBuffer[8];
	p_param->Ki_2 = (int16)g_flashDataBuffer[9];
	p_param->Kp_2 = (int16)g_flashDataBuffer[10];
	p_param->Kd_2 = (int16)g_flashDataBuffer[11];
	p_param->Ki_3 = (int16)g_flashDataBuffer[12];
	p_param->Kp_3 = (int16)g_flashDataBuffer[13];
	p_param->Kd_3 = (int16)g_flashDataBuffer[14];
	p_param->STGY = (int16)g_flashDataBuffer[15];
	p_param->delta_speed = (int16)g_flashDataBuffer[16];
	p_param->null_5_1 = (int16)g_flashDataBuffer[17];
	p_param->Lbalance = (int16)g_flashDataBuffer[18];
	p_param->center = (int16)g_flashDataBuffer[19];
	p_param->param_flag = (int16)g_flashDataBuffer[20];
	p_param->param_enable = (int16)g_flashDataBuffer[21];
}

//������飬�����趨��Χ���޷�����
void param_check(PARAM *p_param)
{
	//	if(p_param->Kp_1 <0)
	//	{
	//        p_param->Kp_1 = 0;
	//	}
	//	else if(p_param->Kp_1 > 300)
	//	{
	//		p_param->Kp_1 = 300;
	//	}
	//
	//	if(p_param->Kd_1 < 0)
	//	{
	//		p_param->Kd_1 = 0;
	//	}
	//	else if(p_param->Kd_1 > 1000)
	//	{
	//		p_param->Kd_1 = 1000;
	//	}

	if (p_param->Kv_1 < 10)
	{
		p_param->Kv_1 = 10;
	}
	else if (p_param->Kv_1 > 450)
	{
		p_param->Kv_1 = 450;
	}

	//	if(p_param->Vf < 0)
	//	{
	//		p_param->Vf = 0;
	//	}
	//	else if(p_param->Vf > 2000)
	//	{
	//		p_param->Vf = 2000;
	//	}
	//
	//	if(p_param->Vt < 0)
	//	{
	//		p_param->Vt = 0;
	//	}
	//	else if(p_param->Vt > 1000)
	//	{
	//		p_param->Vt = 1000;
	//	}

	else if (p_param->Angle_1 > 400)
	{
		p_param->Angle_1 = 400;
	}

	if (p_param->Kd_LM_1 > 200)
	{
		p_param->Kd_LM_1 = 200;
	}
	else if (p_param->Kd_LM_1 > 380)
	{
		p_param->Kd_LM_1 = 380;
	}
}

//�������棬��������д��flash
void param_save(PARAM *p_param)
{
	//flash_erase(0);
	//param_check(p_param);
	g_flashDataBuffer[0] = p_param->Kp_1;
	g_flashDataBuffer[1] = p_param->Kd_1;
	g_flashDataBuffer[2] = p_param->Vf;
	g_flashDataBuffer[3] = p_param->Vt;
	g_flashDataBuffer[4] = p_param->Angle_1;
	g_flashDataBuffer[5] = p_param->Kd_LM_1;
	g_flashDataBuffer[6] = p_param->Kv_1;
	g_flashDataBuffer[7] = p_param->Dif_V_1;
	g_flashDataBuffer[8] = p_param->Bucha_1;
	g_flashDataBuffer[9] = p_param->Ki_2;
	g_flashDataBuffer[10] = p_param->Kp_2;
	g_flashDataBuffer[11] = p_param->Kd_2;
	g_flashDataBuffer[12] = p_param->Ki_3;
	g_flashDataBuffer[13] = p_param->Kp_3;
	g_flashDataBuffer[14] = p_param->Kd_3;
	g_flashDataBuffer[15] = p_param->STGY;
	g_flashDataBuffer[16] = p_param->delta_speed;
	g_flashDataBuffer[17] = p_param->null_5_1;
	g_flashDataBuffer[18] = p_param->Lbalance;
	g_flashDataBuffer[19] = p_param->center;
	g_flashDataBuffer[20] = p_param->param_flag;
	g_flashDataBuffer[21] = p_param->param_enable;
	flash_write();
}

//������ʼ���������flash���������������Ϊ��̻�����ԭ���ƻ�������
//p_param->param_flag != PARAM_INIT_FLAG �����һ�γ�ʼ��
void param_init(PARAM *p_param)
{
	if (p_param->param_flag != PARAM_INIT_FLAG)
	{
		p_param->Kp_1 = PARAM_INIT_Kp_1;
		p_param->Kd_1 = PARAM_INIT_Kd_1;
		p_param->Kv_1 = PARAM_INIT_speed_k;
		p_param->Vf = PARAM_INIT_straight_speed;
		p_param->Vt = PARAM_INIT_turn_speed;
		p_param->Angle_1 = PARAM_INIT_Angle;
		p_param->Kd_LM_1 = PARAM_INIT_Kd_limit;
		//null ����չ��
		p_param->Dif_V_1 = PARAM_INIT_DIF_V_1;
		p_param->Bucha_1 = PARAM_INIT_BUCHA;
		p_param->Ki_2 = PARAM_INIT_Ki_2;
		p_param->Kp_2 = PARAM_INIT_Kp_2;
		p_param->Kd_2 = PARAM_INIT_Kd_2;
		p_param->Ki_3 = PARAM_INIT_Kp_3;
		p_param->Kp_3 = PARAM_INIT_Kd_3;
		p_param->Kd_3 = PARAM_INIT_Ki_3;
		p_param->STGY = PARAM_INIT_STGY;
		p_param->delta_speed = PARAM_INIT_delta_speed;
		p_param->null_5_1 = PARAM_INIT_NULL_5_1;
		p_param->Lbalance = PARAM_INIT_Lbalance;
		p_param->center = PARAM_INIT_center;
		p_param->param_enable = PARAM_INIT_ENBALE;
		//�Ƿ��Ѿ���ʼ������־λ��ֻ��flash����������Ż�ִ��һ�γ�ʼ��
		p_param->param_flag = PARAM_INIT_FLAG;
		param_save(p_param);
	}
}

//��������
//ע���ڸ�λ��ͬʱ�����ϼ��Ż������Ժ���
void param_set()
{
	uint8 page_num = 1;

	param_load(&s_parameter);
	param_init(&s_parameter); //�����־λ�ı䣬��ʼ��ΪĬ��ֵ

	while (page_num != EXIT_SET)
	{
		switch (page_num)
		{
		case 1:
			page_num = set_page_1(); ////���ҳ���Ҽ�ҳ
			//GPIO_Init(PORT_DD,3,1,0);
			break;
		case 2:
			page_num = set_page_2(&s_parameter);
			break;
		case 3:
			page_num = set_page_3(&s_parameter);
			break;
		case 4:
			page_num = set_page_4(&s_parameter);
			break;
		case 5:
			page_num = set_page_5(&s_parameter);
			break;
		case 6:
			page_num = set_page_6(&s_parameter);
			break;
		case 7:
			page_num = set_page_7(&s_parameter);
			break;
		case 8:
			page_num = set_page_8();
			break;
		default:
			return;
		}
	}
}