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
	struct num *A = newNum(4);
	struct num *B = newNum(4);
	struct num *R = newNum(8);

	A->Num[0] = 0x21;
	A->Num[1] = 0x43;
	B->Num[0] = 0x23;
	B->Num[1] = 0x01;
	B->Num[2] = 0x12;
	B->Num[3] = 0xF0;

	printNum(A);
	printNum(B);
	_DIV(A, B, R);


	return 0;
}