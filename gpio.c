/**=============================================================================
// keyboard4x4.s
// Luís Henrique Beltrão Santana
// 25/10/2018
=============================================================================**/

#include "gpio.h"


#define GPIO_PORTJN (0x1100) //bits 8 e 12

//==============================================================================

/** A funcao SYSCTL_RCGCGPIO habilita o modo gpio para as portas selecionadas
  * @param: port e os bits que representam cada uma das portas 
	
	! ADC: Bits 8 and 9 of the SYSCTL_RCGC0_R specify the maximum sampling rate
**/
void EnableGpio(uint32_t value){
    SYSCTL_RCGCGPIO_R |= value;
    while((SYSCTL_PRGPIO_R & value ) != value){};
} 

void clearAmsel(uint8_t port){
	uint8_t temp;
	switch(port){
		case A: GPIO_PORTA_AHB_AMSEL_R = 0x00;
				break;
		case B: GPIO_PORTB_AHB_AMSEL_R = 0x00;
				break;
		case C: temp = GPIO_PORTC_AHB_AMSEL_R;
				temp &= ~0xf0;
				GPIO_PORTC_AHB_AMSEL_R = temp;
				break;
		case D: GPIO_PORTD_AHB_AMSEL_R = 0x00;
				break;
		case E: GPIO_PORTE_AHB_AMSEL_R = 0x00;
				break;
		case F: GPIO_PORTF_AHB_AMSEL_R = 0x00;
				break;
		case G: GPIO_PORTG_AHB_AMSEL_R = 0x00;
				break;
		case H: GPIO_PORTH_AHB_AMSEL_R = 0x00;
				break;
		case J: GPIO_PORTJ_AHB_AMSEL_R = 0x00;
				break;
		case K: GPIO_PORTK_AMSEL_R = 0x00;
				break;
		case L: GPIO_PORTL_AMSEL_R = 0x00;
				break;
		case M: GPIO_PORTM_AMSEL_R = 0x00;
				break;
		case N: GPIO_PORTN_AMSEL_R = 0x00;
				break;
		case P: GPIO_PORTP_AMSEL_R = 0x00;
				break;
		case Q: GPIO_PORTQ_AMSEL_R = 0x00;
				break;
		default: break;
	}
}
	
void clearPCTL(uint8_t port){
	switch(port){
		case A: GPIO_PORTA_AHB_PCTL_R = 0x00;
				break;
		case B: GPIO_PORTB_AHB_PCTL_R = 0x00;
				break;
		case C: GPIO_PORTC_AHB_PCTL_R = 0x1111;
				break;
		case D: GPIO_PORTD_AHB_PCTL_R = 0x00;
				break;
		case E: GPIO_PORTE_AHB_PCTL_R = 0x00;
				break;
		case F: GPIO_PORTF_AHB_PCTL_R = 0x00;
				break;
		case G: GPIO_PORTG_AHB_PCTL_R = 0x00;
				break;
		case H: GPIO_PORTH_AHB_PCTL_R = 0x00;
				break;
		case J: GPIO_PORTJ_AHB_PCTL_R = 0x00;
				break;
		case K: GPIO_PORTK_PCTL_R = 0x00;
				break;
		case L: GPIO_PORTL_PCTL_R = 0x00;
				break;
		case M: GPIO_PORTM_PCTL_R = 0x00;
				break;
		case N: GPIO_PORTN_PCTL_R = 0x00;
				break;
		case P: GPIO_PORTP_PCTL_R = 0x00;
				break;
		case Q: GPIO_PORTQ_PCTL_R = 0x00;
				break;
		default: break;
	}
}

void ioDirection(uint8_t port, uint32_t value){
	uint8_t temp;
	switch(port){
		case A: GPIO_PORTA_AHB_DIR_R = value;
				break;
		case B: GPIO_PORTB_AHB_DIR_R = value;
				break;
		case C: temp = GPIO_PORTC_AHB_DIR_R;
				value &= ~0x0f;
				temp &= ~0xf0;
				temp |= value;
				GPIO_PORTC_AHB_DIR_R = temp;
				break;
		case D: GPIO_PORTD_AHB_DIR_R = value;
				break;
		case E: GPIO_PORTE_AHB_DIR_R = value;
				break;
		case F: GPIO_PORTF_AHB_DIR_R = value;
				break;
		case G: GPIO_PORTG_AHB_DIR_R = value;
				break;
		case H: GPIO_PORTH_AHB_DIR_R = value;
				break;
		case J: GPIO_PORTJ_AHB_DIR_R = value;
				break;
		case K: GPIO_PORTK_DIR_R = value;
				break;
		case L: GPIO_PORTL_DIR_R = value;
				break;
		case M: GPIO_PORTM_DIR_R = value;
				break;
		case N: GPIO_PORTN_DIR_R = value;
				break;
		case P: GPIO_PORTP_DIR_R = value;
				break;
		case Q: GPIO_PORTQ_DIR_R = value;
				break;
		default: break;
	}
}

void clearAfsel(uint8_t port){
	uint8_t temp;
	switch(port){
		case A: GPIO_PORTA_AHB_AFSEL_R = 0x00;
				break;
		case B: GPIO_PORTB_AHB_AFSEL_R = 0x00;
				break;
		case C: temp = GPIO_PORTC_AHB_AFSEL_R;
				temp &= ~0xf0;
				GPIO_PORTC_AHB_AFSEL_R = temp;
				break;
		case D: GPIO_PORTD_AHB_AFSEL_R = 0x00;
				break;
		case E: GPIO_PORTE_AHB_AFSEL_R = 0x00;
				break;
		case F: GPIO_PORTF_AHB_AFSEL_R = 0x00;
				break;
		case G: GPIO_PORTG_AHB_AFSEL_R = 0x00;
				break;
		case H: GPIO_PORTH_AHB_AFSEL_R = 0x00;
				break;
		case J: GPIO_PORTJ_AHB_AFSEL_R = 0x00;
				break;
		case K: GPIO_PORTK_AFSEL_R = 0x00;
				break;
		case L: GPIO_PORTL_AFSEL_R = 0x00;
				break;
		case M: GPIO_PORTM_AFSEL_R = 0x00;
				break;
		case N: GPIO_PORTN_AFSEL_R = 0x00;
				break;
		case P: GPIO_PORTP_AFSEL_R = 0x00;
				break;
		case Q: GPIO_PORTQ_AFSEL_R = 0x00;
				break;
		default: break;
	}
}

void digitalEnable(uint8_t port,uint32_t value){
	uint8_t temp;
	switch(port){
		case A: GPIO_PORTA_AHB_DEN_R = value;
				break;
		case B: GPIO_PORTB_AHB_DEN_R = value;
				break;
		case C: temp = GPIO_PORTC_AHB_DEN_R;
				value &= ~0x0f;
				temp &= ~0xf0;
				temp |= value;
				GPIO_PORTC_AHB_DEN_R = temp;
				break;
		case D: GPIO_PORTD_AHB_DEN_R = value;
				break;
		case E: GPIO_PORTE_AHB_DEN_R = value;
				break;
		case F: GPIO_PORTF_AHB_DEN_R = value;
				break;
		case G: GPIO_PORTG_AHB_DEN_R = value;
				break;
		case H: GPIO_PORTH_AHB_DEN_R = value;
				break;
		case J: GPIO_PORTJ_AHB_DEN_R = value;
				break;
		case K: GPIO_PORTK_DEN_R = value;
				break;
		case L: GPIO_PORTL_DEN_R = value;
				break;
		case M: GPIO_PORTM_DEN_R = value;
				break;
		case N: GPIO_PORTN_DEN_R = value;
				break;
		case P: GPIO_PORTP_DEN_R = value;
				break;
		case Q: GPIO_PORTQ_DEN_R = value;
				break;
		default: break;
	}
}

void enablePullUp(uint8_t port, uint32_t value){
	uint8_t temp;
	switch(port){
		case A: GPIO_PORTA_AHB_PUR_R = value;
				break;
		case B: GPIO_PORTB_AHB_PUR_R = value;
				break;
		case C: temp = GPIO_PORTC_AHB_PUR_R;
				value &= ~0x0f;
				temp &= ~0xf0;
				temp |= value;
				GPIO_PORTC_AHB_PUR_R = temp;
				break;
		case D: GPIO_PORTD_AHB_PUR_R = value;
				break;
		case E: GPIO_PORTE_AHB_PUR_R = value;
				break;
		case F: GPIO_PORTF_AHB_PUR_R = value;
				break;
		case G: GPIO_PORTG_AHB_PUR_R = value;
				break;
		case H: GPIO_PORTH_AHB_PUR_R = value;
				break;
		case J: GPIO_PORTJ_AHB_PUR_R = value;
				break;
		case K: GPIO_PORTK_PUR_R = value;
				break;
		case L: GPIO_PORTL_PUR_R = value;
				break;
		case M: GPIO_PORTM_PUR_R = value;
				break;
		case N: GPIO_PORTN_PUR_R = value;
				break;
		case P: GPIO_PORTP_PUR_R = value;
				break;
		case Q: GPIO_PORTQ_PUR_R = value;
				break;
		default: break;
	}
}

uint32_t PortJ_Input(void)
{
	return GPIO_PORTJ_AHB_DATA_R;
}

uint32_t PortC_Input(void)
{
	return GPIO_PORTC_AHB_DATA_R;
}

void PortN_Output(uint32_t valor)
{
    uint32_t temp;
    temp = GPIO_PORTN_DATA_R & ~0x3;
    temp = temp | valor;
    GPIO_PORTN_DATA_R = temp; 
}

void PortK_Output(uint32_t valor)
{
    GPIO_PORTK_DATA_R = valor; 
}

void PortH_Output(uint32_t valor)
{
    uint32_t temp;
		valor &= ~0xfffffff0;
    temp = GPIO_PORTH_AHB_DATA_R & ~0x0f;
    temp = temp | valor;
    GPIO_PORTH_AHB_DATA_R = temp;
}

void PortL_Output(uint32_t valor)
{
    uint32_t temp;
	  valor &= ~0xfffffff0;
    temp = GPIO_PORTL_DATA_R & ~0x0f;
    temp = temp | valor;
    GPIO_PORTL_DATA_R = temp; 
}

void PortM_Output(uint32_t valor)
{
    uint32_t temp;
	  valor &= ~0xfffffff0;
    temp = GPIO_PORTM_DATA_R & ~0x0f;
    temp = temp | valor;
    GPIO_PORTM_DATA_R = temp; 
}

void PortE_Output(uint32_t valor)
{
    uint32_t temp;
	  valor &= ~0xfffffff0;
    temp = GPIO_PORTE_AHB_DATA_R & ~0x0f;
    temp = temp | valor;
    GPIO_PORTE_AHB_DATA_R = temp; 
}


void PortF_Output(uint32_t valor)
{
    uint32_t temp;
	  valor &= ~0xfffffff0;
    temp = GPIO_PORTF_AHB_DATA_R & ~0x0f;
    temp = temp | valor;
    GPIO_PORTF_AHB_DATA_R = temp; 
		

}


void PortF_TESTE(uint32_t valor)
{
    uint32_t temp;
	  valor &= ~0xfffffff0;
    temp = GPIO_PORTF_AHB_DATA_R & ~0x0f;
    temp = temp | valor;
    GPIO_PORTF_AHB_DATA_R = temp; 		

}





