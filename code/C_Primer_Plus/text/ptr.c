/*##############################
Author:zzy                  
Create_Time:2020-05-23
Versios:1.0
##############################*/
#include <stdio.h>

long A = 1;
long B = 2;
 
void fun(long* p1)
{
	
	*p1 = (long)&B;
}

int main(int argc, char* argv[])
{
	
	long* ptr1 = &A;

	printf("ptr1:%p,%ld\n",ptr1,*ptr1);

	printf("**********************\n");
	fun(ptr1);
	printf("ptr1:%p,%p,%ld\n",ptr1,*(long**)ptr1,**(long**)ptr1);


	return 0; 
}
 

