#include "Tests.h"
#include <stdint.h>

char testMULL(void)
{
    int Error = 0;
    //Variables
    struct num *A = newNum(2);
    struct num *B = newNum(2);
    struct num *R = newNum(4);

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
            _MULL(A,B,R);
            if(*r != (x*y))
            {
                printf("[_MULL]Test BruteForce fail @ %x x %x: %x (wanted %x)\n",x,y,*r,(x*y));
                Error++;
            }
        }
    }

    //End
    if(!Error)
    {
        printf("_MULL no Error\n");
    }
    return Error;

}

