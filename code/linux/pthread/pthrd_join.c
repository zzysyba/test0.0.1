/*##############################
Author:zzy                  
Create_Time:2020-05-16
Versios:1.0
##############################*/
#include "zhaizy.h" 
struct thrd{
	int var;
	char str[256];
};



void perr(char* str) 
{
		perror(str);
		exit(1);
}
 
void* ptha(void* arg)
{	
	struct thrd *th1;
	th1 = malloc(sizeof(th1));
	th1->var = 100;
	strcpy(th1->str,"hello word");

	return (void *)th1;

}


int main(int argc, char* argv[])
{
	int ret;
	struct thrd *th2;
	pthread_t thread;
	ret = pthread_create(&thread, NULL, ptha ,NULL);
	
	pthread_join(thread, (void**)&th2);
	printf("val:%d,str:%s\n",th2->var,th2->str);

	return 0; 
}
 

