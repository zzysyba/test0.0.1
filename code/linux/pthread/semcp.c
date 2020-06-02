/*##############################
Author:zzy                  
Create_Time:2020-05-18
Versios:1.0
##############################*/
#include "zhaizy.h" 
#define  NUM  10

int queue[NUM];
sem_t blank,product;


void plist(void)
{
	printf("*********************\n");
	for(int i = 0; i < NUM; i++ )
	{
		printf("-%3d-",queue[i]);
	}
	printf("\n*********************\n");

}


void perr(char* str) 
{
	perror(str);
	exit(1);
}

void *consumer(void* p)
{
	int i = 0;
	while(1)
	{
	sem_wait(&product);
	printf("-----------consumer%3d\n",queue[i]);
	queue[i] = 0;
	plist();
	sem_post(&blank);
	
	i = (i + 1)%NUM;
	sleep(rand()%5);
	}

	return;
}

void *producer(void* p)
{
	int i = 0;
	while(1)
	{
	sem_wait(&blank);
	queue[i] = rand()% 1000 + 1;
	printf("producer---------%3d\n",queue[i]);
	plist();
	sem_post(&product);
	i = (i + 1) %NUM;
	sleep(rand()%5);


	}
	return;
}


int main(int argc, char* argv[])
{
	srand(time(NULL));

	sem_init(&blank, 0,NUM);
	sem_init(&product, 0, 0);
	pthread_t pid[8];
	for(int i = 0;i < 4;++i)
	{
		pthread_create(&pid[i],NULL,producer,NULL);
	}

	for(int i = 0;i < 4;++i)
	{
		pthread_create(&pid[i + 4],NULL,consumer,NULL);
	}

	for(int i = 0;i < 8;++i)
	{
		pthread_join(pid[i],NULL);
	}

	
/*	pthread_t pid,cid;
	sem_init(&blank, 0,NUM);
	sem_init(&product, 0, 0);

	pthread_create(&pid,NULL,producer,NULL);
	pthread_create(&cid,NULL,consumer,NULL);
	pthread_join(pid,NULL);
	pthread_join(cid,NULL);

	sem_destroy(&blank);
	sem_destroy(&product);
*/
	return 0; 
}


