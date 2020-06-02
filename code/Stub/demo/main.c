#include <stdio.h>
#include <stdlib.h>
#include "stub.h"
#include <errno.h>



int b(int p1, char p2) 
{
	return p1 + p2;
}

int a(int p1, int p2) 
{
	int rc = 0;
	rc = b(p1, p2);
	if (rc < 0) {
		rc = -1;
	}
	return rc;
}

void testSuiteInit(void) 
{
	if (-1 == stub_init())
	{
		printf("faild to init stub\n");
		exit(0);
	}
}

/*
void testSuiteClean(void) 
{
	stub_exit();
}
*/

int bStub(int p1, char p2) 
{
	return p1 - p2;
}

void testCase(void)
{
	int rc = 0;
	struct func_stub stub;
	testSuiteInit();
	rc = a(1, 2);

	/* 把b函数替换成我们自己编写的bStub函数，替换后全局所有的b函数调用都会实际上调用到bStub函数 */
	stub_set(&stub, (int*)b, (int*)bStub);

	rc = a(1, 2);
	if(rc < 0)
	{
		perror("a error");
		exit(0);
	}
	printf("rc = %d\n",rc);

	stub_reset(&stub);
	/* 恢复b函数 */

}

int main(void)
{
	testCase();
	return 0;
}





