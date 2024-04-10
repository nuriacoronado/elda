#include <xc.h>
#include <stdio.h>
#include "TTIMER.h"


unsigned char estat_sio;
unsigned char flag_tad_sio ;
unsigned char flag_startmenu_sio;
unsigned char flag;

void sioInit(){
    estat_sio = 0;
    flag_tad_sio = 0;
    
    TRISCbits.TRISC6 = 1;
    TRISCbits.TRISC7 = 1;
    
    TXSTA = 0x26;
    RCSTA = 0x90;
    BAUDCONbits.BRG16 = 1;
    SPBRG = 68; //cambiar para 16M
    SPBRGH = 0;
    
}

unsigned char waitForSend(){
    flag = 0;
    if(TXSTAbits.TRMT == 1){
        flag = 1;
    }
    return(flag);
}
void sendChar(char caracter){
    TXREG = caracter;    
}
unsigned char checkIfRecieved(){
    flag = 0;
    if(PIR1bits.RCIF){ // Hem rebut algo
        flag = 1;
    }
    return(flag);
}
unsigned char compareCharRecieved(char caracter){
    flag = 0;
    if(RCREG == caracter){
        flag = 1;
    }
    return(flag);
}