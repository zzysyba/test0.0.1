#include <stdio.h>
#define STLEN 10
int main(void)
{

	char words[STLEN];
	puts("Entter:");

	while(fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
		fputs(words, stdout);
	puts("OK");

	return 0 ;
}