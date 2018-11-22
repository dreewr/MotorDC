


void ADC0_InitSWTriggerSeq3_Ch9(void){ volatile unsigned long delay;
	
	

  /**SYSCTL_RCGC2_R |= 0x00000010;   // 1) activate clock for Port E

  delay = SYSCTL_RCGC2_R;         //    allow time for clock to stabilize

  GPIO_PORTE_DIR_R &= ~0x04;      // 2) make PE4 input

  GPIO_PORTE_AFSEL_R |= 0x04;     // 3) enable alternate function on PE2

  GPIO_PORTE_DEN_R &= ~0x04;      // 4) disable digital I/O on PE2

  GPIO_PORTE_AMSEL_R |= 0x04;     // 5) enable analog function on PE2

  SYSCTL_RCGC0_R |= 0x00010000;   // 6) activate ADC0

  delay = SYSCTL_RCGC2_R;        

  SYSCTL_RCGC0_R &= ~0x00000300;  // 7) configure for 125K

  ADC0_SSPRI_R = 0x0123;          // 8) Sequencer 3 is highest priority

  ADC0_ACTSS_R &= ~0x0008;        // 9) disable sample sequencer 3

  ADC0_EMUX_R &= ~0xF000;         // 10) seq3 is software trigger

  ADC0_SSMUX3_R &= ~0x000F;       // 11) clear SS3 field

  ADC0_SSMUX3_R += 9;             //    set channel Ain9 (PE4)

  ADC0_SSCTL3_R = 0x0006;         // 12) no TS0 D0, yes IE0 END0

  ADC0_ACTSS_R |= 0x0008;         // 13) enable sample sequencer 3**/

}
void init_adc(){




}


void initGpioTest(){
/**1. Ativar o clock para a porta setando o bit correspondente no registrador
RCGCGPIO e, após isso, verificar no PRGPIO se a porta está pronta
para uso.
2. Desabilitar a funcionalidade analógica, limpando os bits no registrador
GPIO_PORTx_AMSEL_R
3. Selecionar a funcionalidade de GPIO limpando os bits no registrador
GPIO_PORTx_PCTL_R
4. Especificar se o pino é de entrada ou saída limpando ou setando,
respectivamente os bits no registrador GPIO_PORTx_DIR_R

5. Como o objetivo é utilizar os pinos como GPIO e não função alternativa
limpar os bits correspondentes no registrador GPIO_PORTx_AFSEL_R
	
6. Habilitar a funcionalidade de entrada e saída digital no registrador
GPIO_PORTx_DEN_R**/



}

