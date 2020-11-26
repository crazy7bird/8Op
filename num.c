#include"num.h"

void __hang(void)
{
  printf("hang :-(\n");
  exit(EXIT_FAILURE);
}
struct num* NewNum(unsigned char Size)
{
  struct num* NUM = malloc(sizeof(struct num));
  if(NUM == NULL)__hang();
  unsigned char* N = malloc(sizeof(unsigned char)*Size);
  if(N == NULL)__hang();
  NUM->Num = N;
  NUM->Size = Size;
  //printf(".");
  return NUM;
} 

void DelNum(struct num* N)
{
  free(N->Num);
  free(N);
  return;
}

void clearNum(struct num* N)
{
  char i = 0;
  for(i=0;i<N->Size;i++)
  {
    N->Num[i] = 0;
  }
}

void printnum(struct num* N)
{
  unsigned char Size = N->Size-1;
  printf("0x");
  while(Size > 0)
  {
    printf("%02x",N->Num[Size]);
    //printf("\n%d : %x\n",Size,N->Num[Size]);
    Size--;
  }
  printf("%02x\n",N->Num[0]);
 // printf("\n%d : %x\n",Size,N->Num[Size]);
}

/*A->size should be equal to B->Size*/
void copynum(struct num* A, struct num *B)
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
void strfillnum(struct num* N, char* S)
{
  /*
    Simple
    pour chaque digit de S
    converti une chaine S en num ?
  */
  
  /*S size*/
  short Size =0;
  while(S[Size] != 0x00)Size++;
  printf("len(S) = %d\n",Size);
}