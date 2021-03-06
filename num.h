/*
* num.h, contain all non operator function about num
* A num is always a positif integer.
* This lib is set for crypto purpose on small 8bits devices.
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef _NUM_H_
#define _NUM_H_

struct num
{
  unsigned char*Num;
  unsigned char Size;
};

/*For instance a new num struct*/
struct num* newNum(unsigned char Size);
/*For delete a struct num, and clear memorie allocation*/
void delNum(struct num* N);

/*Help set the num to 0*/
void clearNum(struct num* N);

/*print the num\n*/
void printNum(struct num* N);

/*Copy A->Num values into B*/
void copyNum(struct num* A, struct num *B);

/*Fill the num structure with string ex: "123456789\0"*/
void str2Num(struct num* N, char* S);

/*Numbers of digits realy used*/
unsigned char effectiveSizeNum(struct num * N);

#endif