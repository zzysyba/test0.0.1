#include "zhaizy.h"



/***************************************************************
            			数据结构-严魏敏--2020/4/25
						以及网上课后习题-----堆排序
****************************************************************/

void swap(int arr[], int i,int j)
//交换
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void build_heap(int tree[], int n)
//将数组tree变成一个堆
{
	int last_node = n - 1;
	int parent = (last_node - 1)/2;
	for(int i = parent ;i >= 0 ;i-- )
	{
		heapfiy(tree ,n , i);
	}
}

void heapfiy(int tree[],int n ,int i)
//三个数变成堆
{	
	if (i >= n)
	{
		return;
	}
	int c1 = 2 * i + 1;
	int c2 = 2 * i + 2;
	int max = i;
	if ( c1 < n && tree[c1] > tree[max] )
	{
		max = c1;
	}
	if ( c2 < n && tree[c2] > tree[max] )
	{
		max = c2;
	}
	if (max != i) 
	{
		swap(tree ,max ,i);
		heapfiy(tree ,n ,max );
	}
}

void heap_sort(int tree[], int n)
//堆排，取最大堆的对顶到最后
{
	build_heap(tree ,n );
	for (int i = n - 1; i >= 0; i --)
	{
		swap(tree ,0 ,i );
		heapfiy(tree ,i , 0);
	}
}

int main(void)
{
		int tree[] = {7, 4 ,10 ,3 ,15 ,1 ,22 ,6 ,19 };
		int n = 9;
		heap_sort(tree , n);

		for (int i = 0; i < n; ++i)
		{
			printf("%d,", tree[i]);
		}
		printf("\n");
		return 0;

}








