#include "Tests.h"
#include <stdint.h>

char testSUB(void)
{
    int Error = 0;
    //Variables
    struct num *A = newNum(2);
    struct num *B = newNum(2);
    struct num *R = newNum(4);

    uint32_t *r = (uint32_t *)R->Num; //Generate WARNING, it’s OK

    //Test 1 soustraction de base.
    str2Num(A,"0x01");
    str2Num(B,"0x01");
    _SUB(A,B,R);
    if(*r != 0)
    {
        printf("[_SUB]Test 1 fail : %x\n", *r);
        Error++;
    }

    //Test 2 carry overflow
    str2Num(A,"0x01");
    str2Num(B,"0xFF");
    _SUB(A,B,R);
    if(*r != 0xFFFFFF02)
    {
        printf("[_SUB]Test 2 fail : %x\n",*r);
        Error++;
    }

    //Test 3 overflow 
    str2Num(A,"0xFF");
    str2Num(B,"0xFF");
    _SUB(A,B,R);
    if(*r != 0)
    {
        printf("[_SUB]Test 3 fail : %x\n", *r);
        Error++;
    }

    //Test 4 limits
    str2Num(A,"0xFFFF");
    str2Num(B,"0xFFFF");
    _SUB(A,B,R);
    if(*r != 0)
    {
        printf("[_SUB]Test 4 fail : %x\n", *r);
        Error++;
    }

    //Test 5 purity 
    str2Num(A,"0x10");
    str2Num(B,"0x01");
    str2Num(R,"0x12345678");
    _SUB(A,B,R);
    if(*r != 0x0F)
    {
        printf("[_SUB]Test 5 fail : %x\n", *r);
        Error++;
    }


    //End
    if(!Error)
    {
        printf("_SUB no Error\n");
    }
    return Error;

}

