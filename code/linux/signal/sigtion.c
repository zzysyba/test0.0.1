/*##############################
Author:zzy                  
Create_Time:2020-05-15
Versios:1.0
##############################*/
#include "zhaizy.h" 
 
void perr(char* str) 
{
		perror(str);
		exit(1);
}

void sig_catch(int signo)
{
	printf("catch you %d\n",signo);
}

int main(int argc, char* argv)
{
	struct sigaction act,oldact;

	act.sa_handler =sig_catch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;


	int ret = sigaction(SIGINT, &act, &oldact);
	if(ret == -1)
	{
		perr("sigaction error");
	}
	while(1);
 
	return 0; 
}
 

