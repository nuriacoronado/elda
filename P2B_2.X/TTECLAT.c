#include "TTECLAT.h"
#include "TMENU.h"
#include "TTIMER.h"
#include "LCD.h"
#include <xc.h>

unsigned char flag_preemenu = 0;
unsigned char flagAltaveu_teclat = 0;
unsigned char flag_TTeclat = 1;
unsigned char caracters_escrits_menu;
unsigned char estat_teclat;
unsigned char rows;
unsigned char fase_escombrat;
unsigned char hi_ha_tecla;
unsigned char columna_polsada;
unsigned char caracter_actual;
unsigned char TimerRebots;
unsigned char Timer1S;
unsigned char espera;
unsigned long timer_tics;
unsigned long timer_tics_1s;
unsigned char caracters_escrits;
unsigned char fila_matriu;
unsigned char old_fila_matriu;
unsigned char tower_name[4];
unsigned char matriu_teclat[11][6] = {
        {'1', '\0', '\0', '\0', '\0', '\0'},
        {'A' ,'B' ,'C', '2','\0', '\0'},
        {'D','E','F','3','\0', '\0'},
        {'G','H','I','4','\0', '\0'},
        {'J','K','L','5', '\0', '\0'},
        {'M','N','O','6', '\0', '\0'},
        {'P','Q','R', 'S', '7', '\0'},
        {'T','U','V', '8', '\0', '\0'},
        {'W','X','Y','Z','9', '\0'},
        {'*', '\0', '\0', '\0', '\0', '\0'},
        {'0', ' ','\0','\0','\0', '\0'},
        {'#', '\0', '\0', '\0', '\0', '\0'}
};

void initTeclat(){
    rows = 0x08;//b'00001000';
    caracters_escrits = 0;
    TI_NewTimer(&TimerRebots);
    TI_NewTimer(&Timer1S);
    TI_ResetTics (Timer1S);
    SetColumns_Entrada();
    SetRows_Sortida();
    estat_teclat = 0;
    hi_ha_tecla = 0;
    caracters_escrits = -1;
    espera = 0;
    
}
unsigned char getHiHatecla(){
    return(hi_ha_tecla);
} 
unsigned char getTowerName(unsigned char p){
    return(tower_name[p]);
}
unsigned char getCaractersEscrits (){
    return(caracters_escrits_menu);
}

unsigned char getEspera(){
    return(espera);
}
void setFiles (char rows){
    
    if (rows == 0x01){ // b'00000001'
        LATCbits.LATC1 = 1;
        LATEbits.LATE1 = 0;
        LATCbits.LATC5 = 0;
        LATCbits.LATC3 = 0;
    }
    if (rows == 0x02){ // b'00000010'
        LATCbits.LATC1 = 0;
        LATEbits.LATE1 = 1; //SIO
        LATCbits.LATC5 = 0;
        LATCbits.LATC3 = 0;
    }
    if (rows == 0x04){ // b'00000100'
        LATCbits.LATC1 = 0;
        LATEbits.LATE1 = 0;
        LATCbits.LATC5 = 1;
        LATCbits.LATC3 = 0;
    }
    if (rows == 0x08){ // b'00001000'
        LATCbits.LATC1 = 0;
        LATEbits.LATE1 = 0;
        LATCbits.LATC5 = 0;
        LATCbits.LATC3 = 1;
    }
    
}

unsigned char comprovaHiHaColumna (){
    hi_ha_tecla = 0;
    
    if (PORTCbits.RC2 == 1){ // Si s'ha pulsat COLUMNA 1
        columna_polsada = 0x01; //b'00000001';
        hi_ha_tecla = 1;
    }
    if (PORTCbits.RC0 == 1){ // Si s'ha pulsat COLUMNA 2
        columna_polsada = 0x02; //b'00000010';
        hi_ha_tecla = 1;
    }
    if (PORTCbits.RC4 == 1){ // Si s'ha pulsat COLUMNA 3
        columna_polsada = 0x04; //b'00000100';
        hi_ha_tecla = 1;
    }
    return(columna_polsada);
}

void saveTecla(){
    //reset 1s i si es altre tecla
    if (rows == 0x01){
        if (columna_polsada == 0x01){ // 1a fila 1a columna
            fila_matriu = 0;
        }
        if (columna_polsada == 0x02){ //F1 C2
            if (caracter_actual == 3){
                caracter_actual = 0;
            }else{
                caracter_actual++;
            }
            fila_matriu = 1;
        }
        if (columna_polsada == 0x04){ //F1 C2
            if (caracter_actual == 3){
                caracter_actual = 0;
            }else{
                caracter_actual++;
            }
            fila_matriu = 2;
        }
        
    }
    if (rows == 0x02){
        if (columna_polsada == 0x01){ //F1 C2
            fila_matriu = 3;
        }
        if (columna_polsada == 0x02){ //F1 C2
            fila_matriu = 4;
        }
        if (columna_polsada == 0x04){ //F1 C2
            fila_matriu = 5;
        }
        if (caracter_actual == 3){
                caracter_actual = 0;
            }else{
                caracter_actual++;
            }
        
    }
    if (rows == 0x04){
        if (columna_polsada == 0x01){ //F1 C2
            fila_matriu = 6;
        }
        if (columna_polsada == 0x02){ //F1 C2
            fila_matriu = 7;
        }
        if (columna_polsada == 0x04){ //F1 C2
            fila_matriu = 8;
        }
        if (caracter_actual == 3){
                caracter_actual = 0;
            }else{
                caracter_actual++;
            }
    }
    if (rows == 0x08){ //nou nunu
        if (columna_polsada == 0x01){ //*
            caracter_actual = 0;
            fila_matriu = 9;
        }
        if (columna_polsada == 0x02){ //0
            if (caracter_actual == 1){
                caracter_actual = 0;
            }else{
                caracter_actual++;
            }
            fila_matriu = 10;
        }
        if (columna_polsada == 0x04){ //#
            fila_matriu = 11;
            //flag_sio = 1;
        }
        
    }
}

unsigned char getFilamatriu(){
    return(fila_matriu);
}

void writeCaracter(){
    timer_tics_1s = TI_GetTics (Timer1S);
    
    if (timer_tics_1s < 4000){
        LcGotoXY(caracters_escrits, 1);
       
    }
    
    if(timer_tics_1s > 4000){
        caracters_escrits++;
        caracters_escrits_menu = caracters_escrits;
       
    }
    if(matriu_teclat[fila_matriu][caracter_actual] == '\0'){
        caracter_actual = 1;
    }
    if(caracters_escrits == 4){
        caracters_escrits_menu = 0;
        caracters_escrits = -1; //ERA -1
        flag_preemenu = 1;
        espera = 1;
    }else{
        if(caracters_escrits < 4){
            LcPutChar(matriu_teclat[fila_matriu][caracter_actual]); 
        }
    }
    estat_teclat = 4;
}
void putFilaMatriu12 (){
    fila_matriu = 12;
}
void waitTeclaTreta(){
    if(PORTCbits.RC2 == 0 && PORTCbits.RC0 == 0 && PORTCbits.RC4 == 0){
        estat_teclat = 6;
    }
}

void motorTeclat (){
    switch (estat_teclat){
        case 0:
            rows = 0x01; //b'00000001';
            setFiles(rows);
            estat_teclat = 1;
            columna_polsada = comprovaHiHaColumna();
            if (hi_ha_tecla == 1){
                flagAltaveu_teclat = 1;
                estat_teclat = 4;
                TI_ResetTics (TimerRebots);
            }
        break;
        case 1:
            rows = 0x02; //b'00000010';
            setFiles(rows);
            estat_teclat = 2;
            columna_polsada = comprovaHiHaColumna();
            if (hi_ha_tecla){
                flagAltaveu_teclat = 1;
                estat_teclat = 4;
                TI_ResetTics (TimerRebots);
            }
            break;
            
        case 2:
            rows = 0x04; //b'00000100'; 
            setFiles(rows);      
            estat_teclat = 3;
            columna_polsada = comprovaHiHaColumna();
            if (hi_ha_tecla){
                flagAltaveu_teclat = 1;
                estat_teclat = 4;
                TI_ResetTics (TimerRebots);
            }
            break;
            
        case 3:
            rows = 0x08; //b'00001000';
            setFiles(rows);
            estat_teclat = 0;
            columna_polsada = comprovaHiHaColumna(); 
            if (hi_ha_tecla){
                flagAltaveu_teclat = 1;
                estat_teclat = 4;
                TI_ResetTics (TimerRebots);
            }
            break;
            
        case 4: // Mirem els rebots
            flagAltaveu_teclat = 0;
            timer_tics = TI_GetTics (TimerRebots);
            if (timer_tics >= 8){
                if (hi_ha_tecla){
                    estat_teclat = 5;
                    timer_tics_1s = TI_GetTics (Timer1S);
                   
                }else{
                    estat_teclat = 0;
                } 
            }
        break;
        
        case 5:
            waitTeclaTreta();
            TI_ResetTics (Timer1S);
        break;
        
        case 6:
            //timer_tics_1s = TI_GetTics (Timer1S);
            if (timer_tics_1s >= 4000){
                caracter_actual = 0;
                //LcGotoXY(caracters_escrits++, 1);
            }
            saveTecla();
            estat_teclat = 7;
            break;
            
        case 7:
            if(old_fila_matriu != fila_matriu || timer_tics_1s > 4000){
                tower_name[caracters_escrits] = matriu_teclat[fila_matriu][caracter_actual-1];
                //LcPutChar(tower_name[caracters_escrits]);
                caracters_escrits++;
                caracter_actual = 0;
                caracters_escrits_menu = caracters_escrits;
            }
            flag_TTeclat = Getflag_TTeclat();
            if(flag_TTeclat){
                writeCaracter();
            }
            estat_teclat = 0;
            old_fila_matriu = fila_matriu;
            if (flag_preemenu == 1){
                estat_teclat = 0;
                fila_matriu = 12;
                flag_preemenu = 0;
            }
        break;
        case 8:
            break;
    }
}
