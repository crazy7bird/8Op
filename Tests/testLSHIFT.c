#include "Tests.h"
#include <stdint.h>

char testLSHIFT(void)
{
    int Error=0;
    //Variables
    struct num *A = newNum(4);
    uint32_t *r = (uint32_t *)A->Num;

    //Test 0 << 1.
    str2Num(A,"0x00");
    _LSHIFT(A,1);
    if(*r != 0)
    {
        printf("[_LSHIFT]Test 1 fail : %x\n", *r);
        Error++;
    }
    
    //Test 0<<8
    str2Num(A,"0x00");
    _LSHIFT(A,8);
    if(*r != 0)
    {
        printf("[_LSHIFT]Test 2 fail : %x\n", *r);
        Error++;
    }


    //End
    if(!Error)
    {
        printf("_LSHIFT no Error\n");
    }
    return Error;
}

