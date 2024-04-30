/*
 * File:   TWIFI.c
 * Author: Eldaf
 *
 * Created on 10 / d?abril / 2024, 13:45
 */
#include <xc.h>
#include "TWIFI.h"
#include "TTIMER.h"
#include "pic18f4321.h"

unsigned char EstatTX=0;
unsigned char EstatRC=0;
unsigned char TX_REG=0;
unsigned char RC_REG=0;
unsigned char STARTBIT=0;
unsigned char SENDING=0;
unsigned char COMPTADOR=0;
unsigned char COMPTADOR1=0;
unsigned char TimerTX;
unsigned char TimerRC;
unsigned char estatsendfrase=0;
unsigned char estatReceivefrase=0;
unsigned char typecharacter=0;
unsigned int j = 0;
unsigned int k = 0;
unsigned char RECEIVING = 0; 
unsigned char STARTBITR = 0; 
unsigned char variable = 0; 
char *Rcfrase ; 


void initWIFI(){
    TRISDbits.RD0 = 0;
    TRISAbits.RA4 = 0;
    TRISDbits.RD1 = 1;
    TI_NewTimer(&TimerTX);
    TI_ResetTics (TimerTX);
    TI_NewTimer(&TimerRC);
    TI_ResetTics (TimerRC);
    LATDbits.LATD0 = 1;
    LATAbits.LATA4 = 0;
    EstatTX = 0; 
    COMPTADOR = 0;
    RECEIVING = 0;
}

unsigned char sendFrase(char frase[]){
    switch(estatsendfrase){
        case 0:            
            if(ReadyToSend() == 1 & typecharacter == 0){
                estatsendfrase = 1;
            }
            if(ReadyToSend() == 1 & typecharacter != 0){
                //LATAbits.LATA4 = 1;
                estatsendfrase = 2;
            }
            //LATAbits.LATA4 = 1;
            return(0);
            break;
        case 1:
            if(frase[j]!='\0'){
                CargarTX(frase[j]);
                j++;
                typecharacter = 0;
            }
            if(frase[j]=='\0'){
                typecharacter = 1;
            }
            estatsendfrase = 0;
            return(0);
            break;
        case 2:
            if(typecharacter == 1){
                CargarTX('\r');
                typecharacter = 2;
                estatsendfrase = 0;
                return(0);
            }
            if(typecharacter == 2){
                //LATAbits.LATA4 = 1;
                CargarTX('\n');
                typecharacter = 0;
                j=0;
                estatsendfrase = 0;
                return (1);
            }
            break;
    }
}


void CargarTX(char CHARACTER) {
    TX_REG = CHARACTER;
    STARTBIT=1;
    TI_ResetTics (TimerTX);
    COMPTADOR = 0;
}

void MotorTX(void) {
    switch(EstatTX){
        case 0:
            if(TI_GetTics (TimerTX) >= 2){
                //LATAbits.LATA4 = 0;
                EstatTX = 1;
            }else {
                EstatTX = 0;
            }
            break;    
        case 1:
            if(STARTBIT == 0 & SENDING == 0){
                TI_ResetTics (TimerTX);
                EstatTX = 0;
            }
            if(SENDING == 1){
                EstatTX = 2;
            }
            if(STARTBIT == 1){
                //LATAbits.LATA4 = 0;
                //LATAbits.LATA4 = 1;
                LATDbits.LATD0 = 0;
                SENDING = 1;
                STARTBIT = 0;  
                TI_ResetTics (TimerTX);
                EstatTX = 0;
            }
            break;
        case 2 : 
            LATDbits.LATD0 = TX_REG & 0x01;
            //LATDbits.LATD0 = 0;
            //LATAbits.LATA4 = 0;
            TX_REG >>= 1;
            COMPTADOR = COMPTADOR + 1;
            if(COMPTADOR > 8){
                COMPTADOR = 0;
                SENDING = 0;
                STARTBIT = 0; 
                LATDbits.LATD0 = 1;
                //LATAbits.LATA4 = 0;
            }
            EstatTX = 0;
            TI_ResetTics (TimerTX);
            break; 
    } 
}
unsigned char ReadyToSend(void) {
    if(STARTBIT == 0 & SENDING == 0){
        return(1);
    }else{
        return(0);
    }
}

unsigned char ReadyToRecieve(void) {
    if(LATDbits.LATD1 == 0 & RECEIVING == 0){
        return(1);
    }
    if(RECEIVING == 1){
        return(1);
    }else{
        return(0);
    }
}

//char *Receive_frase (){
//    switch(estatReceivefrase){
//        case 0:
//            if(ReadyToRecieve == 1 & RECEIVING == 0){
//                estatReceivefrase = 1; 
//            }
//            if(ReadyToRecieve == 1 & RECEIVING == 1){
//                estatReceivefrase = 2; 
//            }
//            break;
//        case 1:
//            RECEIVING = 1; 
//            COMPTADOR1 = 0; 
//            estatReceivefrase = 0;   
//            TI_ResetTics (TimerRC);
//            //EstatRC = 0;
//            break;
//        case 2:
//            if(MotorRC() == 1){
//                variable = Extract_RC();
//                if(variable == '\r'){
//                    Rcfrase[k] = '\0';
//                    k=0;
//                    RECEIVING = 0;
//                    estatReceivefrase = 0; 
//                    return (Rcfrase);
//                }else{
//                    Rcfrase[k]= variable;
//                    k++;
//                }
//            }
//            estatReceivefrase = 0;
//            break;
//    }
//    
//}
unsigned char MotorRC(void) {
    switch(EstatRC){
        case 0:
//            LATAbits.LATA4 = 0;
            if(TI_GetTics (TimerRC) >= 2 && RECEIVING == 1){
                //LATAbits.LATA4 = 0;
//                LATAbits.LATA4 = 1;
//                LATAbits.LATA4 = 0;
//                LATAbits.LATA4 = 1;
//                LATAbits.LATA4 = 0;
//                LATAbits.LATA4 = 1;
//                LATAbits.LATA4 = 0;
//                RC_REG &= 0xFE; // Clear the lowest bit of RC_REG
//                RC_REG |= ((PORTD >> 1) & 0x01); // Assign the value of RD1 to the lowest bit of RC_REG
//                RC_REG <<= 1;
                RC_REG &= 0x7F;
                RC_REG |= ((PORTD << 6) & 0x80);
                RC_REG >>= 1;
                //RC_REG = (RC_REG>>1)|(RC_REG<<7);
                COMPTADOR1++;
                if(COMPTADOR1 >= 7){
                    COMPTADOR1 = 0;
                    RECEIVING = 0;
                    EstatRC = 1;
                    TI_ResetTics (TimerRC);
                    return(1);
                }else{
                    EstatRC = 0; 
                    TI_ResetTics (TimerRC);
                }
                
            }
            if(RECEIVING == 0 && PORTDbits.RD1 == 0){
                    LATAbits.LATA4 = 1;
                    LATAbits.LATA4 = 0;
                    RECEIVING = 1; 
                    COMPTADOR1 = 0;
                    EstatRC = 1;
                    TI_ResetTics (TimerRC);  
                }
            return(0);
            break; 
        case 1:
            if(RECEIVING==0){
                if(TI_GetTics (TimerRC) >= 1){
                    
                //LATAbits.LATA4 = 0;
                    EstatRC = 0;
                    TI_ResetTics (TimerRC);
                    
                }
            }else{
                if(TI_GetTics (TimerRC) >= 1){
                    LATAbits.LATA4 = 1;
                    LATAbits.LATA4 = 0;
                    LATAbits.LATA4 = 1;
                    LATAbits.LATA4 = 0;
                //LATAbits.LATA4 = 0;
                    EstatRC = 0;
                    TI_ResetTics (TimerRC);
                }
            }
            return(0);
            break;
    }
}
unsigned char Extract_RC (void){
    return(RC_REG); 
}

