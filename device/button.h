#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "common.h"

//左
#define BT_LE_PORT (PTC)
#define BT_LE_PIN (GPIO_Pin10)
#define BT_LE_NUM (10)
//右
#define BT_RI_PORT (PTC)
#define BT_RI_PIN (GPIO_Pin4)
#define BT_RI_NUM (4)
//下
#define BT_DN_PORT (PTC)
#define BT_DN_PIN (GPIO_Pin8)
#define BT_DN_NUM (8)
//上
#define BT_UP_PORT (PTC)
#define BT_UP_PIN (GPIO_Pin12)
#define BT_UP_NUM (12)
//确定
#define BT_OK_PORT (PTC)
#define BT_OK_PIN (GPIO_Pin7)
#define BT_OK_NUM (7)

//按键状态读取
#define BT_UP_STATE (!LPLD_GPIO_Input_b(BT_UP_PORT, BT_UP_NUM))
#define BT_DN_STATE (!LPLD_GPIO_Input_b(BT_DN_PORT, BT_DN_NUM))
#define BT_LE_STATE (!LPLD_GPIO_Input_b(BT_LE_PORT, BT_LE_NUM))
#define BT_RI_STATE (!LPLD_GPIO_Input_b(BT_RI_PORT, BT_RI_NUM))
#define BT_OK_STATE (!LPLD_GPIO_Input_b(BT_OK_PORT, BT_OK_NUM))

//按键ID定义
#define BT_UP_PRESS (1)
#define BT_DN_PRESS (2)
#define BT_LE_PRESS (3)
#define BT_RI_PRESS (4)
#define BT_OK_PRESS (5)

void button_delay(void);
uint8 button_scan(void);

#endif
