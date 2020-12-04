#include "basicop.h"
#include "logicop.h"
#include "num.h"
#include <stdio.h>
#include <stdlib.h>
//#define MAXCHAR 8



void __DIV(struct num *N,struct num* D)
{
	struct num * Q = newNum(N->Size);
	struct num * R = newNum(N->Size);
	struct num * calcul = newNum(N->Size);

	signed short i = (N->Size * 8) -1;
	unsigned char mask = 0x80;
	unsigned char index = N->Size -1 ;

	while(i >= 0)
	{
		_LSHIFT(R,1);
		R->Num[0] |= (N->Num[index] & mask)?0x01:0x00;
		if(_CMP(R,D)>=0)
		{
			clearNum(calcul);
			_SUB(R,D,calcul);
			copyNum(calcul,R);
			Q->Num[index] |= mask ;
		}

		mask = mask >> 1;
		if(mask == 0)
		{
			mask = 0x80;
			index --;
		}
		i--;
	}
	printNum(Q);
	printNum(R);
	delNum(calcul);
	delNum(R);
	delNum(Q);
}



int main(void) {
	printf("Hello World\n");
	struct num *A = newNum(3);
	struct num *B = newNum(3);
	//struct num *R = newNum(8);
	//A
	A->Num[0] = 0x34;
	A->Num[1] = 0x12;
	//B
	B->Num[0] = 0x78;
	B->Num[1] = 0x56;
	B->Num[2] = 0x04;
	B->Num[3] = 0x00;



	printNum(A);
	printNum(B);

	__DIV(B,A);

	return 0;
}

