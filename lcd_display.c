/**=============================================================================
// keyboard4x4.s
// Luís Henrique Beltrão Santana
// 30/10/2018
=============================================================================**/

#include "lcd_display.h"
#include "gpio.h"
#include "utils.h"

//{0x3C, 0xE, 0xD, 0xE};
const uint32_t instruction[4] = {0x38, 0x06, 0x0C, 0x01};
//const uint32_t instruction[4] = {0x3C, 0x0D, 0x0E, 0x01};
const uint32_t enable_off = 0x0;
const uint32_t enable_on = 0x4;
const uint32_t send_data = 0x5;

char teste = 'S';

void init_display(int ki){
	
	PortM_Output(enable_off);
	SysTick_Wait1ms(10);
	PortM_Output(enable_on);
	SysTick_Wait1ms(10);
	PortK_Output(instruction[0]);
	SysTick_Wait1ms(20);
	
	PortM_Output(enable_off);
	SysTick_Wait1ms(10);
	PortM_Output(enable_on);
	PortK_Output(instruction[1]);
	SysTick_Wait1ms(20);
	
	PortM_Output(enable_off);
	SysTick_Wait1ms(10);
	PortM_Output(enable_on);
	SysTick_Wait1ms(10);
	PortK_Output(instruction[2]);
	SysTick_Wait1ms(20);
	
	PortM_Output(enable_off);
	SysTick_Wait1ms(10);
	PortM_Output(enable_on);
	SysTick_Wait1ms(10);
	PortK_Output(instruction[3]);
	SysTick_Wait1ms(20);
	
	
}
	
void clear_display(int ki){
	PortM_Output(enable_off);
	SysTick_Wait1ms(10);
	PortM_Output(enable_on);
	SysTick_Wait1ms(10);
	PortK_Output(instruction[3]);
	SysTick_Wait1ms(20);
}

void print_message(uint32_t position, char message[]){
	
	int i = 0;
	
	PortM_Output(enable_off);
	SysTick_Wait1ms(10);
	PortM_Output(enable_on);
	SysTick_Wait1ms(10);
	PortK_Output(position);
	SysTick_Wait1ms(20);
		
	while (message[i]){
	
		PortM_Output(enable_off);
		SysTick_Wait1ms(10);
		PortM_Output(send_data);
		SysTick_Wait1ms(10);
		PortK_Output(message[i]);
		SysTick_Wait1ms(20);
	
		++i;
	}

}

