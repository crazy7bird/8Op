#include "Tests.h"
#include <stdint.h>

char testDIV(void)
{
    int Error = 0;
    //Variables
    struct num *N = newNum(2);
    struct num *D = newNum(2);
    struct num *Q = newNum(2);
    struct num *R = newNum(2);


    uint32_t *r = (uint32_t *)R->Num; //Generate WARNING, it’s OK
/*
    //Test 1 soustraction de base.
    str2Num(A,"0x01");
    str2Num(B,"0x01");
    _MULL(A,B,R);
    if(*r != 0)
    {
        printf("[_MULL]Test 1 fail : %x\n", *r);
        Error++;
    }
*/
    unsigned short y = 0;
    unsigned short x = 0;
    for(y=0;y<256;y++)
    {
        for(x=0;x<256;x++)
        {
            A->Num[0] = (unsigned char)(x);
            B->Num[0] = (unsigned char)(y);
            _MUL(A,B,R);
            if(*r != (x*y))
            {
                printf("[_MULL]Test BruteForce fail @ %x x %x: %x (wanted %x)\n",x,y,*r,(x*y));
                Error++;
            }
        }
    }

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

    //End
    if(!Error)
    {
        printf("_MULL no Error\n");
    }
    return Error;

}

