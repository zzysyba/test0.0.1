/*##############################
Author:zzy                  
Create_Time:2020-05-16
Versios:1.0
##############################*/
#include "zhaizy.h" 

void perr(char* str) 
{
	perror(str);
	exit(1);
}

void *thfun(void *arg)
{
	while(1)
	{
		printf("im ailving\n");
		sleep(1);
	}
	return NULL;
}


int main(int argc, char* argv[])
{
	pthread_t tid;
	int ret;	
	ret = pthread_create(&tid, NULL,thfun,NULL);
	if(ret != 0)
	{
		perr("pthread error");
	}
	sleep(3);
	ret = pthread_cancel(tid);
	if(ret != 0)
	{
		perr("pthread error");
	}




	return 0; 
}


