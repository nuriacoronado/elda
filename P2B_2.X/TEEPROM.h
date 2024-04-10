/* 
 * File:   TEEPROM.h
 * Author: nurco
 *
 * Created on 23 de mayo de 2023, 14:54
 */

#ifndef TEEPROM_H
#define	TEEPROM_H


void startEEPROMWrite();
void initEEPROM();
void motorEEPROM();
unsigned char ReadEEPROM (unsigned char adress);
unsigned char waitWriteEEPROM ();
unsigned char getTotalGravacions ();
unsigned char getEepromOverflow();
#endif	/* TEEPROM_H */

