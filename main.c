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
/*InerDIV
Start at prevD wich is the last D*2 before D become greater than N
*/
struct num* _inerDIV(struct num* N, struct num* D, struct num* prevD)
{
	struct num *Dl = newNum(1 + N->Size);
	copyNum(D,Dl);
	struct num * Q = newNum(N->Size); //Optimiser la taille de Q ?
	Q->Num[0]=0x01;
	struct num* R = newNum(1+ N->Size); //R register for iner calculus.

	//Fast forward 
	_ADD(Dl,prevD,R);
	while(_CMP(N,R)>=0)
	{
		_LSHIFT(Dl,1);
		_LSHIFT(Q,1);
		clearNum(R);
		_ADD(Dl,prevD,R);
		printf(">");
	}
	//One step back
	_RSHIFT(Dl,1);
	_RSHIFT(Q,1); //One step back for Q
	_M1(Q); //Q less one cause we start à 1 and no 0

	clearNum(R);
	_ADD(prevD,Dl,R);
	printf("inerdiv\n");
	printNum(Dl);
	printNum(prevD);

	copyNum(R,prevD);
	delNum(Dl);
	delNum(R);
	return Q;
}

struct num* _laDIV(struct num* N, struct num* D)
{
	struct num *Dl = newNum(1 + D->Size);
	copyNum(D,Dl);
	struct num * Q = newNum(D->Size); //Optimiser la taille de Q ?
	Q->Num[0]=0x01;

	struct num * R = newNum(D->Size); 

	//Fast forward 
	while(_CMP(N,Dl)>0)
	{
		_LSHIFT(Dl,1);
		_LSHIFT(Q,1);
	}
	//One step back
	_RSHIFT(Dl,1);
	_RSHIFT(Q,1); //One step back for Q
	_M1(Q); //Q less one cause we start à 1 and no 0

	
	while(_CMP(N,Dl)>0)
	{
		struct num* Qr;
		clearNum(R);
		Qr = _inerDIV(N,D,Dl);
		_ADD(Qr,Q,R);
		copyNum(R,Q);
		delNum(Qr);
		printf("outerdiv\n");
		printNum(Q);
		printNum(Dl);
	}
	delNum(R);
	delNum(Dl);
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
	A->Num[0] = 0x34;
	A->Num[1] = 0x12;
	//B
	B->Num[0] = 0x78;
	B->Num[1] = 0x56;
	B->Num[2] = 0x04;
	B->Num[3] = 0x00;



	printNum(A);
	printNum(B);

	_laDIV(B,A);

	return 0;
}

