#include "zhaizy.h"




int main(int argc, char* argv[])
{
	DIR *dp;
	struct dirent *sdp;
	
	dp = opendir(argv[1]);
	
	if(dp == NULL)
	{
		perror("opendir error");
		exit(1);
	}

	printf("in\n");

	while((sdp = readdir( dp)) != NULL);
	{
		printf("f");
		printf("%s\t",sdp->d_name);
	}
	
	printf("\n");
	closedir(dp);
	
	
	return 0;
}
