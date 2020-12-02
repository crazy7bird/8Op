#include "basicop.h"
#include "logicop.h" //Needed for _CMP(A,B) used by DIV algo



void _ADD(struct num* A, struct num *B, struct num *R)
{
  //Do verif here
  //Assume Size A == Size B. and Size R atleast SizeA+1
  char Size = A->Size;
  char iter =0;
  char carry =0;
  for(iter =0; iter < Size; iter++)
  {
    R->Num[iter] = A->Num[iter] + B->Num[iter];//FF + FF 
    if((R->Num[iter] < A->Num[iter]) || (R->Num[iter] < B->Num[iter]))
    {
      R->Num[iter] += carry;
      carry = 1;
    }
    else
    {
      R->Num[iter] += carry;
      carry = 0;
    }
  }
}


void _P1(struct num* A)
{ 
  //Addition with the same number Hope you dont overflow ?
  char iter = 0;
  char carry_next = 1;
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
  char iter = 0;
  char carry_next = 1;
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
  //Do R = a-(b + c)
  unsigned char index = A->Size;
  unsigned char x;
  unsigned char carry = 0;
  for (x=0; x<index;x++)
  {
    R->Num[x] = A->Num[x] - B->Num[x] - carry;
    if(R->Num[x]>A->Num[x] && R->Num[x]>B->Num[x])
    {
      carry = 1;
    }
    else carry = 0;
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
  struct num* add = newNum(R->Size);

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

    _ADD(mulp,muli,add);
    _ADD(R,add,R);
    clearNum(muli);
    clearNum(mulp);
    clearNum(add);
  }
  /*Clear */
  delNum(mulp);
  delNum(muli);
}

/*division  between 2 num*/
/*
if D = 0 then error(DivisionByZeroException) end
Q := 0                  -- Initialize quotient and remainder to zero
R := 0                     
for i := n − 1 .. 0 do  -- Where n is number of bits in N
  R := R << 1           -- Left-shift R by 1 bit
  R(0) := N(i)          -- Set the least-significant bit of R equal to bit i of the numerator
  if R ≥ D then
    R := R − D
    Q(i) := 1
  end
end
this algo is bit to bit how convert it Byte to Byte
*/

/*division  between 2 num*/
/*
if D = 0 then error(DivisionByZeroException) end
Q := 0                  -- Initialize quotient and remainder to zero
R := 0                     
for i := n − 1 .. 0 do  -- Where n is number of bits in N
  R := R << 1           -- Left-shift R by 1 bit
  R(0) := (N(i/8) & 0x1 << i%8)>>i%8          -- Set the least-significant bit of R equal to bit i of the numerator
  if R ≥ D then
    R := R − D
    Q(i/8) |= 1 <<i%8;
  end
end
Try to make it more for 8Bytes registers.
*/
void _DIV(struct num* N, struct num *D, struct num *Ret)
{
  /*To do check in B == 0 then return error divbyZer0*/
  struct num* Q = newNum(N->Size); /*Quotien*/
  struct num* R = newNum(N->Size); /*Remain*/
  struct num* calcul = newNum(N->Size); /*Buffer for calculs purpose*/
  char i =0;
  for(i=(N->Size); i>0; i--)
  {
    /*FuckIt i aint got leftshift*/
    _LSHIFT(R,8);
    R->Num[0] = N->Num[i -1];
    clearNum(calcul);
    if(_CMP(R,D)>=0)
    {
      _SUB(R,D,calcul);
      copyNum(calcul,R);
      Q->Num[i]= N->Num[i];
    }
  }
  printNum(Q);
  printNum(R);
}