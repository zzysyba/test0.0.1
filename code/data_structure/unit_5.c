#include "zhaizy.h"


/***************************************************************
            			数据结构-严魏敏--2020/4/24
						以及网上课后习题-----排序算法
****************************************************************/
 
void RanGroup(int * num ,int n)
//给长度为n的数组全部生成随机数
{
	for (int i = 0; i < n ; ++i)
	{
		*(num + i) = rand() % 100;
	}
}

void ShowGroup(int *num , int n)
//打印数组
{
	for (int i = 0; i < n; ++i)
	{
		printf("%2d   ",num[i] );
	}
	printf("\n");
}
   
void LST(int e , int *num , int n )
//将e插入长度为n的数组中
{
	for (int i = 0; i < n; ++i)
	{	
		//e比数组的最后一个小，差到队尾
		if (e < num[ n - 1 ])
		{	
			num[ n ] = e;
			break;
		}
		//e比数组的第一个大，差到队头
		else if (  e >= num [0] )
		{	
			for (int j = 0; j <= n ; ++j)
			{
				num[n - j ] = num[n - j - 1];
			}
			num[0] = e;
			break;
		}
		//e找到自己合适的位置，插入
		else if ( e < num[i] && e > num[ i + 1] )
		{	

			for (int j = 0; j <= n - i - 1 ; ++j)
			{
				num[n - j ] = num[n - j - 1];
			}
			num[i + 1] = e;
			break;
		}
	}
}

//***************************************************************

void SortBub(int* num , int n )
//冒泡排序
{
	for (int i = 0; i < n; ++i)
	{	

		for (int j = (i + 1); j < n ; ++j)
		{

			if (num[j] > num[i] )
			{	
				ShowGroup(num, 10);
				int temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}
		}
	}
}

//***************************************************************
void SortIns(int* num, int n)
//插入排序
{
	for (int i = 1; i < n; ++i)
	{	

		 printf("***************\n");
		 printf("%d\n",num[i]);
		 ShowGroup(num, i);	
		 printf("***************\n");


		LST(num[i] ,num , i );


	}
}

//***************************************************************
int partition_Rowe(int arr[], int low, int high)
//根据一个基准数，将数组分为基准数左边小于基准数，基准数右边大于或等于基准数的两部分
//返回值是基准数在数组中的下标
//这里选取数组元素的第0位作为基准数
//low为最低下标，high为最高下标
{
	int pivot = arr[low];//选取基准数
	int low_index = low;
	for (int i = low + 1; i <= high; i++)
	{
		if (arr[i] < pivot)
		{
		//在序列中找到一个比pivot小的，就递增low_index
			low_index++;
			if (i!=low_index)//如果i和low_index相等，则在i之前都不存在需要交换的比pivot大的数
			{
				swap(arr, i, low_index);
			}
		}
	}
	//low_index的位置就是pivot应处在的位置，low_index指向的总是比pivot小的数
	arr[low] = arr[low_index];
	arr[low_index] = pivot;
	ShowGroup(arr, 10);	
	return low_index;
}


void quick_sort(int arr[], int low, int high)
//快速排序
{
	if (high > low)//如果需要排序的序列的元素个数大于1
	{
		int pivot_pos = partition_Rowe(arr, low, high);
		quick_sort(arr, low, pivot_pos - 1);//左序列
		quick_sort(arr, pivot_pos + 1, high);//右序列
	}
}



void swap(int arr[], int index_i, int index_j)
{//将数组相应位置的两个数相交换
	int k = arr[index_i];
	arr[index_i] = arr[index_j];
	arr[index_j] = k;
}
//***************************************************************

void ChoiSort(int* num, int n )
//选择排序
{	
	// int hider = 0;
	// for (int i = 1; i < n; ++i)
	// {
	// 	if (num[0] < num[i])
	// 	{
	// 		hider++;
	// 	}
	// }
	// printf("有%d个数大于%d\n",hider,num[0] );
	// int temp = num[0];
	// num[0] = num[hider];
	// num[hider] = num[0];


	for (int j = 0; j < n; ++j)
	{
		int hider = 0;
		int* dack = num;
		for (int i = 1; i < n; ++i)
		{	

			if (*dack <= num[i])
			{
				hider++;
			}
		}
		if (hider == 0)
		{
			dack++;
			continue;
		}

		int temp = *dack;
		*dack = num[hider];
		num[hider] = temp;
		ShowGroup(num, 10);
	}

}




//***************************************************************
int main(void)
{	
	srand((unsigned)time(NULL));
	int number[11];


	RanGroup(number, 10);
	ShowGroup(number, 10);

	//冒泡排序
	//SortBub(number, 10);


	//插入排序
	//SortIns(number, 10);

	//快速排序
	//quick_sort((number , 0 , 9);
	
	//选择排序
	ChoiSort(number , 10);

	ShowGroup(number, 10);
}





