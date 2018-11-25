/**=============================================================================
// keyboard4x4.s
// Luís Henrique Beltrão Santana
// 25/10/2018
=============================================================================**/

#include <stdint.h>
#include <string.h>


#include "gpio.h"
#include "utils.h"
#include "keyboard.h"
#include "dcMotor.h"
#include "tm4c1294ncpdt.h"
#include "lcd_display.h"

#define KEYBOARD '1'
#define POTENTIOMETER '2'
#define CLOCKWISE '1'
#define COUNTERCLOCKWISE '2'

#define RUN_CLOCKWISE '*'
#define RUN_COUNTERCLOCKWISE '#'

#define START 0
#define INPUT_AQUISITION 1
#define DIRECTION_AQUISITION 2
#define SPEED_AQUISITION 3
#define SPEED_KEYBOARD 4
#define SPEED_POTENTIOMETER 5
#define RUN_MOTOR 6

int current_step = START;
char input_type = ' ';
char rotation_direction = ' ';
char keyboard_speed = ' ';
int selected_speed = -1;
uint32_t selected_direction = 0;
int i = 0;


/**Function Prototypes**/
void ConfigInterruptPortC();
void ConfigInterruptPortJ();
void GPIOPortJ_Handler(void);

int main(void)
{
	PLL_Init();
	SysTick_Init();
	uint32_t gpio = 
		GPIO_PORTC | GPIO_PORTH | GPIO_PORTK | GPIO_PORTL | GPIO_PORTM | GPIO_PORTE | GPIO_PORTF | GPIO_PORTJ;
	EnableGpio(gpio);
	clearAmsel(C);
	clearAmsel(E);
	clearAmsel(F);
	clearAmsel(H);
	clearAmsel(J);
	clearAmsel(K);
	clearAmsel(L);
	clearAmsel(M);
	
	clearPCTL(C);
	clearPCTL(E);
	clearPCTL(F);
	clearPCTL(H);
	clearPCTL(J);
	clearPCTL(K);
	clearPCTL(L);
	clearPCTL(M);
	
	ioDirection(C, P_NONE);
	ioDirection(J, P_NONE);
	ioDirection(E, P0|P1|P2|P3);
	ioDirection(F, P0|P1|P2|P3);
	ioDirection(H, P0|P1|P2|P3);
	ioDirection(K,P_ALL);
	ioDirection(L,P0|P1|P2|P3);
	ioDirection(M,P0|P1|P2);
	
	clearAfsel(C);
	clearAfsel(E);
	clearAfsel(F);
	clearAfsel(H);
	clearAfsel(J);
	clearAfsel(K); 
	clearAfsel(L);
	clearAfsel(M);
	
	digitalEnable(C,P4|P5|P6|P7);
	digitalEnable(J,P0|P1);
	digitalEnable(E,P0|P1|P2|P3);
	digitalEnable(F,P0|P1|P2|P3);
	digitalEnable(H,P0|P1|P2|P3);
	digitalEnable(K,P_ALL);
	digitalEnable(L,P0|P1|P2|P3);
	digitalEnable(M,P0|P1|P2);
	digitalEnable(M,P0|P1|P2);
	
	enablePullUp(C,P4|P5|P6|P7);
	enablePullUp(J,P_ALL);
	
	init_display(0);
	

	ConfigInterruptPortJ();
	
	while(1){
	
		switch(current_step){
			
			case START:
				clear_display(0);
				input_type = ' ';
				rotation_direction = ' ';
				keyboard_speed = ' ';
				selected_speed = -1;
				uint32_t selected_direction = 0;
	
				print_message(0x80, "Motor Parado!");
				print_message(0xC0, "Tec(1) | Pot(2) "); //mudar para 1 ou 2 se precisar
				
			
			  current_step = INPUT_AQUISITION;
				break;
			
			case INPUT_AQUISITION:
				
			input_type = kb4x4(i++);
			if (i >3) i=0;
			
				if(input_type == KEYBOARD ) {
					
					clear_display(0);
					print_message(0x80, "Tec. selecionado ");
					print_message(0xC0, "->(1) | <-(2) "); //mudar para 1 ou 2 se precisar
					current_step = DIRECTION_AQUISITION;
					
				} else if (input_type == POTENTIOMETER){
					
					clear_display(0);
					print_message(0x80, "Pot. selecionado ");
					print_message(0xC0, "->(1) | <-(2) "); //mudar para 1 ou 2 se precisar
					current_step = DIRECTION_AQUISITION;
				}
				
				break;

			case DIRECTION_AQUISITION:

				rotation_direction = kb4x4(i++);
				if (i >3) i=0;

				if(rotation_direction == CLOCKWISE ) {
						
						clear_display(0);
						print_message(0x80, "Sentido -> ");
						selected_direction = 0x1;
						current_step = SPEED_AQUISITION;
						
					} else if (rotation_direction == COUNTERCLOCKWISE){
						
						clear_display(0);
						selected_direction = 0x2;
						print_message(0x80, "Sentido <-");
				
						current_step = SPEED_AQUISITION;
					} 
					

			break;

			case SPEED_AQUISITION:
				
				
			
				if(input_type == KEYBOARD) {print_message(0xC0, "Velocidade (0-6) ");
																		current_step = SPEED_KEYBOARD;}
				
				else if (input_type == POTENTIOMETER) {
					current_step = SPEED_POTENTIOMETER;
				}
			break;

			case SPEED_KEYBOARD:
			
			
				keyboard_speed = kb4x4(i++);
				if(i > 3) i = 0;
				
				if( keyboard_speed == '0' || keyboard_speed == '1' || keyboard_speed == '2' ||
					keyboard_speed == '3' || keyboard_speed == '4' || keyboard_speed == '5' ||
					keyboard_speed == '6' ) {
					
						clear_display(0);
						
					if(get_kb4x4_value(keyboard_speed)!=0)selected_speed = 40 + 10* get_kb4x4_value(keyboard_speed);
					
					else selected_speed = 0;
						
						switch (selected_speed){
							case 0: 
								print_message(0x80, "Motor parado! ");
								break;
							case 50: 
								print_message(0x80, "V. em 50% ");
								break;
							case 60: 
								print_message(0x80, "V. em 60% ");
								break;
							case 70: 
								print_message(0x80, "V. em 70% ");
								break;
							case 80: 
								print_message(0x80, "V. em 80% ");
								break;
							case 90: 
								print_message(0x80, "V. em 90% ");
								break;
							case 100: 
								print_message(0x80, "V. em 100% ");
								break;
						
						}
						
					current_step = RUN_MOTOR;
				}

			break;
			
			case SPEED_POTENTIOMETER:

			//Espera o fetch dos dados do adc e roda motor
			current_step = RUN_MOTOR;
			
			case RUN_MOTOR:

			
				set_dc_motor_direction(selected_direction);
	
				run_dc_motor(selected_speed , 100-selected_speed);

	
			break;
		}

	}
	
}

void GPIOPortJ_Handler(void){
	
	current_step = START;
	
	GPIO_PORTJ_AHB_ICR_R  = 0x01;
	
}

/*
Register 4: Interrupt 0-31 Set Enable (EN0), offset 0x100
Register 5: Interrupt 32-63 Set Enable (EN1), offset 0x104
Register 6: Interrupt 64-95 Set Enable (EN2), offset 0x108
Register 7: Interrupt 96-113 Set Enable (EN3), offset 0x10C*/


void ConfigInterruptPortJ(){
DisableInterrupts();
	
NVIC_EN1_R |= 0x00080000;  //Interrup 32-63 (endereço 0xE000E000, offset 0x104) seta interrupt 51
GPIO_PORTJ_AHB_IM_R |= 0x0000010;  //GPIO_IM da porta J (endereço 0x4006000, offset 0x410) apenas USR_SW1 (Porta J, pino 0)
	
EnableInterrupts();
}

void ConfigInterruptPortC(){
DisableInterrupts();
	
NVIC_EN0_R |= 0x00080000;  //Interrup 32-63 (endereço 0xE000E000, offset 0x100) seta interrupt 51

GPIO_PORTC_AHB_IM_R |= 0x0000001;  //GPIO_IM da porta J (endereço 0x4006000, offset 0x410) apenas USR_SW1 (Porta J, pino 0)
	
EnableInterrupts();
}
