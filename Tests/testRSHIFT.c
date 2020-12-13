#include "Tests.h"
#include <stdint.h>

char testRSHIFT(void)
{
    int Error=0;
    //Variables
    struct num *A = newNum(4);
    uint32_t *r = (uint32_t *)A->Num;

    //Test 0 << 1.
    str2Num(A,"0x00");
    _RSHIFT(A,1);
    if(*r != 0)
    {
        printf("[_RSHIFT]Test 1 fail : %x\n", *r);
        Error++;
    }

    //Test 0<<8
    str2Num(A,"0x00");
    printNum(A);
    _RSHIFT(A,8);
    printNum(A);
    if(*r != 0)
    {
        printf("[_RSHIFT]Test 2 fail : %x\n", *r);
        Error++;
    }


    //End
    if(!Error)
    {
        printf("_RSHIFT no Error\n");
    }
    return Error;
}

