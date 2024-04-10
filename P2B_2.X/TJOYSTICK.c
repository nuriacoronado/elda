
#include <xc.h>
#include <stdio.h>
#include "LCD.h"
#include "TTIMER.h"

unsigned char estat_joy;
unsigned char joy_direction;
unsigned char valor_ADRESH;



void ADC_Init(){
    TRISAbits.TRISA1 = 1;
	ADCON0 = 0x05; 
	ADCON1 = 0x0C; //b'00001100' ; Idle, 3 pins analog
	ADCON2 = 0x09; //Left justified, AD Time (No hpll)
}
char getJoyDirection(){
    return(joy_direction);
}
void motorJoy(){
    switch (estat_joy){
        case 0:
            //flag_portname = getFlagPortname();
            //if(flag_portname){
                estat_joy = 1; 
                ADCON0bits.GODONE = 1;
            //}
                break;
        case 1: //godone
            if (ADCON0bits.GODONE == 0){
                estat_joy = 2;
                valor_ADRESH = ADRESH;
            }
            break;
//ADRESH PONE SIEMPRE QUE ES MAS GRANDE DE 200, (es decir, algo imposible)
        case 2:
            if(valor_ADRESH < 70){
                joy_direction = 'U';
                estat_joy = 0;
            }else{
                estat_joy = 3;
            }
            
            break;
        case 3:
            if(valor_ADRESH > 180){ //esta adalt
                joy_direction = 'D';
                estat_joy = 0;
            }else{
                estat_joy = 4;                
            }
            break;
        case 4:
            joy_direction = 'M';
            estat_joy = 0;
            break;
    }        
}