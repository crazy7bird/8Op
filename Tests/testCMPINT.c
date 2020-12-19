#include "Tests.h"
#include <stdint.h>

char testCMPINT(void)
{
    int Error=0;
    //Variables
    struct num *A = newNum(4);

    unsigned char r;

    //Test 1 CMPINT equal
    str2Num(A,"0x00");
    r = _CMPINT(A,0);
    if(r != 0)
    {
        printf("[_CMPINT]Test 1 fail : %x\n", r);
        Error++;
    }

    //Test 2 CMPINT equal big number.
    str2Num(A,"0xFF");
    r = _CMPINT(A,0xFF);
    if(r != 0)
    {
        printf("[_CMPINT]Test 2 fail : %x\n", r);
        Error++;
    }

    //Test 3 CMPINT biger.
    str2Num(A,"0x0100");
    r = _CMPINT(A,0xFF);
    if(r != 1)
    {
        printf("[_CMPINT]Test 3 fail : %x\n", r);
        Error++;
    }

    //Test 4 CMPINT smaller.
    str2Num(A,"0x01");
    r = _CMPINT(A,0xFF);
    if(r != (unsigned char)(-1))
    {
        printf("[_CMPINT]Test 4 fail : %x\n", r);
        Error++;
    }



    //End
    if(!Error)
    {
        printf("_CMPINT no Error\n");
    }
    return Error;
}

