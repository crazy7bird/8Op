#include "Tests.h"
#include <stdint.h>

char testLSHIFT(void)
{
    int Error=0;
    //Variables
    struct num *A = newNum(4);
    struct num *B = newNum(1); //For overflow catch.
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

    //Test 3 0<<9
    str2Num(A,"0x00");
    _LSHIFT(A,9);
    if(*r != 0)
    {
        printf("[_LSHIFT]Test 3 fail : %x\n", *r);
        Error++;
    }

    printf("[_LSHIFT] If crash, it's an overflow fault that creat sigtrap...\n");
    
    //Test 4 on  full number <<1
    str2Num(A,"0x87654321");
    _LSHIFT(A,1);
    if(*r != 0x0ECA8642)
    {
        printf("[_LSHIFT]Test 4 fail : %x\n", *r);
        Error++;
    }

    //Test 5 on  full number <<8
    str2Num(A,"0x87654321");
    _LSHIFT(A,8);
    if(*r != 0x65432100)
    {
        printf("[_LSHIFT]Test 5 fail : %x\n", *r);
        Error++;
    }

    //Test 6 on  full number <<9
    str2Num(A,"0x87654321");
    _LSHIFT(A,9);
    if(*r != 0xCA864200)
    {
        printf("[_LSHIFT]Test 6 fail : %x\n", *r);
        Error++;
    }

    //Test 7 overly large shift 34
    str2Num(A,"0x87654321");
    _LSHIFT(A,34);
    if(*r != 0x0)
    {
        printf("[_LSHIFT]Test 7 fail : %x\n", *r);
        Error++;
    }


    //Test 8 not print over the number
    clearNum(B); //For using it.
    unsigned char b = (unsigned char)A->Num[4];
    str2Num(A,"0x87654321");
    _LSHIFT(A,8);
    //printf("%x = %x\n",B, A->Num[4]);
    if(b != A->Num[4])
    {
        printf("[_LSHIFT]Test 8 fail : %x = %x\n",b, A->Num[4]);
        Error++;
    }

    //End
    if(!Error)
    {
        printf("_LSHIFT no Error\n");
    }
    return Error;
}

