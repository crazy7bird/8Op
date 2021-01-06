#include "basicop.h"
#include "logicop.h"
#include "advancedop.h"
#include "num.h"
#include <stdio.h>
#include <stdlib.h>
#include "Tests/AutoTests.h"
//#define MAXCHAR 8


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

