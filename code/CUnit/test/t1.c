#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/CUnit.h"
#include "CUnit/Console.h"




int main(void)
{
	
	printf("git hub best!\n");
	printf("%d\n",CU_initialize_registry() );
	CU_cleanup_registry();
	return 0;
}
