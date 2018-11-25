#include "lcd_display.h"
#include "gpio.h"
#include "utils.h"

//Power: valores de 0 a 6
//0 -> 50
//1 -> 60
//0 -> 50% --> 6
//duty cycle base: 50ms, que pode ir pra mais ou pra menos
void run_dc_motor(int on, int off){
	
	PortF_Output(0x4);
	SysTick_Wait1ms(on);	
	
	PortF_Output(0x0);
	SysTick_Wait1ms(off);

}

void set_dc_motor_direction(uint32_t direction){

	PortE_Output(direction); //horário
	
}