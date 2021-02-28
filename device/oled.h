#ifndef _OLED_H_
#define _OLED_H_

#include "common.h"

#define OLED_CHAR_WIDTH 6 //ÿ���ַ�����

#define OLED_SCLK_PORT (PTE)
#define OLED_SCLK_PIN (GPIO_Pin11)
#define OLED_SCLK_NUM (11)

#define OLED_SDIN_PORT (PTE)
#define OLED_SDIN_PIN (GPIO_Pin6)
#define OLED_SDIN_NUM (6)

#define OLED_DC_PORT (PTE)
#define OLED_DC_PIN (GPIO_Pin5)
#define OLED_DC_NUM (5)

#define OLED_RST_PORT (PTE)
#define OLED_RST_PIN (GPIO_Pin7)
#define OLED_RST_NUM (7)

#define LOW (0)
#define HIGH (1)

#define LED_IMAGE_WHITE 1
#define LED_IMAGE_BLACK 0
#define LED_MAX_ROW_NUM 64
#define LED_MAX_COLUMN_NUM 128

#define TWINK_PERIOD 50 // per ms

#define HUAKE_UNIVERSITY (0)
#define SMART_MOTORCADE (1)
#define POWER_ON_SELF_TEST (2)
#define SET_PARAM (3)
#define HARDWARE_TEST (4)
#define DISPLAY_IMAGE (5)
#define FINISH_SD_CARD (6)

enum OLED_LIGHT_MODE
{
	LOW_LIGHT_MODE = 0,
	HIGH_LIGHT_MODE = 1,
};

#define false 0
#define E_SYS 1
/**
 *  @ brief   oled_init
 *
 *  @ param   none
 *
 *	@ note    oled init
 *
 *	@ return  none
 */
void oled_init(void);

/**
 *  @ brief   oled_set_pos
 *
 *  @ param   uc_posx   ��
 *            uc_posy   ҳ
 *
 *	@ note    ��������
 *
 *	@ return  none
 */
void oled_set_pos(uint8 uc_posx, uint8 uc_posy);

/**
 *  @ brief   SetInverseDisplay
 *
 *  @ param   uc_data
 *
 *	@ note    ȫ��д��ͬһ���ַ� ����
 *
 *	@ return  none
 */
void oled_fill(char uc_data);

/**
 *  @ brief   oled_display_6x8char
 *
 *  @ param   uint8 uc_posx  ��ʾ�ĺ�����0~122
 * 			  uint8 uc_posy  ҳ��Χ0��7
 *    		  char uc_data  ��ʾ���ַ�
 *
 *	@ note    display a character
 *
 *	@ return  none
 */
void oled_display_6x8char(uint8 uc_posx, uint8 uc_posy, char uc_data);

/**
 *  @ brief   oled_display_6x8str
 *
 *  @ param   uint8 uc_posx       ��ʾ�ĺ�����0~122
 *			  uint8 uc_posy       ҳ��Χ0��7
 *    		  char uc_dataStr[]  ��ʾ���ַ���
 *
 *	@ note    display a string
 *
 *	@ return  none
 */
void oled_display_6x8str(uint8 uc_posx, uint8 uc_posy, char uc_dataStr[]);

/**
 *  @ brief   oled_print_char
 *
 *  @ param   uint8 uc_posx  ��ʾ�ĺ�����0~122
 *    		  uint8 uc_posy  ҳ��Χ0��7
 *    		  int8  c_data   ��Ҫת����ʾ����ֵ -128~127
 *
 *	@ note    ��һ��Char����ת����3λ��������ʾ
 *
 *	@ return  none
 */
void oled_print_char(uint8 uc_posx, uint8 uc_posy, int8 c_data);

/**
 *  @ brief   oled_print_short
 *
 *  @ param   uint8 uc_posx  ��ʾ�ĺ�����0~122
 *   		  uint8 uc_posy  ҳ��Χ0��7
 *  		  int8  s_data   ��Ҫת����ʾ����ֵ
 *
 *	@ note    ��һ��int16����ת����5λ��������ʾ
 *
 *	@ return  none
 */
void oled_print_short(uint8 uc_posx, uint8 uc_posy, int16 s_data);

/**
 *  @ brief   oled_print_image
 *
 *  @ param   uint8 usPicture[][168]     ��άͼ������ĵ�ַ
*      		  uint16 usRowNum            ��άͼ�������1~64
*   		  uint16 usColumnNum         ��άͼ�������1~128
 *
 *	@ note    ��ͼ����ʾ����
 *
 *	@ return  none
 */
void oled_print_image(uint8 usPicture[][128], uint16 usRowNum, uint16 usColumnNum);
void oled_print_mirror_image(uint8 usPicture[][128], uint16 usRowNum, uint16 usColumnNum);

void oled_print_std_image(uint8 u8Mode);

/**
 *  @ brief   oled_gap
 *
 *  @ param   none
 *
 *	@ note    display gap between dates
 *
 *	@ return  none
 */
void oled_gap(void);

/**
 *  @ brief   oled_twink
 *
 *  @ param   none
 *
 *	@ note    twink, to remind us the oled is working
 *
 *	@ return  none
 */
void oled_twink(void);

/**
 *  @ brief   oled_clear
 *
 *  @ param   none
 *
 *	@ note    clear some space
 *
 *	@ return  none
 */
void oled_clear(uint8 start_x, uint8 page, uint8 clear_size);

/**
 *  @ brief   oled_gap
 *
 *  @ param   none
 *
 *	@ note    display gap between dates
 *
 *	@ return  none
 */
void oled_one_group(uint8 my_x, uint8 my_y, uint16 my_data);

void oled_write_data(uint8 uc_data);

void oled_my_show(uint8 my_x, uint8 my_y, int16 mydata);

//void oled_display_image(CCD_STRUCT *pccd);

void oled_display_16x8char(uint8 uc_posx, uint8 uc_posy, char uc_data);
void oled_display_16x8str(uint8 uc_posx, uint8 uc_posy, char uc_dataStr[]);
void oled_print_16x8char(uint8 uc_posx, uint8 uc_posy, int8 c_data);
void oled_print_16x8short(uint8 uc_posx, uint8 uc_posy, int16 s_data);

void oled_display_16x8char_hl(uint8 uc_posx, uint8 uc_posy, char uc_data);
void oled_display_16x8str_hl(uint8 uc_posx, uint8 uc_posy, char uc_dataStr[]);
void oled_print_16x8short_hl(uint8 uc_posx, uint8 uc_posy, int16 s_data, int8 bits_num);

void oled_display_6x8char_hl(uint8 uc_posx, uint8 uc_posy, char uc_data);

void oled_display_6x8str_hl(uint8 uc_posx, uint8 uc_posy, char uc_dataStr[]);

void oled_print_char_hl(uint8 uc_posx, uint8 uc_posy, int8 c_data);

void oled_print_short_hl(uint8 uc_posx, uint8 uc_posy, int16 s_data, int8 bits_num);

void oled_display_chinese(uint8 uc_posx, uint8 uc_posy, uint8 Chinese_str_num, enum OLED_LIGHT_MODE mode);

void oled_display_boolean(uint8 uc_posx, uint8 uc_posy, char bool_data);

void oled_display_direction(uint8 uc_posx, uint8 uc_posy, char dir_data);

#endif /* OLED_H_ */
