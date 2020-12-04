#include "basicop.h"
#include "logicop.h"
#include "num.h"
#include <stdio.h>
#include <stdlib.h>
//#define MAXCHAR 8


int main(void) 
{
	printf("Hello World\n");
	struct num *A = newNum(4);
	struct num *B = newNum(4);
	struct num *R = newNum(4);
	//A
	A->Num[0] = 0x34;
	A->Num[1] = 0x12;
	A->Num[2] = 0x34;

	//B
	B->Num[0] = 0x78;
	B->Num[1] = 0x56;
	B->Num[2] = 0x04;

	printNum(A);
	printNum(B);
	printNum(R);

	printf("\nR=A+B\n");
	_ADD(A,B,R);
	printNum(A);
	printNum(B);
	printNum(R);

	printf("\nA=A+B\n");
	clearNum(R);
	_ADD(A,B,A);
	printNum(A);
	printNum(B);
	printNum(R);

	printf("\nA=A+A\n");
	clearNum(R);
	_ADD(A,A,A);
	printNum(A);
	printNum(B);
	printNum(R);

	return 0;
}

