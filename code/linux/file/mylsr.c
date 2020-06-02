#include "zhaizy.h"

void isFile(char *name);
void read_dir(char *dir)
{
	char path[256];	
	DIR *dp;
	struct dirent* sdp;

	dp = opendir(dir);
	if (dp == NULL)
	{
		perror("opendir error");
		return;
	}

	while((sdp = readdir(dp)) != NULL)
	{
		sprintf(path,"%s/%s", dir , sdp->d_name);
		isFile(path);
	
	
	}
	
	closedir(dp);
	
	return;
}


void isFile(char *name)
{
	int ret = 0;
	struct stat sb;
	ret = stat(name, &sb);
	if (ret == -1)
	{
		perror("stat error");
		return ;
	}	

	if (S_ISDIR(sb.st_mode))
	{
	
	}
	printf("%s\t %ld\n",name,sb.st_size);
}


int main(int argc , char* argv[])
{
	if(argc == 1)
	{
		isFile(".");

	} 
	else 
	{
		isFile(argv[1]);
	}
}

