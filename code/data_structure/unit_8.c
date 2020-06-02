#include "zhaizy.h"


typedef struct HashTable
//哈希表的结构
{
	struct HashTable *next;
	int key;

}HashTable, *Hashtable;
int m=0;

/***************************************************************
            			数据结构-严魏敏--2020/5/6
						以及网上课后习题-----哈希表
****************************************************************/
void RanGroup(int * num ,int n)
//给长度为n的数组全部生成随机数
{
	for (int i = 0; i < n ; ++i)
	{	
		*(num + i) = rand() % 100;
	}
}

//***************************************************************

int hash(int key)
//对九取余
{
	return key%9;
}

HashTable* InitHashBlock(int val)
//给val初始化一个哈希块，返链回它的地址。
{
	HashTable* root = (HashTable*)malloc(sizeof(*root) );
    root->key  = val;
    root->next  = NULL;

 
    return root;
}

void InitHashTable(HashTable** hashtab , int *num,int n)
{
	for (int i = 0; i < n; ++i)
	{
		int temp = hash(*(num + i));
		printf("%d ,",temp);
		HashTable* Troot = InitHashBlock(*(num + i));

		if (*(hashtab + temp) == NULL)
		//这个哈希值对应的表中位置没有值，直接插
		{	

			*(hashtab + temp) = Troot;
		}
		else
		//有值，循环访问链接的地址，直到下一个值为null;
		{	
			HashTable* aac = *(hashtab + temp);
			while(aac != NULL)
			{	

				if(aac->next == NULL)
				{
					aac->next = Troot;
					break;
				}
				aac = aac->next;
			}
		}

	}

	printf("\n****************************************\n");
}

void PrintHash(HashTable* block)
//递归展示哈希块
{

	printf("%2d -> ", block->key);

	if (block->next == NULL)
	{
		return;
	}
	PrintHash(block->next);
	
}

void Hashfind(HashTable** hashtab,int val)
//查
{	
	int num = hash(val);
	printf("%d 的哈希值为%d,",val,num);
	HashTable* aac = *(hashtab + num);
	while(1)
	{
		if (aac->key == val)
		{
			break;
		}
		aac = aac->next;
	}

	printf("地址为%p\n",aac);
}

void Hashint(HashTable** hashtab,int val)
//增
{
	int temp = hash(val);

	HashTable* Troot = InitHashBlock(val);

	if (*(hashtab + temp) == NULL)
	//这个哈希值对应的表中位置没有值，直接插
	{	

		*(hashtab + temp) = Troot;
	}
	else
	//有值，循环访问链接的地址，直到下一个值为null;
	{	
		HashTable* aac = *(hashtab + temp);
		while(aac != NULL)
		{	

			if(aac->next == NULL)
			{
				aac->next = Troot;
				break;
			}
			aac = aac->next;
		}
	}

}




//***************************************************************
int main(void)
{	
	int n = 30;
	srand((unsigned)time(NULL));
	HashTable* hash[9] = {NULL};
	int num[n];
	RanGroup(num,n);

	for (int i = 0; i < n; ++i)
	{
		printf("%2d,",num[i] );
	}
	printf("\n");

	InitHashTable(hash , num, n);


	for (int i = 0; i < 9; ++i)
	{	
		printf("%d: ", i);
		if (hash[i] != NULL)
		{
			PrintHash(hash[i]);
			printf("\n");
		}
		else printf("NULL\n");
	}
	printf("****************************************\n");
	printf("num[18]:");
	Hashfind( hash,num[18]);

	printf("****************************************\n");
	Hashint(hash , 14);
	for (int i = 0; i < 9; ++i)
	{	
		printf("%d: ", i);
		if (hash[i] != NULL)
		{
			PrintHash(hash[i]);
			printf("\n");
		}
		else printf("NULL\n");
	}
	printf("****************************************\n");
	return 0;
}









