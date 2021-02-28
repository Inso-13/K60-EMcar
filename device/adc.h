#ifndef _ADC_H_
#define _ADC_H_

#include "common.h"
#include "../model/params.h"

extern PARAM s_parameter;
int16 get_AD(ADC_Type *adcn_ch, AdcChnEnum_Type chn);
void get_inductance(void);
void swap(int16 ad[], int16 i, int16 j);
void bubble_sort(int16 ad[], int16 n);

#endif