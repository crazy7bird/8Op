#include "Tests.h"
#include <stdint.h>

char testMUL(void)
{
    int Error = 0;
    //Variables
    struct num *A = newNum(2);
    struct num *B = newNum(2);
    struct num *R = newNum(4);

    uint32_t *r = (uint32_t *)R->Num; //Generate WARNING, it’s OK

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
                printf("[_MUL]Test BruteForce fail @ %x x %x: %x (wanted %x)\n",x,y,*r,(x*y));
                Error++;
            }
        }
    }

    //Test 2: A = A * B
    str2Num(A,"0xFF");
    str2Num(B,"0xFF");
    _MUL(A,B,A);
    if(A->Num[0] != 0x01 || A->Num[1] != 0xFE)
    {
        printf("[_MULL]Test 2 fail : %x%x\n", A->Num[1],A->Num[0]);
        Error++;
    }
    //Test 3: A = A * A Yhea A²
    str2Num(A,"0xFF");
    _MUL(A,A,A);
    if(A->Num[0] != 0x01 || A->Num[1] != 0xFE)
    {
        printf("[_MUL]Test 3 fail : %x%x\n", A->Num[1],A->Num[0]);
        Error++;
    }

    //End
    if(!Error)
    {
        printf("_MULL no Error\n");
    }
    return Error;

}

