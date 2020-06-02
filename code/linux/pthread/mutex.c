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


pthread_mutex_t mutex;

void *thfun(void *arg)
{
	while(1)
	{
		sleep(rand()%2);
		pthread_mutex_lock(&mutex);
		printf("hellow ");
		sleep(rand()%2);
		printf("word\n");
		pthread_mutex_unlock(&mutex);
	}


	return NULL;
}


int main(int argc, char* argv[])
{
	

	pthread_t tid;
	int ret = pthread_mutex_init(&mutex,NULL);
	if(ret != 0)
	{
		fprintf(stderr,"pthread error:%s\n",strerror(ret));
		exit(1);
	}

	ret = pthread_create(&tid, NULL, thfun, NULL);
	if(ret != 0)
	{
		fprintf(stderr,"pthread error:%s\n",strerror(ret));
		exit(1);
	}

	while(1)
	{ 

	sleep(rand()%2);
	pthread_mutex_lock(&mutex);
	printf("HELLOW ");
	sleep(rand()%2);
	printf("WORD\n");
	pthread_mutex_unlock(&mutex);
	}

	pthread_mutex_destroy(&mutex);

	pthread_exit(NULL);	



	return 0; 
}


