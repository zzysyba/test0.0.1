#include "zhaizy.h"

int div1(int a,int b)
{
	return a / b;
}


int main(void)
{
	int a = 10;
	int b = 5;

	printf("%d / %d = %d\n",a,b,div1(a,b));
	return 0;
}