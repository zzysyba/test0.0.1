#include "zhaizy.h"

/***************************************************************
            			回调函数学习--2020/5/7
            	把mystep-cb(i)使用getstep()传给fun的回调函数
****************************************************************/


int mystep_cb(int i)
{
	printf("now is %d\n",i);
	return 100;
}


int main(void)
{
	getstep(mystep_cb);
	run();
}





