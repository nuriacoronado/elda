/* 
 * File:   TRECORDING.h
 * Author: nurco
 *
 * Created on 22 de mayo de 2023, 16:01
 */

#ifndef TRECORDING_H
#define	TRECORDING_H

unsigned int getMostresMicro();
void startTRecording();
void motorRecording();
void endTRecording();
void initMicro();
void sendTimeStamp ();
unsigned char getIndex (unsigned char gravacio, unsigned char posicio);
unsigned char getTimeStampChar(unsigned char position);
#endif	/* TRECORDING_H */

