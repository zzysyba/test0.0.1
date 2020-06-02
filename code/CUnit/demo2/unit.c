#include <stdio.h>
#include "CUnit/TestRun.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"
#include "CUnit/Basic.h"

#define TRUE 1
#define FALSE 0

//初始化套件成功
int init_suite_success(void) { return 0; }
//初始化套件失败
int init_suite_failure(void) { return -1; }
//清除套件成功
int clean_suite_success(void) { return 0; }
//清除套件失败
int clean_suite_failure(void) { return -1; }

//测试通过
void test_success1(void)
{	CU_ASSERT(TRUE);}
void test_success2(void)
{	CU_ASSERT_NOT_EQUAL(2, -1);}
void test_success3(void)
{	CU_ASSERT_STRING_EQUAL("string #1", "string #1");}
void test_success4(void)
{	CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");}
//测试失败
void test_failure1(void)
{	CU_ASSERT(FALSE);}
void test_failure2(void)
{	CU_ASSERT_EQUAL(2, 3);
	CU_ASSERT(FALSE);}
void test_failure3(void)
{	CU_ASSERT(FALSE);
	CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");}
void test_failure4(void)
{	CU_ASSERT_STRING_EQUAL("string #1", "string #2");}

int main()
{
	CU_pSuite pSuite = NULL;

	/* 初始化注册表*/
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* 添加Suite_success套件 */
	pSuite = CU_add_suite("Suite_success", init_suite_success, clean_suite_success);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* 添加测试到Suite_success套件 */
	if ((NULL == CU_add_test(pSuite, "successful_test_1", test_success1)) ||
		(NULL == CU_add_test(pSuite, "successful_test_2", test_success2)) ||
		(NULL == CU_add_test(pSuite, "successful_test_3", test_success3)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* 添加Suite_init_failure套件，并添加一个初始化失败的初始化函数 */
	pSuite = CU_add_suite("Suite_init_failure", NULL, NULL);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* 添加测试到Suite_init_failure套件 */
	if ((NULL == CU_add_test(pSuite, "successful_test_1", test_success1)) ||
		(NULL == CU_add_test(pSuite, "successful_test_2", test_success2)) ||
		(NULL == CU_add_test(pSuite, "successful_test_3", test_success3)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* 添加Suite_clean_failure套件，添加一个清理套件失败的清理函数 */
	pSuite = CU_add_suite("Suite_clean_failure", NULL, NULL);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* 向套件中添加测试函数 */
	if ((NULL == CU_add_test(pSuite, "successful_test_4", test_success1)) ||
		(NULL == CU_add_test(pSuite, "failed_test_2", test_failure2)) ||
		(NULL == CU_add_test(pSuite, "successful_test_1", test_success1)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* 添加Suite_mixed套件 */
	pSuite = CU_add_suite("Suite_mixed", NULL, NULL);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* 添加测试函数到Suite_mixed套件 */
	if ((NULL == CU_add_test(pSuite, "successful_test_2", test_success2)) ||
		(NULL == CU_add_test(pSuite, "failed_test_4", test_failure4)) ||
		(NULL == CU_add_test(pSuite, "failed_test_2", test_failure2)) ||
		(NULL == CU_add_test(pSuite, "successful_test_4", test_success4)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* 用basic接口运行所有测试函数 */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list());
	printf("\n\n");

	/* 用automated接口运行所有测试函数 */
	//CU_automated_run_tests();
	//CU_list_tests_to_file();

	/* 用console接口运行所有测试函数 */
	//CU_console_run_tests();

	/* 用curses接口运行所有测试函数 */
	/* （在具有curses库的linux系统中可以使用） */
//	CU_curses_run_tests();

	/* 清理注册表并返回错误 */
	CU_cleanup_registry();
	return CU_get_error();
}

