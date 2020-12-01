#include "basicop.h"


void _RSHIFT(struct num *N, char s) {
	// s from 0 to 255
	if (s == 0)
		return;
	char fastshift = s / 8;
	char slowshift = s % 8;
	char index;
	for (index = 0; index < N->Size; index++) {
		N->Num[index] = N->Num[index + fastshift];
	}
	for (index = 0; index < (N->Size - 1); index++) {
		char D = 0;
		D = N->Num[index + 1] & (0xFF >> (8 - slowshift));
		D = D << (8 - slowshift);
		D += N->Num[index] >> slowshift;
		N->Num[index] = D;
	}
	N->Num[index] = N->Num[index] >> slowshift;
}


void _LSHIFT(struct num *N, char s) {
	// s from 0 to 255
  //We add 0 in entry
	if (s == 0)
		return;
	char fastshift = s / 8;
	char slowshift = s % 8;
	char index = N->Size -1;
  char dec = index - fastshift;
  while(dec > 0)
  {
    N->Num[index] = (N->Num[dec] << slowshift) + (N->Num[dec-1] >> (8-slowshift)) ;
    dec --;
    index --;
  }
  /*One more time*/
  N->Num[index] = (N->Num[dec] << slowshift);

  for(index = 0; index < fastshift ; index++)
  {
    N->Num[index] =0x00;
  }
}

/*Compare A with B,
Return :
1 if A>B
0 if A==B
-1 if A<B

*/
signed char _CMP(struct num*A, struct num *B)
{
	char x = A->Size-1;
	if (A->Size > B->Size) //A a plus de digit que B
	{
		x = A->Size-1;
		char stop = B->Size-1;
		while(x > stop)
		{
			if(A->Num[x]) //If A not éqaul to 0.
			{
				return  (signed char)1;
			}
			x--;
		}
	}
	if (A->Size < B->Size) //A less digit than B
	{
		x = B->Size-1;
		char stop = A->Size-1;
		while(x > stop)
		{
			if(B->Num[x]) //If A not éqaul to 0.
			{
				return  (signed char)-1;
			}
			x--;
		}
	}
	/*Now A and B have the same digit numbers*/
	for(; x>0;x--)
	{
		if(A->Num[x] != B->Num[x]) //A and B are different so one is biger than the other
		{
			if(A->Num[x] > B->Num[x]) return  (signed char)1;
			else return  (signed char)-1;
		}
	}
	if(A->Num[0] != B->Num[0]) //A and B are different so one is biger than the other
	{
		if(A->Num[0] > B->Num[0]) return  (signed char)1;
		else return  (signed char)-1;
	}
	else return 0; //perfectly equal. 
}

/*Compare to a non num number*/
char _CMPINT(struct num *A, char B) {
	unsigned char x = (A->Size - 1);
	if (A->Size > 1) // More digit on A
	{
		for (; x > 0; x--)
			if (A->Num[x] != 0)
				return (char)1;
	}
	// Do the last digit
	return (char)A->Num[0] - B;
}