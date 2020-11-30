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
    N->Num[index] = (N->Num[dec] << slowshift) + (N->Num[dec] >> (8-slowshift)) ;
    dec --;
    index --;
  }
  /*One more time*/
  N->Num[index] = (N->Num[dec] << slowshift);
  /*
  index --;
  while(index > 0)
  {
    N->Num[index] = 0x00;
    index--;
  }
  N->Num[0] = 0x00;
	*/
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
/*TODO WORK ON IT, its little endian ! */ 
/*start with same size Nim
N[0] = LSB;
N[Size-1] = MSB;
*/
signed char _CMP(struct num*A, struct num *B)
{
	char x = A->Size -1;
	for(; x>0;x--)
	{
		printf("%d - %d = %d\n",A->Num[x] , B->Num[x],A->Num[x] - B->Num[x] );
		if(A->Num[x] != B->Num)
		{
			return (signed char) ((signed char)A->Num[x] - (signed char)B->Num[x]);
		}
		return (signed char) ((signed char)A->Num[0] - (signed char)B->Num[0]);
	}
}

/*
signed char _CMP(struct num *A, struct num *B) {
	unsigned char x = 0;
	char stop = 0;
	if (A->Size > B->Size) // More digit on A
	{
		stop = (A->Size - 1) - (B->Size -1);
		for (char y = 0; y < stop; y++) {
			if (A->Num[y] != 0)
				return (signed char)1;
		}
	} 
	else // More digit on B
	{
		stop = (B->Size - 1) - (A->Size -1);
		for (char y = 0; y < stop; y++) {
			if (B->Num[y] != 0)
				return (signed char)-1;
		}
	}
	for (; x > 0; x--) {
		if (A->Num[x] != B->Num[x])
			return (signed char)A->Num[x] - B->Num[x];
	}
	// Do the last digit
	return (signed char)A->Num[0] - B->Num[0];
}
*/

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