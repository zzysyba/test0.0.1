#include "rt_stub.h"
#include <stdio.h>
#include <stdlib.h>

int a(int p1,int p2)
{
	return p1 + p2;
}

int stub1(int p1, int p2)
{
	return p1 -p2;
}

int stub2(int p1, int p2)
{
	return p1 * p2;
}

int main(void)
{	
	int index1;
	int index2;


	int	rc = a( 3, 2);
	printf("rc = %d\n", rc);

	rtstub_begin();
	rtstub_create2((void*)a, (void *)stub1, &index1);
	
 	rc = a( 3, 2);
	printf("rc = %d\n", rc);

	rtstub_create2((void*)a, (void *)stub2, &index2);

	rc = a( 3, 2);
	printf("rc = %d\n", rc);
	
	rtstub_destroy2(index2);
	rtstub_destroy2(index1);
	rtstub_end();



/*	rtstub_begin();
	rtstub_create((void *)a, (void*)stub1);
	rc = a( 3, 2);
	printf("rc = %d\n", rc);	
	rtstub_destroy((void *)a);

	rtstub_create((void *)a, (void*)stub2);
	rc = a( 3, 2);
	printf("rc = %d\n", rc);	
	rtstub_destroy((void *)a);

	rtstub_end();
*/
	return 0;
}

