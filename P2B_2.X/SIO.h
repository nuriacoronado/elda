/* 
 * File:   SIO.h
 * Author: nurco
 *
 * Created on 8 de mayo de 2023, 15:44
 */

#ifndef SIO_H
#define	SIO_H


void sioInit();
unsigned char GetFlagStartMenu();
unsigned char waitForSend();
//Pre
//Post: if function returns 1, Tx is avaliable for sending. If it returns 0, it has to wait.
void sendChar(char caracter);
//Pre: Wait tx to be available
//Post: Sends a Char
unsigned char compareCharRecieved(char caracter);
//Pre: 
//Post: Compares a char with what has been recieved (1 if equals, 0 if not)
unsigned char checkIfRecieved();
//Pre:
//Post: Checks if something has been recieved (1 if true, 0 if not)

#endif	/* SIO_H */

