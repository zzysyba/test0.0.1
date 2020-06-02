/*##############################
Author:zzy                  
Create_Time:2020-05-16
Versios:1.0
##############################*/
#include "zhaizy.h" 

struct ath{
	char data[20];
};



void *thfun(void *arg)
{
	int i = (int)arg;
	if(i == 2)
	{
		pthread_exit(NULL);
	}

	printf("im pthread:%d my pid = %d,my tid = %ld,and data = %d\n",i+1,getpid(),pthread_self());
	return NULL;
}


int main(int argc, char* argv[])
{
	

	pthread_t tid;
	int ret;	
	for(int i = 0;i < 5 ;++i)
	{
		ret = pthread_create(&tid, NULL,thfun,(void*)i);
		if(ret != 0)
		{
			perr("pthread error");
		}
	}
	pthread_exit(NULL);	
	sleep(1);	
	printf("im parent    my pid = %d\tmy tid = %ld\n",getpid(),pthread_self());



	return 0; 
}


