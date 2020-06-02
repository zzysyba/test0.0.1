/*##############################
Author:zzy                  
Create_Time:2020-05-18
Versios:1.0
##############################*/
#include "zhaizy.h" 

struct msg{
	struct msg* next;
	int num;
};

int gold = 0;
struct msg *head;

void seelist(struct msg* head)
{
	if(head == NULL)
	{
		printf("\n");
		return;
	}
	else
	{
		printf("%d->",head->num);
		seelist(head->next);
	}

}


pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_cond_t has_consume = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void perr(char* str) 
{
	perror(str);
	exit(1);
}

void *consumer(void* p)
{
	struct msg *mp;

	while(1)
	{


		pthread_mutex_lock(&lock);
		while(head == NULL){
			pthread_cond_wait(&has_product,&lock);
		}
		mp = head;
		head = mp->next;
		gold--;
		printf("Consumer:%d----%3d,gold = %d\n",pthread_self(),mp->num,gold);
		seelist(head);
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&has_consume);
		free(mp);
		usleep(50000*(rand()%5));
		//	sleep(rand()%3);
	}

	return;
}

void *producer(void* p)
{
	struct msg *mp;
	while(1)
	{
		
		mp = malloc(sizeof(struct msg));
		mp->num = rand() % 1000 + 1;
		pthread_mutex_lock(&lock);
		while(gold >= 20){
			pthread_cond_wait(&has_consume,&lock);
		}
		mp->next = head;
		head = mp;
		printf("--------Pro %3d,gold = %d\n",mp->num,gold);
		seelist(head);
		gold++;
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&has_product);
		usleep(50000*(rand()%5));

		//		sleep(rand()%3);


	}
	return;
}


int main(int argc, char* argv[])
{
	pthread_t pid[8];
	srand(time(NULL));

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


	return 0; 
}


