#include "Tests.h"

void AutoTests(void)
{
    int Error = 0;
    printf("START AutoTests :\n");
    Error += testADD();
	Error += testP1();
	Error += testM1();
    Error += testSUB();
    printf("END AutoTests with %d error(s)", Error);
}