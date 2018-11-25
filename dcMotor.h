#ifndef __DCMOTOR__
#define __DCMOTOR__

#include <stdint.h>

void run_dc_motor(int on, int off);

void set_dc_motor_direction(uint32_t direction);

#endif