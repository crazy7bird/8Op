#include "Tests.h"
#include <stdint.h>

char testDIV(void)
{
    int Error = 0;
    //Variables
    struct num *N = newNum(2);
    struct num *D = newNum(2);
    struct num *Q = newNum(4);
    struct num *R = newNum(4);


    uint32_t *r = (uint32_t *)R->Num; 
    uint32_t *q = (uint32_t *)Q->Num;

    unsigned short y = 0;
    unsigned short x = 0;
    for(y=1;y<256;y++)
    {
        for(x=0;x<256;x++)
        {
            N->Num[0] = (unsigned char)(x);
            D->Num[0] = (unsigned char)(y);
            _DIV(N,D,Q,R);
            if((*q != (x/y)) || (*r != (x%y)))
            {
            printf("[_DIV]Test BruteForce fail @ %x / %x: %x ; %x (wanted %x ; %x)\n",x,y,*q,*r,(x/y),(x%y));
                Error++;
                return 1;
            }
        }
    }
/*
    //Test 6 A = A - B
    str2Num(A,"0xFF");
    str2Num(B,"0xFF");
    _MUL(A,B,A);
    if(A->Num[0] != 0x01 || A->Num[1] != 0xFE)
    {
        printf("[_MULL]Test 6 fail : %x%x\n", A->Num[1],A->Num[0]);
        Error++;
    }
    //Test 7 A = A - A Serious ? who do that ?
    str2Num(A,"0xFF");
    _MUL(A,A,A);
    if(A->Num[0] != 0x01 || A->Num[1] != 0xFE)
    {
        printf("[_MULL]Test 7 fail : %x%x\n", A->Num[1],A->Num[0]);
        Error++;
    }
*/
    //End
    if(!Error)
    {
        printf("_DIV no Error\n");
    }
    return Error;

}

