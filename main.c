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

#define INPUT_AQUISITION 0
#define DIRECTION_AQUISITION 1
#define SPEED_AQUISITION 2
#define SPEED_KEYBOARD 3
#define SPEED_POTENTIOMETER 4
#define RUN_MOTOR 5

int main(void)
{
	//iniciando
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
	enablePullUp(C,P4|P5|P6|P7);
	enablePullUp(J,P_ALL);
	
	//uint32_t switcher;
	
	//PortF_Output(0x4); //iniciliza motor
	
	int current_step = INPUT_AQUISITION;
	char input_type = ' ';
	char rotation_direction = ' ';
	char keyboard_speed = ' ';
	int selected_speed = -1;
	int i = 0;
	
	while(1){
		
		switch(current_step){
			case INPUT_AQUISITION:
				clear_display(0);
				
				print_message(0x80, "Motor Parado!");
				print_message(0xC0, "Pot (A) 4x4 (B) "); //mudar para 1 ou 2 se precisar 

				input_type = kb4x4(0);

				//Armazena o input em DIRECTION_CONTROL
				if(input_type == KEYBOARD || input_type == POTENTIOMETER) current_step = DIRECTION_AQUISITION;
				
				break;

			case DIRECTION_AQUISITION:

				clear_display(0);

				if(input_type == KEYBOARD) print_message(0x80, "INPUT: 4X4 ");
		
				else if (input_type == POTENTIOMETER) print_message(0x80, "INPUT: POT. ");
				
				print_message(0x80, "-> (1) | <- (2) ");

				//
				rotation_direction = kb4x4(0);
				//input_type = kb4x4(i++);
				//if(i > 3) i = 0;
				//Pega a direção do giro
				if(rotation_direction == CLOCKWISE || rotation_direction == COUNTERCLOCKWISE) current_step = SPEED_AQUISITION;

			break;

			case SPEED_AQUISITION:
				if(input_type == KEYBOARD) current_step = SPEED_KEYBOARD;
				
				else if (input_type == POTENTIOMETER) current_step = SPEED_POTENTIOMETER;

				else print_message(0xC0, "DEU RUIM IRMÃO ");
			break;

			case SPEED_KEYBOARD:
		
				keyboard_speed = kb4x4(i++);
				if(i > 3) i = 0;
				
				if( rotation_direction == '0' || rotation_direction == '1' || rotation_direction == '2' ||
					rotation_direction == '3' || rotation_direction == '4' || rotation_direction == '5' ||
					rotation_direction == '6' ) {

					selected_speed = get_kb4x4_value(keyboard_speed);
					current_step = RUN_MOTOR;
				}

			break;
			case SPEED_POTENTIOMETER:

			//Espera o fetch dos dados do adc e roda motor
			current_step = RUN_MOTOR;
			default: break;
			case RUN_MOTOR:

			while(PortJ_Input() != 0x03){

			//run_motor
			run_motor(9999);
			//A qualquer momento, se o botão ‘*’ for pressionado o motor deve alterar 
			//a rotação para  girar no sentido horário e se o botão ‘#’
 			//for pressionado o motor deve girar no sentido anti-horário;


			}	

			current_step = INPUT_AQUISITION;
			break;
		}

	}
		/*Código antigo
		if(PortJ_Input() == 0x02){
		PortE_Output(0x1); //horário
	
		PortF_Output(0x004);}
	
		else {
		PortE_Output(0x02); //horário
		PortF_Output(0x000); //iniciliza motor <---PWM
		} Fim do código antigo*/
	
		
	
}


