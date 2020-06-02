#include "zhaizy.h"


typedef struct SeqList
//线性表的结构
{
	DataType *data;
	int MaxLen;
	int len;
}SeqList;

/***************************************************************
            			数据结构-严魏敏--2020/4/20
						以及网上课后习题-----顺序表
****************************************************************/

//构造一个空的线性表
void IniList_seq(SeqList *La)
{
	La->data = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(! La->data)	
		exit(OVERKLOW);
	La->len = 0;
	La->MaxLen = LIST_INIT_SIZE;

}//InitList_sq

void PrintList(SeqList *L)
//打印顺序线性表
{
	printf("\n");
	printf("******************************************************\n");
	for (int i = 0; i < L->MaxLen; i++)
	{
		printf("L.data[%2d]is %2d.\n",i,L->data[i]);
	}
	printf("******************************************************\n");
	printf("L.len is %2d. L.maxlen is %2d.\n",L->len,L->MaxLen);
}


/*******************1.*******************************************
设顺序表L 中的数据元素递增有序。试写一算法，
将数据元素 x 插入到顺序表 L 的适当位置，
以保持该表的有序性。
****************************************************************/

void insertLx(SeqList *L, DataType x)
{
	if(L->len == L->MaxLen)
	{
		SeqList* newbase = (ElemType *)realloc(L->data,(LISTINCREMENT  + L->MaxLen)* sizeof(ElemType));
		if(!newbase) exit(OVERKLOW);
		L->data = newbase;
		L->MaxLen +=  LISTINCREMENT;
	}
	int i = L->len-1;

	while(i >= 0 && x<L->data[i])
	{
		L->data[i+1] = L->data[i];
		i = i - 1 ;
	}
	L->data[i + 1] = x;
	L->len++;
}


/*******************2.*******************************************
在顺序线性表L中第一i位置之前插入新的元素e
****************************************************************/

Status ListInsert_Sq(SeqList *L, int i , int e)
{	

	if (i < 1 || i > L->len + 1 )
	{	

		return ERROR;
	}

	if (L->len >= L->MaxLen )
	{

		SeqList* newbase = (ElemType *)realloc(L->data,(LISTINCREMENT  + L->MaxLen)* sizeof(ElemType));
		if(!newbase) exit(OVERKLOW);
		L->data = newbase;
		L->MaxLen +=  LISTINCREMENT;
	}
	for (int k = 0; k < L->len - i ; ++k)
	{	
		L->data[L->len - k] = L->data[L->len - (k + 1)];
	}

	L->data[i] = e;
	L->len +=1;
	return OK;

}

/*******************2.*******************************************
删除L中第i个元素
****************************************************************/
Status DeleteList_Seq(SeqList* L ,int i )
{
	if (i < 0 || i > L->len)
	{
		printf("i有误\n");
		return ERROR;
	}
	
	int e = L->data[i-1];

	for (int k = i; k < L->len; ++k)
	{	
		L->data[k - 1] = L->data [k];
	}
	L->data[L->len - 1] = NULL;
	L->len -= 1;
	return e;
}

/*******************3.*******************************************
合并两个非递减线性表
****************************************************************/
void MergeList_Seq(SeqList* L, SeqList* L2 , SeqList* L3)
{	

	for (int i = 0; i < L->len; ++i)
	{	
		if (L3->len >= L3->MaxLen)
		{
			SeqList* newbase = (ElemType *)realloc(L3->data,(LISTINCREMENT  + L3->MaxLen)* sizeof(ElemType));
			if(!newbase) exit(OVERKLOW);
			L3->data= newbase;
			L3->MaxLen +=  LISTINCREMENT;
		}
		L3->data[i] = L->data[i];
		L3->len +=1;
	}

	for (int i = 0; i < L2->len; ++i)
	{
		for (int j = 0; j < L3->len; ++j)
		{	
			//如果L2的data处于，L3data的两个值之间
			if (L2->data[i] >= L3->data[j] && L2->data[i] < L3->data[j+1])
			{	
				//将L2的data插入L3的表中，
				
				int e = L2->data[i];
		
				for (int k = 0; k < L3->len - j ; ++k)
				{	

					L3->data[L3->len - k] = L3->data[L3->len - (k + 1)];
				}

				L3->data[j] = e;
				L3->len +=1;
				printf("done :L2->data[%2d]:%2d to L3->data[%2d]\n",i, L2->data[i], j);
				break;
			}

			//L2的值比所有L3的值都大
			else if (L3->data[ j + 1] == 0 && L3->data[ j + 2] == 0)
			{	
				//将L2的data插入L3的表尾，
				int e = L2->data[i];
				L3->data[j + 1] = e;
				L3->len +=1;
				printf("done :L2->data[%2d]:%2d to L3->data[%2d]\n",i, L2->data[i], j+1);
				break;
			}
		}
	}

}


//***************************************************************
int main(void)
{
	SeqList L;
	SeqList L2;
	SeqList L3;
	IniList_seq(&L);
	IniList_seq(&L2);
	IniList_seq(&L3);
	int n = 3; 

	for (int i = 2; i < 15; i+=2)
	{
		insertLx(&L2, i);
	}
	PrintList(&L2);

	for (int i = 0; i < 12; ++i)
	{
		insertLx(&L, i);
	}
	PrintList(&L);

	ListInsert_Sq(&L , 2 , 10);
	PrintList(&L);

	printf("删除了第%2d个元素:%2d\n",n,DeleteList_Seq(&L , n));
	PrintList(&L);
	PrintList(&L2);

    MergeList_Seq(&L , &L2 ,&L3);
    PrintList(&L3);



	return 0;

}
























