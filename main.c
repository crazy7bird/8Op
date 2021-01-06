#include "basicop.h"
#include "logicop.h"
#include "advancedop.h"
#include "num.h"
#include <stdio.h>
#include <stdlib.h>
#include "Tests/AutoTests.h"
//#define MAXCHAR 8
/*

struct num* modpow(struct num* base, struct num* exp, struct num* m) {

   unsigned char Size = (base->Size);
   struct num* result = newNum(Size); 
   result->Num[0] =0x01;
   struct num* calcul = newNum(Size);

   while (_CMPINT(exp,0)>0) 
   {
      if ((exp->Num[0] & 1) > 0)
	  {
		  //result = (result * base) % m;
		  clearNum(calcul);
		  _MUL(result,base,result);
		  _DIV(result,m,NULL,calcul);
		  copyNum(calcul,result);
	  } 
      _RSHIFT(exp,1);
      //base = (base * base) % m;
	  _MUL(base,base,base);
	  clearNum(calcul);
	  _DIV(base,m,NULL,calcul);
	  copyNum(calcul,base);

   }
   printNum(result);
   delNum(calcul);
   return result;
 }
*/
int main(void) 
{
	printf("Hello World\n");
/*
	struct num* A = newNum(8);

	unsigned char X;
	printNum(A);
	printf("%d\n",effectiveSizeNum(A));
	for(X=0; X<A->Size;X++)
	{
		clearNum(A);
		A->Num[X] =0x01;
		printNum(A);
		printf("%d\n",effectiveSizeNum(A));
	}
*/

	struct num* A = newNum(10);
	struct num* B = newNum(10);
	struct num* C = newNum(10);
	str2Num(A,"0x1234567890");
	str2Num(B,"0x1337");
	str2Num(C,"0x424242");
	_MODPOW(A, B, C);

	AutoTests();
	return 0;
}

