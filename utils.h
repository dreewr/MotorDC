/**=============================================================================
// keyboard4x4.s
// Luís Henrique Beltrão Santana
// 25/10/2018
=============================================================================**/

#ifndef __UTILS__
#define __UTILS__

#include <stdint.h>

#ifndef NULL
#define NULL ((void *) 0)
#endif
#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif
typedef int bool;


void PLL_Init(void);
void SysTick_Init(void);
void SysTick_Wait1ms(uint32_t delay);
#endif
