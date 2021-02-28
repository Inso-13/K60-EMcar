#ifndef _PAGES_H_
#define _PAGES_H_

#include "common.h"
#include "../model/params.h"

//µ÷ÊÔÒ³Êı
#define PAGE_MIN (1)
#define PAGE_MAX (8)
#define EXIT_SET (0)

uint8 set_page_first(void);
uint8 set_page_ent(PARAM *p_param);
uint8 set_page_last(void);
uint8 set_page_16x8common(char *pstr_a, int16 *param_a,
						  char *pstr_b, int16 *param_b,
						  char *pstr_c, int16 *param_c,
						  char *pstr_d, int16 *param_d,
						  uint8 page_num);
uint8 set_page_1(void);
uint8 set_page_2(PARAM *p_param);
uint8 set_page_3(PARAM *p_param);
uint8 set_page_4(PARAM *p_param);
uint8 set_page_5(PARAM *p_param);
uint8 set_page_6(PARAM *p_param);
uint8 set_page_7(PARAM *p_param);
uint8 set_page_8(void);

#endif