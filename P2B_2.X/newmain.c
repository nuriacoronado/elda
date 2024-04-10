#include <xc.h>
#include "TTIMER.h"
#include "LCD.h"
#include "TMENU.h"
#include "TTECLAT.h"
#include "TJOYSTICK.h"
#include "SIO.h"
#include "CURRENT_TIME.h"
#include "TALTAVEU.h"
#include "TRECORDING.h"
#include "TEEPROM.h"
#include "TPLAY_RECORDING.h"

#pragma config OSC = INTIO1 //32
#pragma config PBADEN = DIG
#pragma config MCLRE = OFF
#pragma config DEBUG = OFF
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config WDT = OFF
#pragma config LVP = OFF

void __interrupt() my_interrupts(void){
    RSI_Timer0();
    
}

void InitconfOsc(){ 
    //CAMBIO A 16M 
    /*OSCCONbits.IDLEN = 0; //b'01100000'
    OSCCONbits.IRCF2 = 1; //b'01100000'
    OSCCONbits.IRCF1 = 1; //b'01100000'
    OSCCONbits.IRCF0 = 0; //b'01100000'
    OSCCONbits.SCS1 = 0; //b'01100000'
    OSCCONbits.SCS0 = 0; //b'01100000'*/
    OSCCON = 0x60;
    OSCTUNE = 0x40; // b'01000000'

}
//void main(void);

//int tick_count;
//Important: NO es poden cridar les funcions d'interrupcions des del codi
//ja que les seves funcions de retorn en asm són diferents.
//Definició d'una interrupció d'alta prioritat. 
//void interrupt RSI_High(void){
	
//}
////Definició d'una interrupció de baixa prioritat.
//void interrupt low_priority RSI_Low(void) {
	
//}

//includes de cada codi
//CONFIGS

void  main(void){
    //INIT
    InitconfOsc();
    TI_Init();
    Menu_Init(); 
    LcInit(2, 16);
    initTeclat();
    LcGotoXY(0,0);
    ADC_Init();
    InitAltaveu();
    sioInit();
    initMicro();
    initEEPROM();
    
    while(1){
        //MOTORS
        motorMenu();
        motorTeclat();
        motorJoy();
        //motorShowCurrentTime();
        //motorAltaveu();
        //motorRecording();
        //motorEEPROM();
        //motorPlayRecording();
    }
}