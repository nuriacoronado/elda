/* 
 * File:   TMENU.h
 * Author: nurco
 *
 * Created on 24 de abril de 2023, 15:59
 */

#ifndef TMENU_H
#define	TMENU_H

unsigned char getFlagMenu();
unsigned char getFlagPreeMenu();
unsigned char Getflag_TTeclat();
void Menu_Init ();
void motorMenu ();
unsigned char getFlag_Start_Recording();
unsigned char getCurrentTime();
unsigned char getJoystickDownCounter();
void esperaMarq(unsigned char estat);
void augmentaPosMarq();
#endif	/* TMENU_H */

