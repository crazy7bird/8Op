#include "Tests.h"
#include <stdint.h>

char testM1(void)
{
    //Test var
    int Error = 0;
    //Variables
    struct num *A = newNum(4);
    uint32_t *r = (uint32_t *)A->Num; //Generate WARNING, it’s OK

    //Test 1 0-1.
    str2Num(A,"0x00");
    _M1(A);
    if(*r != 0xFFFFFFFF)
    {
        printf("[_P1]Test 1 fail : %x\n", *r);
        Error ++;
    }

    //Test 2 digit down carry
    str2Num(A,"0x0100");
    _M1(A);
    if(*r != 0xFF)
    {
        printf("[_P1]Test 2 fail : %x\n", *r);
        Error++;
    }

    //Test 3 Max.
    str2Num(A,"0xFFFFFFFF");
    _M1(A);
    if(*r != 0xFFFFFFFE)
    {
        printf("[_P1]Test 3 fail : %x\n", *r);
        Error++;
    }


    //End
    if(!Error)
    {
        printf("_M1 no Error\n");
    }
    return Error;

}

