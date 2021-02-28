#include "button.h"
#include "flash.h"
#include "oled.h"
#include "../controller/interrupt.h"
#include "inits.h"

ADC_InitTypeDef adc_init_struct;
GPIO_InitTypeDef gpio_init_struct;
FTM_InitTypeDef motor_init_struct; //���
FTM_InitTypeDef ftm_init_struct;
UART_InitTypeDef uart5_init_struct;
GPIO_InitTypeDef ButtonInit;
PIT_InitTypeDef p_init;

void gpio_init(GPIO_Type *PTx, uint32 GPIO_Pinx, uint8 dir, uint8 Level, uint32 pincontrol)
{

	gpio_init_struct.GPIO_Dir = dir;
	gpio_init_struct.GPIO_PTx = PTx;		//PORT��
	gpio_init_struct.GPIO_Pins = GPIO_Pinx; //���ź�
	if (dir == DIR_OUTPUT)
	{
		gpio_init_struct.GPIO_Output = Level; //��ʼ������ڳ�ʼ��ƽ�ߵ�
	}
	gpio_init_struct.GPIO_PinControl = pincontrol; //���ſ���
	LPLD_GPIO_Init(gpio_init_struct);
}

void motor_init(void) //�����ʼ��
{

	motor_init_struct.FTM_Ftmx = FTM0;		   //ʹ��FTM0ͨ�����1
	motor_init_struct.FTM_Mode = FTM_MODE_PWM; //ʹ��PWMģʽ
	motor_init_struct.FTM_PwmFreq = 10000;
	LPLD_FTM_Init(motor_init_struct);	

	LPLD_FTM_PWM_Enable(FTM0,	   //ʹ��FTM0//�ұ�
						FTM_Ch2,   //ʹ��Ch2ͨ��  ����
						0,		   //&&&&&&&&&&&&&&&&&&&&//��ʼ���Ƕ�0��
						PTC3,	   //ʹ��Ch0ͨ����PTC1����
						ALIGN_LEFT //���������
	);
	LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 0);
	LPLD_FTM_PWM_Enable(FTM0,	   //ʹ��FTM0//�ұ�
						FTM_Ch0,   //ʹ��Ch0ͨ��    ����
						0,		   //&&&&&&&&&&&&&&&&&&&&//��ʼ���Ƕ�0��
						PTC1,	   //ʹ��Ch0ͨ����PTC1����
						ALIGN_LEFT //���������
	);
	LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 0);
}

void servo_init(void)
{

	ftm_init_struct.FTM_Ftmx = FTM1;		 //ʹ��FTM1ͨ��
	ftm_init_struct.FTM_Mode = FTM_MODE_PWM; //ʹ��PWMģʽ
	ftm_init_struct.FTM_PwmFreq = 50;		 //PWMƵ��50Hz

	LPLD_FTM_Init(ftm_init_struct);

	LPLD_FTM_PWM_Enable(FTM1,	   //ʹ��ftmx
						FTM_Ch1,   //ʹ��chnͨ��
						0,		   //��ʼ���Ƕ�0��
						PTA9,	   //ʹ��chnͨ����pin����
						ALIGN_LEFT //���������
	);
	LPLD_FTM_PWM_ChangeDuty(FTM1, FTM_Ch1, 725); //775 ����  825 �����  730�����
}

void uart_init(void)
{

	uart5_init_struct.UART_Uartx = UART5;	 //ʹ��UART5
	uart5_init_struct.UART_BaudRate = 38400; //���ò�����9600
	uart5_init_struct.UART_RxPin = PTE9;	 //��������ΪPTE9
	uart5_init_struct.UART_TxPin = PTE8;	 //��������ΪPTE8
	//��ʼ��UART
	LPLD_UART_Init(uart5_init_struct);
}

void flash_init(void)
{
	LPLD_Flash_Init();
}

void button_init(void)
{

	ButtonInit.GPIO_PTx = PTC;
	ButtonInit.GPIO_Dir = DIR_OUTPUT; //���뷽��
	ButtonInit.GPIO_Output = OUTPUT_H;
	ButtonInit.GPIO_PinControl = IRQC_DIS | INPUT_PULL_DOWN; //������ֹ�ж�

	ButtonInit.GPIO_Pins = BT_LE_PIN;
	LPLD_GPIO_Init(ButtonInit);
	ButtonInit.GPIO_Pins = BT_RI_PIN;
	LPLD_GPIO_Init(ButtonInit);
	ButtonInit.GPIO_Pins = BT_DN_PIN;
	LPLD_GPIO_Init(ButtonInit);
	ButtonInit.GPIO_Pins = BT_UP_PIN;
	LPLD_GPIO_Init(ButtonInit);
	ButtonInit.GPIO_Pins = BT_OK_PIN;
	LPLD_GPIO_Init(ButtonInit);
}

void pit_servo_init(void)
{

	p_init.PIT_Pitx = PIT0;
	p_init.PIT_PeriodS = 0;
	p_init.PIT_PeriodUs = 0;
	p_init.PIT_PeriodMs = 5; //ѧ�����飺20ms
	p_init.PIT_Isr = pit_loop;
	LPLD_PIT_Init(p_init);
	LPLD_PIT_EnableIrq(p_init);
}

void ADC_init(void)
{

	adc_init_struct.ADC_DiffMode = ADC_SE;			  //���˲ɼ�
	adc_init_struct.ADC_BitMode = SE_8BIT;			  //����8λ����
	adc_init_struct.ADC_SampleTimeCfg = SAMTIME_LONG; //�̲���ʱ��
	adc_init_struct.ADC_LongSampleTimeSel = LSAMTIME_12EX;
	adc_init_struct.ADC_HwAvgSel = HW_16AVG; //16��Ӳ��ƽ��
	adc_init_struct.ADC_CalEnable = TRUE;	 //ʹ�ܳ�ʼ��У��

	adc_init_struct.ADC_Adcx = ADC0;
	LPLD_ADC_Init(adc_init_struct);
    LPLD_ADC_Chn_Enable(ADC0,AD13);
	adc_init_struct.ADC_Adcx = ADC1;
	LPLD_ADC_Init(adc_init_struct);
    LPLD_ADC_Chn_Enable(ADC1,DAD3);
    LPLD_ADC_Chn_Enable(ADC1,AD14);
    LPLD_ADC_Chn_Enable(ADC1,AD15);
}

void inits(void)
{
	DisableInterrupts;

	flash_init();
	oled_init();
	ADC_init();
	servo_init();
	motor_init();
	pit_servo_init(); //�жϺ�����ʼ��

	flash_read();
	param_load(&s_parameter);

	EnableInterrupts;
}
