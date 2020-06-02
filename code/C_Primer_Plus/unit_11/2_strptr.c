# include <stdio.h>
int main(void)
{
	char *cha = "are";
	printf( "%s ,%p ,%c ,%p ,%c\n" , "we" , cha, *(cha+1), cha + 1, *"farmily" );
	return 0;
}