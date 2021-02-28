#ifndef _PARAMS_H_
#define _PARAMS_H_

#include "common.h"

//�����ṹ��
typedef struct
{
	//dir control parameter
	int16 Kp_1;
	int16 Kd_1;

	int16 Vf;
	int16 Vt;

	//camera threshold
	int16 Kv_1; //cam_cnst
	//speed control parameter
	int16 Angle_1; //speed_max

	int16 Kd_LM_1;
	int16 Dif_V_1; //sd_able
	//null

	int16 Bucha_1; //ͼ��0����ʾ��1 ��ʵͼ��2 ��ͼ��
	int16 Ki_2;	   //ǰհ�ߵ��ڴ�����ӱ����
	int16 Kp_2;
	int16 Kd_2;

	int16 Ki_3;
	int16 Kp_3;
	int16 Kd_3;
	int16 STGY;

	int16 delta_speed;
	int16 null_5_1;
	int16 Lbalance;
	int16 center;

	int16 param_flag;
	int16 param_enable;

} PARAM;

//������ʼ��
#define PARAM_INIT_speed_k (45)
#define PARAM_INIT_SPE_KP (5)
#define PARAM_INIT_SPE_KI (40)
#define PARAM_INIT_Angle (32)
#define PARAM_INIT_Kd_limit (13)
#define PARAM_INIT_DIF_V_1 (280)

#define PARAM_INIT_Kp_1 (1)
#define PARAM_INIT_Kd_1 (600)
#define PARAM_INIT_straight_speed (3200)
#define PARAM_INIT_turn_speed (2800)

#define PARAM_INIT_BUCHA (10)
#define PARAM_INIT_Ki_2 (1)
#define PARAM_INIT_Kp_2 (1)
#define PARAM_INIT_Kd_2 (1)
#define PARAM_INIT_Kp_3 (1)
#define PARAM_INIT_Kd_3 (1)
#define PARAM_INIT_Ki_3 (1)
#define PARAM_INIT_STGY (1)
#define PARAM_INIT_delta_speed (0)
#define PARAM_INIT_NULL_5_1 (950)
#define PARAM_INIT_Lbalance (100)
#define PARAM_INIT_center (775)
#define PARAM_INIT_FLAG (12)
#define PARAM_INIT_ENBALE (123)

void param_load(PARAM *p_param);
void param_save(PARAM *p_param);
void param_check(PARAM *p_param);
void param_init(PARAM *p_param);
void param_set(void);

#endif