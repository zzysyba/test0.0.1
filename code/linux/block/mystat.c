#include "zhaizy.h"


int main (int argc,char* argv[])

{
	struct stat sb;

	int ret = stat(argv[1],&sb);
	if(ret == -1)
	{
		perror("stat error");
		exit(1);
	}

 	if(S_ISREG(sb.st_mode))
 	{
 		printf("it's a regular\n");
 	}
 	else if (S_ISDIR(sb.st_mode))
 	{
 		printf("it's a dir\n");
 	}
 	else if (S_ISFIFO(sb.st_mode))
 	{
 		printf("it's a pipe\n");
 	}
 	else if (S_ISLNK(sb.st_mode))
 	{
 		printf("it's a link\n");
 	}

	return 0;

}




