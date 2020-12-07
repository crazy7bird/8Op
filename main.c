#include "basicop.h"
#include "logicop.h"
#include "num.h"
#include <stdio.h>
#include <stdlib.h>
//#define MAXCHAR 8


struct num* modpow(struct num* base, struct num* exp, struct num* m) {

   unsigned char Size = (2 * base->Size);
   struct num* result = newNum(Size); 
   result->Num[0] =0x01;
   struct num* calcul = newNum(Size);

   while (_CMPINT(exp,0)>0) 
   {
      if ((exp->Num[0] & 1) > 0)
	  {
		  clearNum(calcul);
		  //result = (result * base) % m;
		  printf("START inside\n");
		  printNum(result);
		  printNum(base);
		  _MULL(result,base,calcul);
		  printNum(calcul);
		  printNum(m);
		  _DIV(calcul,m,NULL,result);
		  printNum(result);
		  printf("---\n");
	  } 
	  printf("START outside\n");
      _RSHIFT(exp,1);
	  clearNum(calcul);
      //base = (base * base) % m;
	  _MULL(base,base,calcul);
	  printNum(calcul);
	  _DIV(calcul,m,NULL,base);
	  printNum(exp);
	  printNum(base);
	  printf("---\n");
   }
   printNum(result);
   delNum(calcul);
   return result;
 }

int main(void) 
{
	printf("Hello World\n");
	struct num *A = newNum(4);
	struct num *B = newNum(4);
	struct num *C = newNum(4);

	//A
	A->Num[0] = 0x11;
	A->Num[1] = 0x00;
	//A->Num[2] = 0x00;

	//B
	B->Num[0] = 0x12;
	B->Num[1] = 0x00;
	//B->Num[2] = 0x00;

	C->Num[0] = 0x37;

	//printNum(A);
	//printNum(B);
	//printNum(C);

	//modpow(A,B,C);
{
	struct num *N = newNum(4);
	struct num *D = newNum(4);
	struct num *Q = newNum(4);
	struct num *R = newNum(8);
	N->Num[0] = 0x58;
	N->Num[1] = 0x02;
	D->Num[0] = 0x37;

	printNum(N);
	printNum(D);
	_DIV(N,D,Q,R);
	printNum(Q);
	printNum(R);

}


	return 0;
}

