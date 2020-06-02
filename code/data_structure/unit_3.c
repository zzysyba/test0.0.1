#include "zhaizy.h"

typedef struct Lnode
//带头指针的单向链表的结构
{
	ElemType data;
	struct Lnode *next;
}Lnode, *LinkList;

/***************************************************************
            			数据结构-严魏敏--2020/4/22
						以及网上课后习题-----单向链表
****************************************************************/
void Init_LinkList(Lnode* head)
//初始化链表
{

    head->next = NULL; 
	printf("& of head is:%p.\n", &head);
}



void Insert_LinkList(Lnode* head, int e, int index)
//插入链表节点 e是插入的值，index是插入的位置
{
    //前驱结点。
    int i;
    Lnode* prev, *node;
 
    prev = head; 
    for (i = 1; i < index; i++)
        prev = prev->next;
 
    node = (Lnode*)malloc(sizeof(Lnode));
    node->data = e;
    //为插入的结点分配内存并赋值

    //插入
    node->next = prev->next;
    prev->next = node;
}



int Delet_LinkList(Lnode* head, int index)
//删除链表节点
{
    int i;
    Lnode* prev, *node;
 
    prev = head; //前驱结点
    for (i = 1; i < index; i++)
        prev = prev->next;
   
    //删除步骤
    node = prev->next;
    int e = node->data;
    prev->next = node->next;
    printf("删除了链表中第%d个值.\n",index );
    free(node);
 
    return e;
}



int IdSearch_List(Lnode * head, int index)
//按照序号查找数值
{
	Lnode *perv;
	perv = head->next;
	for(int i = 1; i < index;i++)
	{
		if (perv->next == NULL)
		{
			printf("错误，链表没有这么长.\n");
			return 0;
		}
		perv = perv->next;
	}
	printf("链表中第%d个值是%d.\n",index ,perv->data );
	return perv->data;
}


int ValueSearch_List(Lnode * head, int e)
//5.按值查找表结点
{
	int i = 1;
	Lnode *prev;
	prev = head->next;
	while(prev != NULL && prev->data !=e)
	{
		prev = prev->next;
		i++;
	}
	if(prev == NULL)
	{
		printf("错误，链表中不存在这个值.\n");
		return 0;
	}
	else if (prev->data == e)
	{
		printf("%d是链表中第%d个值.\n",e ,i );
		return i;
	}
}


void print_list(Lnode* head)
//打印链表
{
	printf("------打印链表：---------->");
    for (head = head->next; head != NULL; head = head->next)
    {   
        printf("%d -> ", head->data);
 	}
    printf("\n");
}


/*******************2.*******************************************
试写一个算法，
在带头结点的单链表L的元素x前插入一个结点y。
*****************************************************************/
void insert_y_before_x(Lnode* head, ElemType x, ElemType y)
{
	Lnode *prev , *prevy;
	prev = head->next;

	while(prev->next && prev->next->data != x)
	{
		prev = prev->next;
	}	

	if(!prev->next)
	{
		printf("错误，不存在这个值%d\n", x);
		return;
	} 
	else if (prev->next->data == x)
	{
		prevy = (Lnode*)malloc(sizeof(Lnode));
		prevy->data = y;
		prevy->next = prev->next;
		prev->next = prevy;
	}
	printf("插入成功.\n");
}

/*******************3.*******************************************
试写一个算法，
统计带头指针的单链表 L 的元素个数。
*****************************************************************/
int NumberOf(Lnode *head)
{
	Lnode *prev;
	prev = head->next;
	int i;
	for ( i = 1;prev->next;i++)
	{
		prev = prev->next;
	}
	printf("链表有%d元素。\n",i );
	return i;

}


/*******************4.*******************************************
试写一个算法，
在带头结点的单链表 L 的第 k 个结点后插入一个结点 x。
*****************************************************************/
 void insert_x_after_k(Lnode *head,int x,int k)
 {
 	Lnode* prev, *prevx;
 	prev = head->next;
 	int i;
 	for (i = 1; (prev->next && (i < k)); i++)
 	{
 		prev = prev->next;
 	}
 	if (prev->next == NULL)
 	{
 		printf("错误，链表没有这么长\n");
 		return;
 	}
 	printf("%d\n", i);
 	prevx = (Lnode*)malloc(sizeof(Lnode));
 	prevx->data = x;
 	prevx->next = prev->next;
 	prev->next = prevx;
 	printf("插入成功\n");
 }

/*******************5.*******************************************
试写一个算法，
在带头结点的单链表Ｌ中删除所有的数据元素为 x 的结点。
*****************************************************************/
void RemoveX(Lnode *head, int x)
{
	Lnode* prev, *node;
	prev = head;
	while(prev)
	{	
		if (prev->next && prev->next->data == x)
		{
			node = prev->next;
    		prev->next = node->next;
    		printf("删除了一个%d\n", node->data);
    		free(node);

		}
		
		else prev = prev->next;
	}
}

/*******************6.*******************************************
假设一个单循环链表Ｌ的数据域为整型，
设计一个算法， 求该表中所有结点的数据之和。
*****************************************************************/
int SumList(Lnode *head)
{
	if (head->next == NULL)
	{
		return 0;
	}
	Lnode* prev = head->next;
	int sum = 0;
	while(1)
	{	
		printf("加上了%d\n", prev->data);
		if (prev->next == NULL)
		{
			sum += prev->data;
			return sum;
		}
		sum += prev->data;
		prev = prev->next; 

	}

}



//****************************************************************
int main(void)
{	
	Lnode List_head;
    Init_LinkList(&List_head);
	Insert_LinkList(&List_head,120,1);
	Insert_LinkList(&List_head,3,2);
	Insert_LinkList(&List_head,20,2);
	Insert_LinkList(&List_head,156,2);
	Insert_LinkList(&List_head,20,1);
	Insert_LinkList(&List_head,200,3);
	print_list(&List_head);
	
	ValueSearch_List(&List_head,50);
	IdSearch_List(&List_head,4);

	print_list(&List_head);	
	Delet_LinkList(&List_head,2);
	print_list(&List_head);	

	insert_y_before_x(&List_head,50,40);
	print_list(&List_head);	
	NumberOf(&List_head);

	insert_x_after_k(&List_head,10,2);
	print_list(&List_head);	
	
	RemoveX(&List_head, 20);
    print_list(&List_head);	

    int ans = SumList(&List_head);
    printf("sum = %d\n",ans);	 
    print_list(&List_head);	 
	return 0;
}
