#include "Tests.h"

void AutoTests(void)
{
    int Error = 0;
    printf("START AutoTests :\n");
    //All basics math operation from basicop.c
    Error += testADD();
	Error += testP1();
	Error += testM1();
    Error += testSUB();
    Error += testMUL();
    Error += testDIV();

    //All logicals operations from logicop.c
    Error += testRSHIFT();
    Error += testLSHIFT();


    printf("END AutoTests with %d error(s)", Error);
}