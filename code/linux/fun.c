
/***************************************************************
            			回调函数学习--2020/5/7
            			getstep接送函数指针p付值给step，
            			在run()中运行的step()实质上在main中
            			mystep_cb(i) == step(ct)
****************************************************************/
		
int (*step)(int) = NULL;

void run(void)
{
	int ct = 0;
	while(1)
	{
		if (step != NULL )
		{
			int rc = step(ct);
			printf("rc = %d\n", rc );
		}
		ct++;
		sleep(1);
	}
}

void getstep(int(*p)(int))
{
	step = p;
}
