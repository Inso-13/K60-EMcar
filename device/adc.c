#include "adc.h"

int16 right_inductance;
int16 left_inductance;

int16 get_AD(ADC_Type *adcn_ch, AdcChnEnum_Type chn)
{
	int16 ad[40] = {0};
	float ad_x = 0;
	uint8 i;

	for (i = 0; i < 40; i++)
	{
		ad[i] = (int16)LPLD_ADC_Get(adcn_ch, chn);
		ad_x += ad[i];
	}
	bubble_sort(ad, 40);							   //ð������
	ad_x = (ad_x - ad[0] - ad[1] - ad[38] - ad[39]) / 36; //ȥ��������С����ȡƽ��ֵ
        
	if (ad_x < 5)
		return (0); //����޷�?
	else
		return ((int16)(ad_x));
}

void get_inductance(void)
{
	left_inductance = get_AD(ADC1, AD15) + get_AD(ADC1, DAD3);
	right_inductance = (get_AD(ADC1, AD14) + get_AD(ADC0, AD13)) * s_parameter.Lbalance / 100;
}

void swap(int16 ad[], int16 i, int16 j)
{
	int temp = ad[i];
	ad[i] = ad[j];
	ad[j] = temp;
}

void bubble_sort(int16 ad[], int16 n)
{
	for (int j = 0; j < n - 1; j++) // ÿ������?�ؾ�������һ��"��"����������
	{
		for (int i = 0; i < n - 1 - j; i++) // ���αȽ����ڵ�����Ԫ��,ʹ�ϴ���Ǹ������
		{
			if (ad[i] > ad[i + 1]) // ��������ĳ�ad[i] >= ad[i + 1],����?���ȶ��������㷨
			{
				swap(ad, i, i + 1);
			}
		}
	}
}