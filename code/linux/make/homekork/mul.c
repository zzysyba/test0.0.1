#include "zhaizy.h"

int mul(int a,int b)
{
	return a*b;
}

int main(void)
{
	int a = 10;
	int b = 5;
	printf("%d * %d = %d\n",a,b,mul(a,b));
	return 0;
}