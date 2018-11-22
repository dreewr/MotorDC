/**=============================================================================
// keyboard4x4.s
// Luís Henrique Beltrão Santana
// 25/10/2018
=============================================================================**/

#ifndef __GPIO__
#define __GPIO__

#include <stdint.h>
#include "tm4c1294ncpdt.h"

#define P0 0x1
#define P1 0x2
#define P2 0x4
#define P3 0x8
#define P4 0x10
#define P5 0x20
#define P6 0x40
#define P7 0x80
#define P_ALL 0xFF
#define P_NONE 0x0

#define A (0x10)
#define B (0x20)
#define C (0x30)
#define D (0x40)
#define E (0x50)
#define F (0x60)
#define G (0x70)
#define H (0x80)
#define J (0x90)
#define K (0xA0)
#define L (0xB0)
#define M (0xC0)
#define N (0xD0)
#define P (0xE0)
#define Q (0xF0)

#define GPIO_PORTA (0x0001)
#define GPIO_PORTB (0x0002)
#define GPIO_PORTC (0x0004)
#define GPIO_PORTD (0x0008)
#define GPIO_PORTE (0x0010)
#define GPIO_PORTF (0x0020)
#define GPIO_PORTG (0x0040)
#define GPIO_PORTH (0x0080)
#define GPIO_PORTJ (0x0100)
#define GPIO_PORTK (0x0200)
#define GPIO_PORTL (0x0400)
#define GPIO_PORTM (0x0800)
#define GPIO_PORTN (0x1000)
#define GPIO_PORTP (0x2000)
#define GPIO_PORTQ (0x4000)

//função legada
void GPIO_Init(void);
/**=============================================================================
 *	Funções de inicialização para configurar as GPIOs
=============================================================================**/

/**
 *  1. Ativar o clock para a(s) porta(s) necessária(s)
**/
void EnableGpio(uint32_t port);

/**
 *  2. desativar modo analógico das portas
**/
void clearAmsel(uint8_t port);

/**
 *  3. limpar PCTL
**/
 void clearPCTL(uint8_t port);

/**
 *  4. selecionar direção da porta [input | output]
**/
 void ioDirection(uint8_t port, uint32_t value);

/**
 *  5. selecionar GPIO sem função alternativa
**/
 void clearAfsel(uint8_t port);

/**
  *  6. habilitar a porta como digital
 **/
void digitalEnable(uint8_t port, uint32_t value);

/**
 *  7. habilita o resistor de Pull Up
**/
void enablePullUp(uint8_t port, uint32_t value);

/**=============================================================================
 *
=============================================================================**/


uint32_t PortC_Input(void);
uint32_t PortJ_Input(void);
void PortN_Output(uint32_t valor);
void PortH_Output(uint32_t valor);
void PortK_Output(uint32_t valor);
void PortL_Output(uint32_t valor);
void PortM_Output(uint32_t valor);


//Criadas
void PortE_Output(uint32_t valor);
void PortF_Output(uint32_t valor);
void PortF_TESTE(uint32_t valor);

#endif
