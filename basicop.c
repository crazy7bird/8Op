#include "basicop.h"
#include "logicop.h" //Needed for _CMP(A,B) used by DIV algo


/*_ADD(A,B,R) => R = A+B*/
void _ADD(struct num* A, struct num *B, struct num *R)
{
  //Do verif here
  //Assume Size A == Size B. and Size R atleast SizeA+1
  unsigned char Size = A->Size;
  unsigned char iter =0;
  unsigned char carry =0;
  unsigned char ADD = 0; // Var for calcul addition and safe overflow
  for(iter =0; iter < Size; iter++)
  {
    ADD = A->Num[iter] + B->Num[iter];
    if((ADD < A->Num[iter]) || (ADD < B->Num[iter]) || (ADD+carry) < ADD )
    {
      ADD+=carry;
      carry = 1;
    }
    else
    {
      ADD+=carry;
      carry = 0;
    }
    R->Num[iter] = ADD;
  }
  if(R->Size>A->Size)
  {
    R->Num[iter] = carry;
    iter++;
     while(iter < R->Size)
     {
       R->Num[iter]=0x00;
       iter++;
     }
  }
}


void _P1(struct num* A)
{ 
  //Addition with the same number Hope you dont overflow ?
  unsigned char iter = 0;
  unsigned char carry_next = 1;
  while(carry_next)
  {
    if(A->Num[iter] > 0xFE) carry_next = 1;
    else carry_next =0;
    A->Num[iter] = A->Num[iter] + 1;
    iter++;
  }
}

void _M1(struct num* A)
{ 
  //Addition with the same number Hope you dont overflow ?
  unsigned char iter = 0;
  unsigned char carry_next = 1;
  while(carry_next)
  {
    if(A->Num[iter] < 0x01) carry_next = 1;
    else carry_next =0;
    A->Num[iter] = A->Num[iter] - 1;
    iter++;
  }
}

/*Substraction between 2 num. Make sure A greater than B*/
void _SUB(struct num* A, struct num *B, struct num *R)
{
  //Do verif here
  //Assume Size A == Size B.
  unsigned char Size = A->Size;
  unsigned char iter =0;
  unsigned char carry =0;
  unsigned char SUB = 0; // Var for calcul addition and safe overflow
  for(iter =0; iter < Size; iter++)
  {
    SUB = A->Num[iter] - B->Num[iter] - carry;
    //IF c = 0 A<B carry or A<=B if allready c
    if(carry ? A->Num[iter]<=B->Num[iter] : A->Num[iter]<B->Num[iter])
    {
      carry = 1;
    }
    else
    {
      carry = 0;
    }
    R->Num[iter] = SUB;
  }
  if(R->Size > A->Size)
  { 
    unsigned char Finish = carry ? (unsigned char)0xFF : (unsigned char)0x00;
    while(iter < R->Size)
    {
      R->Num[iter] = Finish;
      iter++;
    }
  }
  
}

/*So like ADD, but with mull*/
void _MULL(struct num* A, struct num *B, struct num *R)
{
  /*Round 1 R[n*2]R[n*2 +1] = A[n]*B[n] */
  unsigned char x = 0; //Index sur A
  unsigned char y = 0; //Index sur B
  unsigned char z = 0;//Index sur R
  unsigned short I;
  unsigned char* i = (unsigned char*)&I;
  struct num* mulp = newNum(R->Size);
  struct num* muli = newNum(R->Size);

  for(y=0; y<B->Size;y++)
  {
    //Y représente l’index sur B
    z = y;
    for(x=0; x<A->Size; x++)
    {
      /*Fill up 2 register that multiplication dint need add, then add the 2 register*/
      I = A->Num[x] * B->Num[y];
      mulp->Num[z] = i[0];
      z++;
      mulp->Num[z] = i[1];
      x++;
      if(x < A->Size)
      {
        I = A->Num[x] * B->Num[y];
        muli->Num[z] = i[0];
        z++;
        muli->Num[z] = i[1];
      }
    }
    _ADD(R,muli,R);
    _ADD(R,mulp,R);
    clearNum(muli);
    clearNum(mulp);
  }
  /*Clear */
  delNum(mulp);
  delNum(muli);
}

/*division  between 2 num*/
/*
DIVISON, return Quotient in Q an Rest in R.
If Q and R could be null.
*/
void _DIV(struct num *N,struct num* D,struct num* Q, struct num*R)
{
	//Preparation 
	struct num * Ql = (Q == NULL) ? newNum(N->Size) :Q;
	struct num * Rl = (R == NULL) ? newNum(N->Size) :R;

  //Precalcul test 
  char test = _CMP(D,N);
  if(test>0) //N<D
  {
    clearNum(Ql);
    copyNum(N,Rl);
  }

  if(test == 0)
  {
    clearNum(Rl);
    Ql->Num[0]=0x01;
  }
  
  if(test<0) //N>D
  {
    struct num * calcul = newNum(N->Size);

    signed short i = (N->Size * 8) -1;
    unsigned char mask = 0x80;
    unsigned char index = N->Size -1 ;

    while(i >= 0)
    {
      _LSHIFT(Rl,1);
      Rl->Num[0] |= (N->Num[index] & mask)?0x01:0x00;
      if(_CMP(Rl,D)>=0)
      {
        clearNum(calcul);
        _SUB(Rl,D,calcul);
        copyNum(calcul,Rl);
        Ql->Num[index] |= mask ;
      }

      mask = mask >> 1;
      if(mask == 0)
      {
        mask = 0x80;
        index --;
      }
      i--;
    }
    delNum(calcul);
  } 
	
	if(Q == NULL) delNum(Ql);
	if(R == NULL) delNum(Rl);
}