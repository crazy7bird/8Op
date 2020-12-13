/*
* basicop,
* Contain the four basical math function,
* "+" "-" "/" "*"
* for a struct num type number.
*/

#ifndef _BOP_H_
#define _BOP_H_

#include <stdio.h>
#include <stdlib.h>
#include "num.h"

/*Addition between 2 num*/
void _ADD(struct num* A, struct num *B, struct num *R);
void _P1(struct num* A);  //A++
void _M1(struct num* A);    //A--
/*Substraction between 2 num. Make sure A greater than B*/
void _SUB(struct num* A, struct num *B, struct num *R);

/*Multiplication between 2 num*/
void _MUL(struct num* A, struct num *B, struct num *R);
/*division  between 2 num*/
/*R and Q could be set to NULL, R the Remainder Q the Quotient*/
void _DIV(struct num *N,struct num* D,struct num* Q, struct num*R);

#endif