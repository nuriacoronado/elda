/* 
 * File:   TALTAVEU.h
 * Author: nurco
 *
 * Created on 16 de mayo de 2023, 13:34
 */

#ifndef TALTAVEU_H
#define	TALTAVEU_H

#define NOTA_ONE 2
#define NOTA_TWO 4
#define NOTA_THREE 6
#define NOTA_FOUR 8
#define NOTA_FIVE 10
#define NOTA_SIX 12
#define NOTA_SEVEN 14
#define NOTA_EIGHT 18
#define NOTA_NINE 20
#define NOTA_TEN 22
#define NOTA_ELEVEN 26
#define NOTA_TWELVE 28

static const char array_notas[12] = {NOTA_ONE, NOTA_TWO, NOTA_THREE, NOTA_FOUR, NOTA_FIVE, NOTA_SIX, NOTA_SEVEN, NOTA_EIGHT, NOTA_NINE, NOTA_TEN, NOTA_ELEVEN, NOTA_TWELVE};


void InitAltaveu();
void motorAltaveu();
void Melody();
void NotaTecles();

#endif	/* TALTAVEU_H */

