#include "TTECLAT.h"
#include "TTIMER.h"
#include "TALTAVEU.h"
#include <xc.h>


unsigned char nota = 0;
unsigned char estat_altaveu = 0;
unsigned char TimerTiempoNota = 0;
unsigned char TimerNotaTotal = 0;
unsigned char tiempo_nota = 0;
unsigned char tecla_premuda = 0;
unsigned char tiempo_nota_total = 0;
unsigned char TimerMelody = 0;
unsigned char temps_5s = 0;
unsigned char p = 0;


void InitAltaveu(){
    TRISEbits.TRISE2 = 0;
    LATEbits.LATE2 = 0;
    TI_NewTimer(&TimerTiempoNota);
    TI_ResetTics (TimerTiempoNota);
    TI_NewTimer(&TimerMelody);
    TI_ResetTics (TimerMelody);
    p = 2;
}

void NotaTecles(){
    estat_altaveu = 0;
}

void Melody(){
    estat_altaveu = 7;
}

void motorAltaveu(){
    switch(estat_altaveu){
        case 0:
            tiempo_nota = 0;
            tecla_premuda = getHiHatecla();
            if(tecla_premuda){
                estat_altaveu = 1;
            }
            break;
        case 1:
            TI_ResetTics(TimerTiempoNota);
            nota = getFilamatriu();
            estat_altaveu = 2;
            break;
        case 2:
            nota = getFilamatriu();
            tecla_premuda = getHiHatecla();
            tiempo_nota = TI_GetTics(TimerTiempoNota);
            if(tiempo_nota < array_notas[nota]){
                LATEbits.LATE2 = 1;
            }else{
                LATEbits.LATE2 = 0;
                if(tecla_premuda == 0){
                   estat_altaveu = 0;
                   TI_ResetTics (TimerTiempoNota);
                }else{
                    estat_altaveu = 3;
                    TI_ResetTics (TimerTiempoNota);
                }
            }
            break;
        case 3:
            nota = getFilamatriu();
            tecla_premuda = getHiHatecla();
            tiempo_nota = TI_GetTics(TimerTiempoNota);
            if(tiempo_nota < array_notas[nota]){//para que este a zero hasta que no se cumplan 250 milis para que todos sen igual
                LATEbits.LATE2 = 0;
            }else{
                if(tecla_premuda == 0){
                   estat_altaveu = 0;
                   TI_ResetTics (TimerTiempoNota);
                }else{
                    estat_altaveu = 2;
                    TI_ResetTics (TimerTiempoNota);
                }    
            }
            break; 
        case 7:
            estat_altaveu = 4;
            TI_ResetTics (TimerMelody);
            TI_ResetTics(TimerTiempoNota);
            temps_5s = 0;
            p = 2;
            break;
        case 4:
            estat_altaveu = 5;
            if(TI_GetTics(TimerMelody) >= 4000){
                    TI_ResetTics (TimerMelody);
                    temps_5s++;
                }
                if(temps_5s >= 5){
                    estat_altaveu = 0;
                    p = 2;
                }
            break;
        case 5:
            tiempo_nota = TI_GetTics(TimerTiempoNota);
            if(tiempo_nota < array_notas[p]){
                LATEbits.LATE2 = 1;
            }else{
                LATEbits.LATE2 = 0;
                estat_altaveu = 6;
                TI_ResetTics (TimerTiempoNota);
                
                if(TI_GetTics(TimerMelody) >= 4000){
                    TI_ResetTics (TimerMelody);
                    temps_5s++;
                    p++;
                }
                if(temps_5s >= 5){
                    estat_altaveu = 8;
                    p = 2;
                }
            }
            break;
        case 6:
            tiempo_nota = TI_GetTics(TimerTiempoNota);
            if(tiempo_nota < array_notas[p]){
                LATEbits.LATE2 = 0;
            }else{
                estat_altaveu = 5;
                
                TI_ResetTics (TimerTiempoNota);
            }
            break;
        case 8:
            
            break;
    }
}
