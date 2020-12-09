#include "Tests.h"
#include <stdint.h>

char testP1(void)
{
    int Error=0;
    //Variables
    struct num *A = newNum(4);
    uint32_t *r = (uint32_t *)A->Num; //Generate WARNING, it’s OK

    //Test 1 0+1.
    str2Num(A,"0x00");
    _P1(A);
    if(*r != 1)
    {
        printf("[_P1]Test 1 fail : %x\n", *r);
        Error++;
    }

    //Test 2 FF +1.
    str2Num(A,"0xFF");
    _P1(A);
    if(*r != 0x100)
    {
        printf("[_P1]Test 2 fail : %x\n", *r);
        Error++;
    }

    //Test 3 Overflow.
    str2Num(A,"0xFFFFFFFF");
    _P1(A);
    if(*r != 0)
    {
        printf("[_P1]Test 3 fail : %x\n", *r);
        Error++;
    }


    //End
    if(!Error)
    {
        printf("_P1 no Error\n");
    }
    return Error;
}

