#include "basicop.h"
#include "logicop.h"
#include "num.h"
#include <stdio.h>
#include <stdlib.h>
#include "Tests/AutoTests.h"
//#define MAXCHAR 8


struct num* modpow(struct num* base, struct num* exp, struct num* m) {

   unsigned char Size = (base->Size);
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


	AutoTests();
	return 0;
}

