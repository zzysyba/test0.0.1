#include "zhaizy.h"

/*=========================================
        mkff.c
 2020年05月13日 星期三 11时45分07秒
=========================================*/

int main(int argc,char* argv [])
{

	int ret = mkfifo("myfifo", 0777);
	if(ret == -1 )
	{
		perror("makefifo error");
		exit(1);
	}
	return 0;
}
 
