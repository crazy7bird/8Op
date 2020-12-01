#include "basicop.h"
#include "logicop.h"
#include "num.h"
#include <stdio.h>
#include <stdlib.h>
//#define MAXCHAR 8


/*Have to implement sub and div first…*/
char _MOD(struct num *A, struct num *B) {
	return 0;
}

int main(void) {
	printf("Hello World\n");
	struct num *A = newNum(5);
	struct num *B = newNum(4);
	struct num *R = newNum(8);
	//A
	A->Num[0] = 0x21;
	A->Num[1] = 0x43;
	//B
	B->Num[0] = 0x23;
	B->Num[1] = 0x43;
	B->Num[2] = 0x12;
	B->Num[3] = 0xF0;



	printNum(A);
	printNum(B);
	struct num *Q = newNum(8);
	Q->Num[0] = 1;
	while(_CMP(B,A)>0)
	{
		_LSHIFT(Q,1);
		printNum(Q);
		_LSHIFT(A,1);
		printNum(A);
		printNum(B);
		printf("%d\n\n",_CMP(B,A));
	}
	printNum(A);
	printNum(Q);

	return 0;
}