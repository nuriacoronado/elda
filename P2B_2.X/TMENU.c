#include "TMENU.h"
#include "LCD.h"
#include "SIO.h"
#include "TTECLAT.h"
#include "TJOYSTICK.h"
#include "CURRENT_TIME.h"
#include "TRECORDING.h"
#include "TTIMER.h"
#include "TALTAVEU.h"
#include "TEEPROM.h"
#include "TPLAY_RECORDING.h"
#include <xc.h>
#include <stdio.h>
#include <string.h>



unsigned char fila_play_recording = 0;
unsigned char joystick_down_counter = 0;
unsigned char eedata = 0;
unsigned char iterador_towername = 0;
unsigned char posicio_grabacio = 0;
unsigned char posicio_ensenyar_eeprom = 0;
unsigned int mostres_micro;
unsigned char temps_8s = 0;
unsigned char flag_TTeclat_menu = 1;
unsigned char arrModifyCurrentTimeMinuts[2];
unsigned char arrModifyCurrentTimeSegons[2];
unsigned char CurrentTimeComplet = 0;
unsigned char total_temps = 0;
unsigned char flag_modifyCurrentTime = 0;
unsigned char filamatriu_menu;
unsigned char hi_ha_tecla_menu = 0;
unsigned char estat_menu; 
unsigned char flag_menu;
unsigned char tower_name_position; 
unsigned char fila_matriu_menu; 
unsigned char flag_putstring;
unsigned char joystick_direction;
unsigned char flag_show_current_time = 0;
unsigned char flag_startmenu = 0;
unsigned char flag_towername = 0;
unsigned char TimerRecording;
unsigned char TimerMarquesina;
unsigned char timer_start_recording = 0;
unsigned char time_recording = 0;
unsigned char timer_2s = 0;
unsigned char time_recording_minuts = 0;
unsigned char time_recording_segons = 0;
unsigned char flag_CurrentTime_menu = 0;
unsigned char flag_tad_sio = 0;
unsigned int temps_grabacio = 0;
unsigned char pos_marq = 0;
unsigned char p = 0;
unsigned char iteracio_char = 0;
unsigned char posicio_caracter = 0;
unsigned char tower_name_menu[4];
//unsigned char tower_name_menu2[4];
unsigned char tower_name_menu0 = 0;
unsigned char tower_name_menu1 = 0;
unsigned char tower_name_menu2 = 0;
unsigned char marquesina_text[6][20] = {/*22 
1: LIST ACCESS POINTS  
2: SHOW CONN. STATUS
3: CHANGE CHAT MODE
4: ENTER CHAT MODE
5: LIST LAST MSGS.
6: CLOSE CONNECTION*/
        {'1', '.', 'L', 'I', 'S', 'T', ' ' ,'A', 'C', 'C', 'E', 'S', 'S' ,' ' ,'P', 'O','I', 'N', 'T', 'S'},
        {'2', '.', 'S', 'H', 'O', 'W', ' ' ,'C', 'O', 'N', 'N', '.' ,' ' ,'S', 'T','A', 'T', 'U', 'S', ' '},
        {'3', '.', 'C', 'H', 'A', 'N', 'G' ,'E', ' ', 'C', 'H', 'A' ,'T' ,' ', 'M','O', 'D', 'E', ' ', ' '},
        {'4', '.', 'E', 'N', 'T', 'E', 'R', ' ', 'C', 'H', 'A','T', ' ','M', 'O', 'D', 'E', ' ', ' ', ' '},
        {'5', '.', 'L', 'I', 'S', 'T', ' ', 'L', 'A', 'S', 'T',' ', 'M','S', 'G', 'S', '.', ' ', ' ', ' '},
        {'6', '.', 'C', 'L', 'O', 'S', 'E', ' ', 'C', 'O', 'N','N', 'E','C', 'T', 'I', 'O', 'N', ' ', ' '},
};

//PRACTICA 2 VARS///////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned char dest_port[4];
unsigned char rec_port[4];
unsigned char user_name[3];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void augmentaPosCaracter (){
    if (iteracio_char + pos_marq == 22){
        posicio_caracter = 0;
    }
    if (iteracio_char + pos_marq < 22) {
        posicio_caracter = iteracio_char + pos_marq;
    }
    
    if (iteracio_char + pos_marq > 22) {
        posicio_caracter = iteracio_char + pos_marq - 22;
    }
}


void esperaMarq(unsigned char estat){
    if(TI_GetTics(TimerMarquesina) >= 4000){
        TI_ResetTics (TimerMarquesina);
        augmentaPosMarq();
        estat_menu = estat;
        iteracio_char = 0;
        augmentaPosCaracter();
    }
}
void compareJoystickDir(unsigned char direction, unsigned char estat){
    joystick_direction = getJoyDirection();
    if (joystick_direction == direction){
        LcGotoXY(0, 0);
        LcClear();
        estat_menu = estat;
    }
}

void augmentaPosMarq (){
    pos_marq++;
    if (pos_marq == 22){
       pos_marq = 0; 
    }
}
void Menu_Init () {
    estat_menu = 0;
    flag_putstring = 0;
    flag_startmenu = 0;  
    TI_NewTimer(&TimerRecording);
    TI_ResetTics (TimerRecording);
    TI_NewTimer(&TimerMarquesina);
    TI_ResetTics (TimerMarquesina);
    TI_NewTimer(&timer_2s);
    TI_ResetTics (timer_2s);
    tower_name_position = 0;
}

char getFlagShowCurrentTime(){
    return(flag_show_current_time);
}
unsigned char getJoystickDownCounter(){
    return(joystick_down_counter);
}
unsigned char getCurrentTime(){
    return(flag_CurrentTime_menu);
}

unsigned char Getflag_TTeclat(){
    return(flag_TTeclat_menu);
}

unsigned char getFlagMenu(){
    return(flag_menu);
}

//unsigned char getFlagPreeMenu(){
//    return(flag_preemenu);
//}


void motorMenu (){
    switch (estat_menu){
        case 0:
            if (flag_putstring == 0){
                flag_putstring = MyPutString("DEST.PORT:");
            }else{
                estat_menu = 1;
                LcGotoXY(0, 1);
                flag_putstring = 0;
            }
            break;
        case 1: // llenan la lcd del dest.port
            if(getCaractersEscrits() == 3){
                estat_menu = 2;
                //guardar los 4 digitos
            }
            break;
        case 2: //guardar los 4 digitos
            dest_port[0] = getTowerName(0);
            dest_port[1] = getTowerName(1);
            dest_port[2] = getTowerName(2);
            dest_port[3] = getTowerName(3);
            
            estat_menu = 3; 
            
            LcClear();
            LcGotoXY(0, 0);
            break;
        case 3:
            
            if (flag_putstring == 0){
                flag_putstring = MyPutString("REC.PORT:");
            }else{
                estat_menu = 4;
                LcGotoXY(0, 1);
                flag_putstring = 0;
            }
            break;
        case 4:// esperamos a llenar el rec.port
            
            if((getCaractersEscrits() == 3) && (getEspera() == 1)){
                estat_menu = 5; 
                //guardar los 4 digitos
            }
            break;
        case 5:
            
            rec_port[0] = getTowerName(0);
            rec_port[1] = getTowerName(1);
            rec_port[2] = getTowerName(2);
            rec_port[3] = getTowerName(3);
            
            estat_menu = 6; 
            
            LcClear();
            LcGotoXY(0, 0);
            
            break;
        case 6:
            
            if (flag_putstring == 0){
                flag_putstring = MyPutString("USER NAME:");
            }else{
                estat_menu = 7;
                LcGotoXY(0, 1);
                flag_putstring = 0;
            }
            break; 
        case 7:
            if(getCaractersEscrits() == 2){
                estat_menu = 8; 
                //guardar los 3 digitos
            }
            break;
        case 8:
            user_name[0] = getTowerName(0);
            user_name[1] = getTowerName(1);
            user_name[2] = getTowerName(2);
            
            estat_menu = 9; 
            
            LcClear();
            LcGotoXY(0, 0);
            break;
        case 9:
            
            
            
            
            LcClear();
            break;
        case 10:
            //
            LcClear();
            LcClear();
             LcClear();
            LcClear();
            break;
}
}

