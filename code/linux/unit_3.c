#include "zhaizy.h"
/***************************************************************
            			linux系统编程学习--2020/5/9
            			动态库与静态库
****************************************************************/

int add(int , int);
int sub(int , int);

int main(void)
{
   int a = 5;
   int b = 6;
   printf("a + b = %d\n",add(a, b));
   printf("a - b = %d\n",sub(a, b));
}

//静态库制作方法
//gcc -c mymath.c
//ar rcs libmymath.o mymath.o
//gcc unit_3.c mymath.a



//动态库制作方法
//gcc -c mymath.c -fPIC
//gcc -shared libmymath.so mymath.o
//gcc unit_3.c -lmymaht -L./
//export LD_LIBRARY_RATH = ./
//a.out








