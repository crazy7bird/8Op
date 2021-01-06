#include "Tests.h"
#include <stdint.h>

char testDIV(void)
{
    int Error = 0;
    //Variables
    struct num *N = newNum(4);
    struct num *D = newNum(4);
    struct num *Q = newNum(4);
    struct num *R = newNum(4);


    uint32_t *r = (uint32_t *)R->Num; 
    uint32_t *q = (uint32_t *)Q->Num;

    unsigned short y = 0;
    unsigned short x = 0;
    for(y=1;y<256;y++)
    {
        for(x=0;x<256;x++)
        {
            N->Num[0] = (unsigned char)(x);
            D->Num[0] = (unsigned char)(y);
            _DIV(N,D,Q,R);
            if((*q != (x/y)) || (*r != (x%y)))
            {
            printf("[_DIV]Test BruteForce fail @ %x / %x: %x ; %x (wanted %x ; %x)\n",x,y,*q,*r,(x/y),(x%y));
                Error++;
                return 1;
            }
        }
    }

    //Test clean
    /*
    str2Num(N,"0xFFFF");
    str2Num(D,"0x1000");
    str2Num(Q,"0xFF00");
    str2Num(R,"0x00FF");
*/
    //Test 2: A = A / B
    str2Num(N,"0xFFFF");
    str2Num(D,"0x1000");
    _DIV(N,D,N,R);
    if(N->Num[0] != 0x00 || N->Num[1] != 0x0F)
    {
        printf("[_DIV]Test 2 fail : %x%x\n", N->Num[1],N->Num[0]);
        Error++;
    }
    /*
    //Test 3: A = A * A Yhea A²
    str2Num(A,"0xFF");
    _MUL(A,A,A);
    if(A->Num[0] != 0x01 || A->Num[1] != 0xFE)
    {
        printf("[_MUL]Test 3 fail : %x%x\n", A->Num[1],A->Num[0]);
        Error++;
    }
    */
    //End
    if(!Error)
    {
        printf("_DIV no Error\n");
    }
    return Error;

}

