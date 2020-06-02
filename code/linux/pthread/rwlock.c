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


pthread_rwlock_t rwlock;
int counter = 1;

void *rlock(void *arg)
{	
	while(1)
	{
		usleep(10000*(rand()%3));
		pthread_rwlock_rdlock(&rwlock);
		usleep(10000*(rand()%3));
		printf("----------read%d c = %d\n ",(int)arg,counter);
		pthread_rwlock_unlock(&rwlock);
		usleep(10000*(rand()%3));
	}

	return NULL;
}
void *wlock(void *arg)
{
	
	while(1)
	{
		usleep(10000*(rand()%3));
		pthread_rwlock_wrlock(&rwlock);
		counter++;
		usleep(10000*(rand()%3));
		printf("write%d c = %d------\n ",(int)arg,counter);
		pthread_rwlock_unlock(&rwlock);
		usleep(10000*(rand()%3));
	}
	return NULL;
}

int main(int argc, char* argv[])
{
	

	pthread_t tid[8];
	pthread_rwlock_init(&rwlock,NULL);
	for(int i = 0; i < 3 ; i++)
	{
		pthread_create(&tid[i], NULL, wlock, (void*)i);
	}
	for(int i = 0; i < 5 ; i++)
	{
		pthread_create(&tid[i + 3], NULL, rlock, (void*)i);
	}
	for(int i = 0; i < 3 ; i++)
	{
		pthread_join(tid[i],NULL);
	}
	pthread_rwlock_destroy(&rwlock);
	return 0; 
}


