//#include <xc.h>
//#include "TTIMER.h"
//#include "LCD.h"
//
//#pragma config OSC = HS //INTIO2
//#pragma config PBADEN = DIG
//#pragma config MCLRE = OFF
//#pragma config DEBUG = OFF
//#pragma config PWRT = OFF
//#pragma config BOR = OFF
//#pragma config WDT = OFF
//#pragma config LVP = OFF
//
//void HighInterruptRSI(void);
//void main(void);
//
//int tick_count;
////Important: NO es poden cridar les funcions d'interrupcions des del codi
////ja que les seves funcions de retorn en asm són diferents.
////Definició d'una interrupció d'alta prioritat. 
////void interrupt RSI_High(void){
////	
////}
//////Definició d'una interrupció de baixa prioritat.
////void interrupt low_priority RSI_Low(void) {
////	
////}
//
////includes de cada codi
////CONFIGS
//
//void main(void){
//    //INIT
//    LcInit(2, 16);
//    LcGotoXY(0,0);
//
//    while(1){
//        //MOTORS
//        LcPutChar('C');
//    }
//}