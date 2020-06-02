#include "zhaizy.h"
/***************************************************************
            			linux系统编程学习--2020/5/9
            			makefile学习
****************************************************************/


int main(void)
{
	int a = 10;
	int b = 5;
	printf("%d * %d = %d\n",a,b,mul(a,b));
	printf("%d + %d = %d\n",a,b,add(a,b));
	printf("%d - %d = %d\n",a,b,sub(a,b));
	printf("%d / %d = %d\n",a,b,div1(a,b));
	return 0;
}


