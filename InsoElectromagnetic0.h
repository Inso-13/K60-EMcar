#ifndef _INSO_H_
#define _INSO_H_

#include "debug/debug.h"
#include "device/oled.h"
#include "device/inits.h"
#include "model/params.h"

extern PARAM s_parameter;
extern int16 right_inductance;
extern int16 left_inductance;
extern int16 speed_error;
extern uint32 speed;
extern int16 Direct_out;

#endif