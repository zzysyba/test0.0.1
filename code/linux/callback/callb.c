/*##############################
Author:zzy                  
Create_Time:2020-05-26
Versios:1.0
##############################*/
#include "zhaizy.h" 
 

 
void (*step)(char *) = NULL;

void nextdo(int time, char* what)
{
	
	while(1)
	{
		step(what);
		sleep(time);
	}
}

void myprint(char* mwhat)
{
	printf("%s\n",mwhat);
}

int main(int argc, char* argv[])
{
 	printf("lalalalalal1\n");
	void(*p)(int , char*) = &nextdo; 
 	printf("lalalalalal2\n");
	step = myprint; 	
 	printf("lalalalalal3\n");
 	p(1,"eat");
 	printf("lalalalalal4\n");

	return 0; 
}
 

