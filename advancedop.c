#include "advancedop.h"
#include "basicop.h"
#include "logicop.h"

void _MODPOW(struct num* base, struct num* exp, struct num* m) {

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
   delNum(result);
   //return result;
 }

