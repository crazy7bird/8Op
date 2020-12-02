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
/*
[IDEA] :
recursive DIV(N,D,S) //S= 0 for the first call
{
	Dl = D; (copy);
	Q = struct num 1;

	while(N>(Dl + S)) :
		Dl<<1;
		Q<<1;
	
	//1 step back
	Dl >>1;
	Q >>1;

	IF (N-Dl)>D :
		Q,Dl += recursive DIV(N,D,Dl);
	
	R = N-Dl;
	return Q,Dl,R;
}
*/
/*First without R*/

struct num* _laDIV(struct num* N, struct num* D)
{
	struct num *Dl = newNum(1 + D->Size);
	copyNum(D,Dl);
	struct num * Q = newNum(D->Size); //Optimiser la taille de Q ?
	Q->Num[0]=0x01;

	//Fast forward 
	while(_CMP(N,Dl)>0)
	{
		_LSHIFT(Dl,1);
		_LSHIFT(Q,1);
		printf(">");
	}
	//One step back
	_RSHIFT(Dl,1);
	_RSHIFT(Q,1); //Two step back for Q cause it start at 1 and not 0.



	printf("\n");
	printNum(Dl);
	printNum(Q);
	//Slow Forward
	while(_CMP(N,Dl)>0)
	{
		_ADD(Dl,D,Dl);
		//printNum(D);
		//printNum(Dl);
		_P1(Q);
		//printf(".");
	}
	printf("\n");
	printNum(Q);
	/*Real result is Q-1*/
	return Q;
}



int main(void) {
	printf("Hello World\n");
	struct num *A = newNum(5);
	struct num *B = newNum(5);
	struct num *R = newNum(8);
	//A
	A->Num[0] = 0x01;
	A->Num[1] = 0x00;
	//B
	B->Num[0] = 0x00;
	B->Num[1] = 0x00;
	B->Num[2] = 0x01;
	B->Num[3] = 0x00;



	printNum(A);
	printNum(B);
	_M1(A);
	_M1(B);
	printNum(A);
	printNum(B);

	//_laDIV(B,A);
	/*
	struct num *S = newNum(6);
	struct num *Q;

	Q = _recursiveDIV(B,A,S);
	printNum(Q);
*/
	return 0;
}

