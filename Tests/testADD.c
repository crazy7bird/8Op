#include "Tests.h"
#include <stdint.h>

char testADD(void)
{
    int Error = 0;
    //Variables
    struct num *A = newNum(2);
    struct num *B = newNum(2);
    struct num *R = newNum(4);

    uint32_t *r = (uint32_t *)R->Num; //Generate WARNING, it’s OK

    //Test 1 addition de base.
    str2Num(A,"0x01");
    str2Num(B,"0x01");
    _ADD(A,B,R);
    if(*r != 2)
    {
        printf("[_ADD]Test 1 fail : %x\n", *r);
        Error++;
    }

    //Test 2 carry
    str2Num(A,"0x01");
    str2Num(B,"0xFF");
    _ADD(A,B,R);
    if(*r != 0x100)
    {
        printf("[_ADD]Test 2 fail : %x\n",*r);
        Error++;
    }

    //Test 3 overflow 
    str2Num(A,"0xFF");
    str2Num(B,"0xFF");
    _ADD(A,B,R);
    if(*r != 0x1FE)
    {
        printf("[_ADD]Test 3 fail : %x\n", *r);
        Error++;
    }

    //Test 4 limits
    str2Num(A,"0xFFFF");
    str2Num(B,"0xFFFF");
    _ADD(A,B,R);
    if(*r != 0x1FFFE)
    {
        printf("[_ADD]Test 4 fail : %x\n", *r);
        Error++;
    }

    //Test 5 purity 
    str2Num(A,"0x01");
    str2Num(B,"0x00");
    str2Num(R,"0x12345678");
    _ADD(A,B,R);
    if(*r != 0x01)
    {
        printf("[_ADD]Test 5 fail : %x\n", *r);
        Error++;
    }


    //End
    if(!Error)
    {
        printf("_ADD no Error\n");
    }
    return Error;

}

