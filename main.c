#include "basicop.h"
#include "logicop.h"
#include "num.h"
#include <stdio.h>
#include <stdlib.h>
//#define MAXCHAR 8


int main(void) 
{
	printf("Hello World\n");
	struct num *A = newNum(8);
	struct num *B = newNum(8);
	struct num *R = newNum(8);
	struct num *Q = newNum(8);
	//A
	A->Num[0] = 0x34;
	A->Num[1] = 0x12;
	A->Num[2] = 0x34;
	A->Num[3] = 0x12;
	A->Num[4] = 0x34;
	A->Num[5] = 0x12;
	A->Num[6] = 0x34;
	A->Num[7] = 0x12;
	//B
	B->Num[0] = 0x78;
	B->Num[1] = 0x56;
	B->Num[2] = 0x04;
	B->Num[3] = 0x50;
	B->Num[4] = 0x78;
	B->Num[5] = 0x56;
	B->Num[6] = 0x04;
	B->Num[7] = 0x50;





	printNum(A);
	printNum(B);

	printf("\n NULL NULL :\n");
	_DIV(B,A,NULL,NULL);
	printNum(A);
	printNum(B);
	printNum(Q);
	printNum(R);

	printf("\n Q NULL :\n");
	_DIV(B,A,Q,NULL);
	printNum(A);
	printNum(B);
	printNum(Q); clearNum(Q);
	printNum(R);

	printf("\n NULL R :\n");
	_DIV(B,A,NULL,R);
	printNum(A);
	printNum(B);
	printNum(Q);
	printNum(R); clearNum(R);

	printf("\n Q R :\n");
	_DIV(B,A,Q,R);
	printNum(A);
	printNum(B);
	printNum(Q);
	printNum(R);

	return 0;
}

