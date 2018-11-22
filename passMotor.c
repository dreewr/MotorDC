
#include "keyboard.h"
#include "gpio.h"
#include "utils.h"
#include "passMotor.h"

void passControll(int v){
	switch(v){
		case 1:
			PortH_Output(0x8);
			break;
		case 2:
			PortH_Output(0xC);
			break;
		case 3:
			PortH_Output(0x4);
			break;
		case 4:
			PortH_Output(0x6);
			break;
		case 5:
			PortH_Output(0x2);
			break;
		case 6:
			PortH_Output(0x3);
			break;
		case 7:
			PortH_Output(0x1);
			break;
		case 8:
			PortH_Output(0x9);
			break;
		
	}
}

void pass(int passes){
	int actualPass = 0;
    if(passes > 0){
        for(int i = 0; i<passes; i++){
            actualPass++;
					  SysTick_Wait1ms(10);
            if(actualPass > 8) actualPass = 1;
            passControll(actualPass);
        }
    }else if(passes < 0){
        for(int i = 0; i>passes; i--){ 
            actualPass--;
					  SysTick_Wait1ms(10);
            if(actualPass < 1) actualPass = 8; 
            passControll(actualPass);
        }
    }
}

void angle(int angle){
	pass((int) angle/(1.8/2));
}
