#include "TMENU.h"
#include "SIO.h"
#include "TRECORDING.h"
#include "TEEPROM.h"
#include "TALTAVEU.h"
#include <xc.h>


unsigned char estat_play = 0;
unsigned char gravacio_reprduir_id = 0;
unsigned char index0_playrec = 0;
unsigned char flag_end_playing = 0;


void startPlayRecording(){
    estat_play = 1;
}
unsigned char getFlagEndPlaying(){
    return(flag_end_playing);
}
void motorPlayRecording(){
    switch(estat_play){
        case 0:
            
            break;
        case 1:
            flag_end_playing = 0;
            if(waitForSend() == 1){
                estat_play = 2; 
            }
            break;
        case 2:
            sendChar('P');
            estat_play = 3; 
            break;
        case 3:
            if(checkIfRecieved() == 1){
                estat_play = 4; 
            }
            break;
        case 4:
            if(compareCharRecieved('K') == 1){
                estat_play = 5;
            }
            break;
        case 5:
            if(waitForSend() == 1){
                estat_play = 6; 
            }
            break;
        case 6:
            gravacio_reprduir_id = getJoystickDownCounter();
            index0_playrec = getIndex(gravacio_reprduir_id,0);
            if (index0_playrec != 0){
                sendChar(index0_playrec);
            }
            estat_play = 7; 
            break;
        case 7:
            if(waitForSend() == 1){
                estat_play = 8; 
            }
            break;
        case 8:
            sendChar(getIndex(gravacio_reprduir_id,1));
            estat_play = 9;
            break;
        case 9:
            if(waitForSend() == 1){
                estat_play = 10; 
            }
            break;
        case 10:
            sendChar('\0');
            estat_play = 11;
            break;
        case 11:
            if(checkIfRecieved() == 1){
                estat_play = 12; 
            }
            break;
        case 12:
            if(compareCharRecieved('F') == 1){
                estat_play = 13;
                //Melody();
            }else{
                estat_play = 11;
            }
            break;
        case 13:
            flag_end_playing = 1;
            
            break;
    }
    
}
