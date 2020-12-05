#include "basicop.h"
#include "logicop.h"
#include "num.h"
#include <stdio.h>
#include <stdlib.h>
//#define MAXCHAR 8


struct num* modpow(struct num* base, struct num* exp, struct num* m) {
   struct num* result = newNum(2*base->Size);

   while (_CMPINT(exp,0)>0) 
   {
      if ((exp & (big)1) > 0) result = (result * base) % m;
      _RSHIFT(exp,1);
      base = (base * base) % m;
   }
   return result;
 }

int main(void) 
{
	printf("Hello World\n");
	struct num *A = newNum(4);
	struct num *B = newNum(4);
	struct num *R = newNum(4);
	//A
	A->Num[0] = 0xFF;
	A->Num[1] = 0x00;
	A->Num[2] = 0x00;

	//B
	B->Num[0] = 0xFE;
	B->Num[1] = 0xFF;
	B->Num[2] = 0x00;

	printNum(A);
	printNum(B);
	printNum(R);

	printf("\nADD :\n");
	_SUB(B,A,R);
	printNum(A);
	printNum(B);
	printNum(R);

	return 0;
}

