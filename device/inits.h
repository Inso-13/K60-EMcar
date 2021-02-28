#ifndef _INITS_H_
#define _INITS_H_

#include "common.h"
#include "../model/params.h"

extern PARAM s_parameter;

void gpio_init(GPIO_Type *PTx, uint32 GPIO_Pinx, uint8 dir, uint8 Level, uint32 pincontrol);
void inits(void);
void motor_init(void);
void uart_init(void);
void servo_init(void);
void flash_init(void);
void button_init(void);
void pit_servo_init(void); //舵机打角时钟初始化
void ADC_init(void);

#endif