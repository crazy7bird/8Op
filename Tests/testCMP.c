#include "Tests.h"
#include <stdint.h>

char testCMP(void)
{
    int Error=0;
    //Variables
    struct num *A = newNum(4);
    struct num *B = newNum(4);

    unsigned char r;

    //Test 1 CMP equal
    str2Num(A,"0x00");
    str2Num(B,"0x00");
    r = _CMP(A,B);
    if(r != 0)
    {
        printf("[_CMP]Test 1 fail : %x\n", r);
        Error++;
    }

    //Test 2 CMP equal big number.
    str2Num(A,"0x12345678");
    str2Num(B,"0x12345678");
    r = _CMP(A,B);
    if(r != 0)
    {
        printf("[_CMP]Test 2 fail : %x\n", r);
        Error++;
    }

    //Test 3 CMP biger.
    str2Num(A,"0x12345679");
    str2Num(B,"0x12345670");
    r = _CMP(A,B);
    if(r != 1)
    {
        printf("[_CMP]Test 3 fail : %x\n", r);
        Error++;
    }

    //Test 4 CMP smaller.
    str2Num(A,"0x12345670");
    str2Num(B,"0x12345679");
    r = _CMP(A,B);
    if(r != (unsigned char)(-1))
    {
        printf("[_CMP]Test 4 fail : %x\n", r);
        Error++;
    }



    //End
    if(!Error)
    {
        printf("_CMP no Error\n");
    }
    return Error;
}

