#include <stdio.h>
#define MSG "i`m special"

int main(void)
{
	char ar[] = MSG;
	const char *pt = MSG;
	printf("address of i`m special:%p \n", "i`m special");
	printf("address of i`m special:%p \n", ar);
	printf("address of i`m special:%p \n", pt);
	printf("address of i`m special:%p \n", MSG);
	printf("address of i`m special:%p \n", "i`m special");

	return 0;
}