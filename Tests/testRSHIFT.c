#include "Tests.h"
#include <stdint.h>

char testRSHIFT(void)
{
    int Error=0;
    //Variables
    struct num *A = newNum(4);
    uint32_t *r = (uint32_t *)A->Num;

    //Test 0 >> 1.
    str2Num(A,"0x00");
    _RSHIFT(A,1);
    if(*r != 0)
    {
        printf("[_RSHIFT]Test 1 fail : %x\n", *r);
        Error++;
    }
    
    //Test 0>>8
    str2Num(A,"0x00");
    _RSHIFT(A,8);
    if(*r != 0)
    {
        printf("[_RSHIFT]Test 2 fail : %x\n", *r);
        Error++;
    }

    //Test 3 0>>9
    str2Num(A,"0x00");
    _RSHIFT(A,9);
    if(*r != 0)
    {
        printf("[_RSHIFT]Test 3 fail : %x\n", *r);
        Error++;
    }

    //Test 4 on  full number >>1
    str2Num(A,"0x87654321");
    _RSHIFT(A,1);
    if(*r != 0x43B2A190)
    {
        printf("[_RSHIFT]Test 4 fail : %x\n", *r);
        Error++;
    }

    //Test 5 on  full number >>8
    str2Num(A,"0x87654321");
    _RSHIFT(A,8);
    if(*r != 0x00876543)
    {
        printf("[_RSHIFT]Test 5 fail : %x\n", *r);
        Error++;
    }

    //Test 6 on  full number >>9
    str2Num(A,"0x87654321");
    _RSHIFT(A,9);
    if(*r != 0x0043B2A1)
    {
        printf("[_RSHIFT]Test 6 fail : %x\n", *r);
        Error++;
    }

    //Test 7 overly large shift 34
    str2Num(A,"0x87654321");
    _RSHIFT(A,34);
    if(*r != 0x0)
    {
        printf("[_RSHIFT]Test 7 fail : %x\n", *r);
        Error++;
    }

    //End
    if(!Error)
    {
        printf("_RSHIFT no Error\n");
    }
    return Error;
}

