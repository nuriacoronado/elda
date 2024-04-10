/* 
 * File:   TTECLAT.h
 * Author: nurco
 *
 * Created on 24 de abril de 2023, 16:56
 */


#ifndef TTECLAT_H
#define	TTECLAT_H

#define SetColumns_Entrada()		(TRISCbits.TRISC0 = TRISCbits.TRISC4 = TRISCbits.TRISC2 = 1)
#define SetRows_Sortida()		(TRISCbits.TRISC1 = TRISCbits.TRISC3 = TRISCbits.TRISC5 = TRISEbits.TRISE1 = 0)


unsigned char getTowerName(unsigned char p);
unsigned char getTecla ();
void initTeclat();
void setFiles (char rows);
unsigned char comprovaHiHaColumna ();
void esperaRebots();
void escombraTeclat ();
void saveTecla();
void writeCaracter();
void waitTeclaTreta();
void motorTeclat ();
unsigned char getCaractersEscrits ();
unsigned char getEspera();
unsigned char getFilamatriu();
void putFilaMatriu12 ();
unsigned char getHiHatecla();


#endif	/* TTECLAT_H */

