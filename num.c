#include"num.h"

void __hang(void)
{
  printf("hang :-(\n");
  printf("All work and no play make me a doll boy.");
  exit(EXIT_FAILURE);
}

/*Checking rules like buffers equals size, +1 size or x2*/
void __checkRules(void)
{
  /*YEAP it could be cool and Secure*/
  /*And give me all the succes, and buy punta cana */
}

struct num* newNum(unsigned char Size)
{
  struct num* NUM = malloc(sizeof(struct num));
  if(NUM == NULL)__hang();
  unsigned char* N = malloc(sizeof(unsigned char)*Size);
  if(N == NULL)__hang();
  NUM->Num = N;
  NUM->Size = Size;
  //printf(".");
  clearNum(NUM);
  return NUM;
} 

void delNum(struct num* N)
{
  free(N->Num);
  free(N);
  return;
}

void clearNum(struct num* N)
{
  unsigned char i = 0;
  for(i=0;i<N->Size;i++)
  {
    N->Num[i] = (unsigned char)0;
  }
}

void printNum(struct num* N)
{
  unsigned char Size = N->Size-1;
  printf("0x");
  while(Size > 0)
  {
    printf("%02x",N->Num[Size]);
    Size--;
  }
  printf("%02x\n",N->Num[0]);
}

/*A->size should be equal to B->Size*/
void copyNum(struct num* A, struct num *B)
{
  unsigned char X = A->Size -1;
  for(;X>0;X--)
  {
    B->Num[X] = A->Num[X];
  }
  /*One more time*/
  B->Num[X] = A->Num[X];
}

/*Fill the num structure with string ex: "123456789\0"*/
void str2Num(struct num* N, char* S)
{
  //Tests HEXA is given.
  if( S[0]==0x30 && S[1]==0x78) //Test 0 and x
  {
    S++;//Remove "0x"
    S++; //Remove "0x"
    short Size =0;
    while(S[Size] != 0x00)Size++;
    //printf("len(S) = %d\n",Size);
    if(Size > 2*N->Size)
    {
      printf("[Error] str2Num str len greater than number size\n");
      exit(EXIT_FAILURE);
    }
    if(Size%2 != 0)
    {
      printf("[Error] str2Num str lack hexa digit.\n");
      exit(EXIT_FAILURE);
    }
    char iter = Size -1;
    unsigned char NumIter = 0;
    clearNum(N); //Be sure every Byte are clear.
    for(;iter>0;iter-=2)
    {
      unsigned char NUM = ((S[iter]-0x30 )+ ((S[iter-1]-0x30)<<4));
      printf("%x\n",NUM);
      N->Num[NumIter] = NUM;
      NumIter ++;
    }

  }
  else
  {
    printf("[Error] str2Num str is not 0x string\n");
    exit(EXIT_FAILURE);
  }

}