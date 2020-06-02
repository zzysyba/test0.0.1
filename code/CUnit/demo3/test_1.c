/*
5个数中取最大值的函数int max(int a[5]）
*/
#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/CUnit.h"
#include "CUnit/Console.h"
int max(int a[])
{
	int m=0,i=0;
	for(i=0;i<5;i++)
	{
      if(m<a[i])
      	{m=a[i];}
	  
	}
return m;
}
int init_suite1(void)
{
    return 0;   
}
int clean_suite1(void)
{  
      return 0;
}
void test_max(void)
{

   int a1[5]={6,5,4,8,3},a2[5]={4,848,616,84,6},a3[5]={45,41,12,68,31},a4[5]={16,12,3,5,2};
   CU_ASSERT(0 ==max(a1));
   CU_ASSERT(2 ==max(a2));
   CU_ASSERT(7 == max(a3));
   CU_ASSERT(16==max(a4));
}

int main()
{
   CU_pSuite pSuite = NULL;

   /* 初始化注册表*/
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* 添加套件 */
   pSuite = CU_add_suite("Suite_111", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* 添加测试用例 */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test of max()", test_max)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* 基本模式 */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   
CU_automated_run_tests();
	CU_list_tests_to_file();  
   CU_cleanup_registry();
   return CU_get_error();
}  
