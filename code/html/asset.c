/*##############################
Author:zzy                  
Create_Time:2020-05-27
Versios:1.0
##############################*/
#define NDEBUG
#include "zhaizy.h" 

void perr(char* str) 
{
		perror(str);
		exit(1);
}
 
int main(int argc, char* argv[])
{
	for(int i = 5; i > 0;i--)
	{
		printf("%d\n",i);
		assert(i >= 3);
	}
	 
	return 0; 
}
 

