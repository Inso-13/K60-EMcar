#ifndef _DIRECTION_H
#define _DIRECTION_H

#include "common.h"
#include "../model/params.h"

extern int16 right_inductance;
extern int16 left_inductance;
extern PARAM s_parameter;

#define Direct_max (s_parameter.center+90)
#define Direct_min (s_parameter.center-90)
#define Direct_center (s_parameter.center)

void auto_navigate(void);
void auto_navigate_1(void);
void auto_navigate_2(void);
void auto_navigate_3(void);

#endif