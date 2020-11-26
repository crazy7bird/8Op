/*
Logical operator between num.
*/
#ifndef _LOP_H_
#define _LOP_H_

#include <stdio.h>
#include <stdlib.h>
#include "num.h"

/*Right shift register of s time on num N*/
void _RSHIFT(struct num *N, char s);
/*Guess what i wont tell you what it does !*/
void _LSHIFT(struct num *N, char s);

/*compare 2 numbers return 
positif is A>B;
0 if A==B;
negatif if A<B;
*/
char _CMP(struct num *A, struct num *B);

/*Compare to a non num number*/
char _CMPINT(struct num *A, char B);
#endif