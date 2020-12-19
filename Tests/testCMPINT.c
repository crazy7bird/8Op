#include "Tests.h"
#include <stdint.h>

char testCMPINT(void)
{
    int Error=0;
    //Variables
    struct num *A = newNum(4);
    struct num *B = newNum(4);

    unsigned char r;

    //Test 1 CMPINT equal
    str2Num(A,"0x00");
    str2Num(B,"0x00");
    r = _CMPINT(A,B);
    if(r != 0)
    {
        printf("[_CMPINT]Test 1 fail : %x\n", r);
        Error++;
    }

    //Test 2 CMPINT equal big number.
    str2Num(A,"0x12345678");
    str2Num(B,"0x12345678");
    r = _CMPINT(A,B);
    if(r != 0)
    {
        printf("[_CMPINT]Test 2 fail : %x\n", r);
        Error++;
    }

    //Test 3 CMPINT biger.
    str2Num(A,"0x12345679");
    str2Num(B,"0x12345670");
    r = _CMPINT(A,B);
    if(r != 1)
    {
        printf("[_CMPINT]Test 3 fail : %x\n", r);
        Error++;
    }

    //Test 4 CMPINT smaller.
    str2Num(A,"0x12345670");
    str2Num(B,"0x12345679");
    r = _CMPINT(A,B);
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

