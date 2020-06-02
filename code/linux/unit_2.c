#include "zhaizy.h"
/***************************************************************
  C语言学习--2020/5/8
  指针的高级传递
 ****************************************************************/
void fun(long val)
{	

	int* a = (int*)val;
	printf("%d\n",*a ); 
}


int* fun2()
{
	static int mun[5] = {0};
	if (mun[0] == 1)
		printf("yes 1\n");
	return mun;
}


int main(int argc , char** argv)
{

/*
//字符串常量，用指针不能改，用数组可以改
	char *p = "hello \0hehjej";

	for (int i = 0; i < 15; ++i)
	{
	printf("%c",p[i]);
	}
	printf("%s\n",p );
	printf("%c\n",p[1]);
*/






/* 
//越界访问内存
	int a = 0x123456;
	int b = 0x123450;
	int* p1 = &b;
	char* p2 = (char *) &b;
	printf("p1:%x,%x,%x\n",*(p1+1),p1[1],*p1 + 1);
	printf("p2:%x\n",*p2 );

*/




/*
//用内存越界修改const的值
	const int a = 10;
	printf("%d\n",a );
	int b = 5;
	int* p3 = &b;
	 *(p3+1) = 100;
	 printf("%d\n",a );
*/





//多级数组 argv[i]是第i个参数的首地址
/*
	   for (int i = 0; i <100; ++i)
	   {
	   if (argv[i] == NULL)
	   {
	   break;
	   }	
	   printf("argc is %s\n", argv[i]);

	   }
*/

/*	
//设置一个指向a[5][6]的指针
	int a[][6] = {0,1,2,3,4,5,6};
	for (int i = 0; i < 10; ++i)
	{
	printf("%d\n",*(*a + i));
	}
	int (*p)[6] = a;
	printf("**************\n");
	printf("%d\n",**(p + 1) );
*/



/*
//函数名字是标签
	int (*myshow)(const char *, ...);
	printf("hahha %p\n",printf);
	myshow = printf;
	myshow("yayayay\n");
*/



/*
//传值在强转
		int a = 5;
		int* b = &a;
		printf("%d\n",sizeof(long) );
		printf("%d\n",sizeof(int*) );
		long c = (long)b;
		printf("%p\n",b );
		printf("%p\n",c );
		fun(c);
*/	



/*
	//sprintf特殊用法
	int a = 12;
	char buf[10];
	sprintf(buf,"%d",a);
	printf("%s\n",buf );
	*/

	/*
	//stati传递局部变量
	int* aaa = fun2();
	 *aaa = 1;
	fun2();
*/


/*
//位计算
	unsigned int a = 1;
	a = a<<20;
	printf("%d\n",a ); 
*/




//函数指针的格和大小
	void   (*a)(int,int);
	int    (*b)(int,int);
	char   (*c)(int,int);
	long   (*d)(int,int);
	double (*e)(int,int);

	void * f(int a,int b)
	{
		int i = 1;
	}
	printf("void   %ld\n",sizeof(a) );
	printf("int    %ld\n",sizeof(b) );
	printf("char   %ld\n",sizeof(c) );
	printf("long   %ld\n",sizeof(d) );
	printf("double %ld\n",sizeof(e) );
	printf("double %ld %p\n",sizeof(f), f );
	printf("***********************\n");
	printf("void   %ld\n",sizeof(*a) );
	printf("int    %ld\n",sizeof(*b) );
	printf("char   %ld\n",sizeof(*c) );
	printf("long   %ld\n",sizeof(*d) );
	printf("double %ld\n",sizeof(*e) );
	printf("double %ld\n",sizeof(*f) );

	return 0;

}
