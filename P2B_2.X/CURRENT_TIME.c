#include <xc.h>
#include <stdio.h>
#include <string.h>
#include "TTIMER.h"
#include "TMENU.h"
#include "LCD.h"

unsigned char estat_ct;
unsigned long TimerCurrentTime = 0;
unsigned char digit_segons_0 = 0;
unsigned char digit_segons_1 = 0;
unsigned char digit_minuts_0 = 0;
unsigned char digit_minuts_1 = 0;
unsigned long current_tics_x;
unsigned char flag_CurrentTime = 0;
unsigned char segons0_menu = 0;
unsigned char segons1_menu = 0;
unsigned char minuts0_menu = 0;
unsigned char minuts1_menu = 0;
unsigned char flag_putstring_current = 0;

void startCurrentTime(){
    estat_ct = 1;
}
unsigned char getSegons0 (){
    return(digit_segons_0);
}
unsigned char getSegons1 (){
    return(digit_segons_1);
}
unsigned char getMinuts0 (){
    return(digit_minuts_0);
}
unsigned char getMinuts1 (){
    return(digit_minuts_1);
}
void putSegons0(unsigned char digit){
    digit_segons_0 = digit;
    segons0_menu = digit;
}
void putSegons1(unsigned char digit){
    digit_segons_1 = digit;
    segons1_menu = digit;
}
void putMinuts0(unsigned char digit){
    digit_minuts_0 = digit;
    minuts0_menu = digit;
}
void putMinuts1(unsigned char digit){
    digit_minuts_1 = digit;
    minuts1_menu = digit;
}
void InitCurrentTime(){
    TI_NewTimer(&TimerCurrentTime);
    
}
void motorShowCurrentTime(){
    switch (estat_ct){
        case 0:
            break;
        case 1:
            TI_ResetTics(TimerCurrentTime);
            estat_ct = 2;
            break;
        case 2:
            current_tics_x = TI_GetTics(TimerCurrentTime);
            if (current_tics_x > 4000){
                estat_ct = 3;
            }
            break;
        case 3:
            flag_CurrentTime = getCurrentTime();
            if(flag_CurrentTime){
                LcClear();
            }           
            estat_ct = 4;
            break;
        case 4:
            flag_CurrentTime = getCurrentTime();
            if(flag_CurrentTime){
                if (flag_putstring_current == 0){
                    flag_putstring_current = MyPutString("CURRENT TIME:"); 
                }
                if (flag_putstring_current == 1){
                     LcGotoXY(0, 1);
                     flag_putstring_current = 0;
                     estat_ct = 5;
                }
            }else{
                estat_ct = 5;
            }
            break;
        case 5:
            flag_CurrentTime = getCurrentTime();
            if(flag_CurrentTime){
                segons0_menu = getSegons0();
                segons0_menu = segons0_menu + 0x30;
                segons1_menu = getSegons1();
                segons1_menu = segons1_menu + 0x30;
                minuts0_menu = getMinuts0();
                minuts0_menu = minuts0_menu + 0x30;
                minuts1_menu = getMinuts1();
                minuts1_menu = minuts1_menu + 0x30;
                LcPutChar(minuts1_menu);
                LcPutChar(minuts0_menu);
                LcPutChar(':');
                LcPutChar(segons1_menu);
                LcPutChar(segons0_menu);
            }
            if (digit_segons_0 != 0){
                digit_segons_0--;
                estat_ct = 1;
            }else{
                digit_segons_0 = 9;
                estat_ct = 6;
            }
            
            break;
        case 6:
            if (digit_segons_1 != 0){
                digit_segons_1--;
                estat_ct = 1;
            }else{
                digit_segons_1 = 5;
                estat_ct = 7;
            }
            break;
        case 7:
            if (digit_minuts_0 != 0){
                digit_minuts_0--;
                estat_ct = 1;
            }else{
                digit_minuts_0 = 9;
                estat_ct = 8;
            }
            break;
        case 8:
            if (digit_minuts_1 != 0){
                digit_minuts_1--;
                estat_ct = 1;
            }else{
                digit_minuts_1 = 5;
                estat_ct = 1;
            }
            break;
       
    }
}
