/*##############################
Author:zzy                  
Create_Time:2020-05-19
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
	char buf[BUFSIZ];
	int	ret = read(STDIN_FILENO,buf,BUFSIZ);
	printf("****************");
	write(STDOUT_FILENO,buf,ret);
	return 0; 
}
 

