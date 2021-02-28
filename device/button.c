#include "button.h"

void button_delay(void)
{
	unsigned int i, j;

	for (i = 0; i < 2000; i++)
	{
		for (j = 0; j < 2000; j++)
		{
			asm("nop");
		}
	}
}

uint8 button_scan(void)
{
	if (!LPLD_GPIO_Input_b(BT_LE_PORT, BT_LE_NUM)) //LPLD_GPIO_Input_b返回引脚的电位值
	{
		button_delay();
		// if (!LPLD_GPIO_Input_b(BT_LE_PORT, BT_LE_NUM))
		// {
		// 	while (!LPLD_GPIO_Input_b(BT_LE_PORT, BT_LE_NUM))
		// 		;
		// 	return 3;
		// }
		return 3;
	}
	else if (!LPLD_GPIO_Input_b(BT_RI_PORT, BT_RI_NUM)) //LPLD_GPIO_Input_b返回引脚的电位值
	{
		button_delay();
		// if (!LPLD_GPIO_Input_b(BT_RI_PORT, BT_RI_NUM))
		// {
		// 	while (!LPLD_GPIO_Input_b(BT_RI_PORT, BT_RI_NUM))
		// 		;
		// 	return 4;
		// }
		return 4;
	}
	else if (!LPLD_GPIO_Input_b(BT_UP_PORT, BT_UP_NUM)) //LPLD_GPIO_Input_b返回引脚的电位值
	{
		button_delay();
		// if (!LPLD_GPIO_Input_b(BT_UP_PORT, BT_UP_NUM))
		// {
		// 	while (!LPLD_GPIO_Input_b(BT_UP_PORT, BT_UP_NUM))
		// 		;
		// 	return 1;
		// }
		return 1;
	}
	else if (!LPLD_GPIO_Input_b(BT_DN_PORT, BT_DN_NUM)) //LPLD_GPIO_Input_b返回引脚的电位值
	{
		button_delay();
		// if (!LPLD_GPIO_Input_b(BT_DN_PORT, BT_DN_NUM))
		// {
		// 	while (!LPLD_GPIO_Input_b(BT_DN_PORT, BT_DN_NUM))
		// 		;
		// 	return 2;
		// }
		return 2;
	}
	else if (!LPLD_GPIO_Input_b(BT_OK_PORT, BT_OK_NUM)) //LPLD_GPIO_Input_b返回引脚的电位值return (uint8)((ptx->PDIR>>lsb_num)&0x01L);
	{
		button_delay();
		// if (!LPLD_GPIO_Input_b(BT_OK_PORT, BT_OK_NUM))
		// {
		// 	while (!LPLD_GPIO_Input_b(BT_OK_PORT, BT_OK_NUM))
		// 		;
		// 	return 5;
		// }
		return 5;
	}
	return 0;
}
