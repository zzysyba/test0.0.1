#include "zhaizy.h"

void perr(const char* str)
{
	perror(str);
	exit(1);
}


void print_set(sigset_t* set)
{
	int i;
	for (i = 1;i < 32; ++i)
	{
		if(sigismember(set, i))
		{
			putchar('1');
		}
		else
			putchar('0'); 
	}
	printf("\n");
}


int main(int argc, char* argv[])
{
	sigset_t set,oldset;
	sigset_t pedset;
	int ret = 0;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGBUS );

	ret = sigprocmask(SIG_BLOCK, &set, &oldset);
	if(ret == -1)
	{
		perr("sigprocmask error");
	}
	while(1)
	{
		ret = sigpending(&pedset);
		if(ret == -1)
		{
			perr("sigpending error");
		}
		sleep(1);
		print_set(&pedset);
	}


	return 0;
}

