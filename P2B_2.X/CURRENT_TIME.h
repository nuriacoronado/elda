/* 
 * File:   CURRENT_TIME.h
 * Author: nurco
 *
 * Created on 11 de mayo de 2023, 10:17
 */

#ifndef CURRENT_TIME_H
#define	CURRENT_TIME_H

void motorShowCurrentTime();
void startCurrentTime();
unsigned char getSegons0 ();
unsigned char getSegons1 ();
unsigned char getMinuts0 ();
unsigned char getMinuts1 ();
void putSegons0(unsigned char digit);
void putSegons1(unsigned char digit);
void putMinuts0(unsigned char digit);
void putMinuts1(unsigned char digit);
void InitCurrentTime();


#endif	/* CURRENT_TIME_H */

