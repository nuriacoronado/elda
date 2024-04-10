#include "TTECLAT.h"
#include "TTIMER.h"
#include "TMENU.h"
#include "TRECORDING.h"
#include "SIO.h"
#include <xc.h>

unsigned char estat_eeprom = 0;
unsigned char eeprom_data;
unsigned char p1 = 0;
unsigned char flag_index = 0;
unsigned char total_gravacions = 0;
unsigned char eeprom_adress_temp = 0;
unsigned char eeprom_adress = 0;
unsigned char eeprom_read = 0;
unsigned char index_data = 0;
unsigned char eeprom_overflow = 0;

void startEEPROMWrite(){
    estat_eeprom = 5;
}
unsigned char getTotalGravacions (){
    return(total_gravacions);
}
unsigned char getEepromOverflow(){
    return(eeprom_overflow);
}
void initEEPROM(){
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EEADR = 0;
}
/*void putCharEEPROM (unsigned char caracter){
    eeprom_data = caracter;
}*/
void configWriteEEPROM (){
    INTCONbits.GIE = 0;
    EECON1bits.WREN = 1;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
}
unsigned char waitWriteEEPROM (){
    unsigned char flag_ww_eeprom = 0;
    if(EECON1bits.WR == 0){
        INTCONbits.GIE = 1;
        EECON1bits.WREN = 0;
        flag_ww_eeprom = 1;
    }
    return(flag_ww_eeprom);
}
unsigned char ReadEEPROM (unsigned char adress){
    EEADR = adress;    
    EECON1bits.RD = 1;
    return(EEDATA);
}

void motorEEPROM(){
    switch(estat_eeprom){
        case 0: // Llegim adre a 70
            eeprom_read = ReadEEPROM(70);
            flag_index = 0;
            estat_eeprom = 1;
            eeprom_overflow = 0;
            break;
        case 1: // Si no hi ha res, fem reset
            if (eeprom_read == 0xFF){
                estat_eeprom = 2;
                
            }else{
                estat_eeprom = 4;
                total_gravacions = eeprom_read;
            }
            break;
        case 2: //Posem un 0
            EEADR = 70;
            EEDATA = 0;
            configWriteEEPROM();
            estat_eeprom = 3;
            break;
        case 3: //Ens esperem a que s'escrigui
            if(waitWriteEEPROM() == 1){
                estat_eeprom = 4;
            }
            break;
        case 4: //Esperem a que ens diguin escriu
            flag_index = 0;
            break;
        case 5:
            total_gravacions = ReadEEPROM(70);
            estat_eeprom = 6;
            eeprom_adress = total_gravacions * 7;
            break;
            
        case 6:
            if(flag_index <= 1){
                EEDATA = getIndex(total_gravacions, flag_index);
                //index_data = getIndex(total_gravacions, flag_index);
            }else{
                EEDATA = getTimeStampChar(p1);
            }
            estat_eeprom = 7;
            break;
        case 7:
            EEADR = eeprom_adress;
            configWriteEEPROM();
            estat_eeprom = 8;
            break;
        case 8:
            if(waitWriteEEPROM() == 1){
                estat_eeprom = 9;
            }
            break;
        case 9:
            if (flag_index == 2){
                p1++;
            }else{
                flag_index++;
            }
            if (p1 < 5){
                estat_eeprom = 6; 
                eeprom_adress++;
            }else{
                estat_eeprom = 0;
                total_gravacions++;
                estat_eeprom = 10;
                p1 = 0;
            }
            break;
        case 10: 
            EEADR = 70;
            if(total_gravacions != 8){
                EEDATA = total_gravacions;
            }
            if (total_gravacions == 8){
                EEDATA = 0;
                total_gravacions = 0; // Si s'han gravat 8, es torna a 0 de manera que la següent gravació comenci al 0.
                flag_index = 0;
                eeprom_overflow = 1;
            }
            configWriteEEPROM();
            estat_eeprom = 11;
            break;
        case 11:
            if(waitWriteEEPROM() == 1){
                estat_eeprom = 1;
                estat_eeprom = 4;
            }
            break;
        
    }
    
    
    
    
    
}