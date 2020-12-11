#include "Tests.h"
#include <stdint.h>

char testSUB(void)
{
    int Error = 0;
    //Variables
    struct num *A = newNum(2);
    struct num *B = newNum(2);
    struct num *R = newNum(4);

    uint32_t *r = (uint32_t *)R->Num; //Generate WARNING, it’s OK

    //Test 1 soustraction de base.
    str2Num(A,"0x01");
    str2Num(B,"0x01");
    _SUB(A,B,R);
    if(*r != 0)
    {
        printf("[_SUB]Test 1 fail : %x\n", *r);
        Error++;
    }

    //Test 2 carry overflow
    str2Num(A,"0x01");
    str2Num(B,"0xFF");
    _SUB(A,B,R);
    if(*r != 0xFFFFFF02)
    {
        printf("[_SUB]Test 2 fail : %x\n",*r);
        Error++;
    }

    //Test 3 overflow 
    str2Num(A,"0xFF");
    str2Num(B,"0xFF");
    _SUB(A,B,R);
    if(*r != 0)
    {
        printf("[_SUB]Test 3 fail : %x\n", *r);
        Error++;
    }

    //Test 4 limits
    str2Num(A,"0xFFFF");
    str2Num(B,"0xFFFF");
    _SUB(A,B,R);
    if(*r != 0)
    {
        printf("[_SUB]Test 4 fail : %x\n", *r);
        Error++;
    }

    //Test 5 purity 
    str2Num(A,"0x10");
    str2Num(B,"0x01");
    str2Num(R,"0x12345678");
    _SUB(A,B,R);
    if(*r != 0x0F)
    {
        printf("[_SUB]Test 5 fail : %x\n", *r);
        Error++;
    }

    //Test 6 A = A - B
    str2Num(A,"0xFF");
    str2Num(B,"0xEE");
    _SUB(A,B,A);
    if(A->Num[0] != 0x11 || A->Num[1] != 0x00)
    {
        printf("[_SUB]Test 6 fail : %x%x\n", A->Num[1],A->Num[0]);
        Error++;
    }
    //Test 7 A = A - A Serious ? who do that ?
    str2Num(A,"0xFF");
    _SUB(A,A,A);
    if(A->Num[0] != 0x00 || A->Num[1] != 0x00)
    {
        printf("[_SUB]Test 7 fail : %x%x\n", A->Num[1],A->Num[0]);
        Error++;
    }

    unsigned short y = 0;
    unsigned short x = 0;
    A->Num[1] = 0;
    B->Num[1] = 0;
    for(y=0;y<256;y++)
    {
        for(x=0;x<256;x++)
        {
            A->Num[0] = (unsigned char)(x);
            B->Num[0] = (unsigned char)(y);
            _SUB(A,B,R);
            if(*r != (x-y))
            {
                printf("[_ADD]Test BruteForce fail @ %x + %x: %x (wanted %x)\n",x,y,*r,(x-y));
                Error++;
            }
        }
    }


    //End
    if(!Error)
    {
        printf("_SUB no Error\n");
    }
    return Error;

}

