#include <stdio.h>
#include <string.h>

#include "CUnit/Basic.h"



static FILE* temp_file = NULL;

/*初始化一个套件，如果成功，则返回0，失败则返回-1*/
int init_suite1(void)
{
   if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}
/*清理套件函数，关闭用于测试的临时文件，成功则返回0，失败返回-1*/
int clean_suite1(void)
{
   if (0 != fclose(temp_file)) {
      return -1;
   }
   else {
      temp_file = NULL;
      return 0;
   }
}
/*fprint的测试函数*/
void test_fprintf(void)
{
   int i1 = 10;

   if (NULL != temp_file) {
      CU_ASSERT(0 == fprintf(temp_file, ""));
      CU_ASSERT(2 == fprintf(temp_file, "Q\n"));
      CU_ASSERT(7 == fprintf(temp_file, "i1 = %d", i1));
   }
}
/*简单示例中只测试了返回值，在我们进行测试模块测试的时候，可能还需要跟踪数据结构在中间过程的变化，不能只测试一个返回值*/
/*fread的测试函数*/
void test_fread(void)
{
   unsigned char buffer[20];

   if (NULL != temp_file) {
      rewind(temp_file);
      CU_ASSERT(9 == fread(buffer, sizeof(unsigned char), 20, temp_file));
      CU_ASSERT(0 == strncmp(buffer, "Q\ni1 = 10", 9));
   }
}



int main (int argc, char* argv[])
{
CU_pSuite pSuite = NULL;

   /* 初始化CUnit注册表 */
   if (CU_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* 在注册表中添加套件 */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* 在套件中添加测试用例 */
   /* */
   if ((NULL == CU_add_test(pSuite, "test of fprintf()", test_fprintf)) ||
       (NULL == CU_add_test(pSuite, "test of fread()", test_fread)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* 在BASIC模式下执行所有测试用例 */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();  // CU_console_run_tests();CU_console_run_tests();CU_automated_run_tests(); 还可以选这些
   
   CU_cleanup_registry();
   return CU_get_error();



}

