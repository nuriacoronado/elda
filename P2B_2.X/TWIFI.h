#ifndef _TWIFI_H_
#define _TWIFI_H_

#include "TTIMER.h"

void initWIFI (void);
// Post: Inicialitza el TAD. Precondició de la resta de funcions
unsigned char sendFrase(char frase[]);

void CargarTX(char);
    
void MotorTX (void);

unsigned char ReadyToSend(void);

unsigned char MotorRC(void);

unsigned char Extract_RC (void); 

#endif

