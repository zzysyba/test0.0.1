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
 
int main(int argc, char* argv[])
{
	int ret = 22;
	fprintf(stderr,"stderr printf:%s\n",strerror(ret));
	fprintf(stdout,"stdout printf:%s\n",strerror(ret));
 
	

	return 0; 
}
 

