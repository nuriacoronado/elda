#include "TTECLAT.h"
#include "TTIMER.h"
#include "TMENU.h"
#include "TRECORDING.h"
#include "SIO.h"
#include "TEEPROM.h"
#include "CURRENT_TIME.h"
#include "LCD.h"
#include <xc.h>


 unsigned int mostres = 0;
 unsigned char estat_tad_recording = 0;
 unsigned char valor_micro_ADRESH = 0;
 unsigned char TimerRecordingADC = 0;
 unsigned char eeprom_adress = 0;
 unsigned char current_time_recording[5];
 unsigned char n = 0;
 unsigned char index[8][2];
 unsigned char index_gravacions = 0;
 
 unsigned int getMostresMicro(){
     return(mostres);
 }
 void initMicro(){
    TI_NewTimer(&TimerRecordingADC);
    TI_ResetTics (TimerRecordingADC);
    mostres = 0;
 }
 unsigned char getIndex (unsigned char gravacio, unsigned char posicio){
     return(index[gravacio][posicio]);
 }
void startTRecording(){
    estat_tad_recording = 1;
}
void endTRecording(){
    estat_tad_recording = 0;
}
void sendTimeStamp (){
    estat_tad_recording = 8;
}
unsigned char getTimeStampChar(unsigned char position){
    return(current_time_recording[position]);
}
void motorRecording(){
    switch (estat_tad_recording){
        case 0:         
            break;
        case 1:
            //startEEPROM();
            estat_tad_recording = 2;
            mostres = 0;
            break;
        case 2:
            if(waitForSend() == 1){
                estat_tad_recording = 3;
            }
            break;
        case 3:
            sendChar('D');
            estat_tad_recording = 4;
            break;
        case 4:
            ADCON0 = 0x09; // Canvia al canal 2 per fer servir el micro
            ADCON0bits.GODONE = 1;
            estat_tad_recording = 5;
            break;
        case 5:
            if(ADCON0bits.GODONE == 0){
                estat_tad_recording = 6;
                valor_micro_ADRESH = ADRESH;
            }   
            break;
        case 6:
            if(waitForSend() == 1){
                estat_tad_recording = 7;
            }
            break;
        case 7:
            if(TI_GetTics(TimerRecordingADC) >= 1 && mostres <= 32768){
                TI_ResetTics (TimerRecordingADC);
                sendChar(valor_micro_ADRESH);
                mostres++;
                estat_tad_recording = 4;
            }            
            break;
        case 8:
            n = 0;
            current_time_recording[4] = getSegons0()  + 0x30;
            current_time_recording[3] = getSegons1()  + 0x30;
            current_time_recording[2] = ':';
            current_time_recording[1] = getMinuts0()  + 0x30;
            current_time_recording[0] = getMinuts1() + 0x30;
            estat_tad_recording = 9;
            break;
        case 9:
            if(waitForSend() == 1){
                estat_tad_recording = 10;
            }
            break;
        case 10:
            sendChar(current_time_recording[n]);
            if(n < 4){
                estat_tad_recording = 9;
            }if(n >= 4){
                estat_tad_recording = 11;
                n = 0;
            }
            n++;
            break;
        case 11:
            if (checkIfRecieved() == 1){
                estat_tad_recording = 12;
            }
            break;
        case 12:
            if (compareCharRecieved('A') == 1){
                estat_tad_recording = 13;
            }
            break;
        case 13:
            if (checkIfRecieved() == 1){
                estat_tad_recording = 14;
            }
            break;
        case 14:
            index_gravacions = getTotalGravacions();
            if(index_gravacions == 8){
                index_gravacions = 0;
            }
            index[index_gravacions][0] = RCREG;
            estat_tad_recording = 15;
            break;
        case 15:
            if (checkIfRecieved() == 1){
                estat_tad_recording = 16;
            }
            break;
        case 16:
            index[index_gravacions][1] = RCREG;
            estat_tad_recording = 0;
            startEEPROMWrite();
            break;
        
    }
}