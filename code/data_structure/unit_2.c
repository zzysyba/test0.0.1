#include "zhaizy.h"


//栈的数据结构
typedef struct{
	ElemType *base;
	ElemType *top;
	int      stacksize;
}Sqstack;


//队列的数据结构
typedef struct {
	int      *addr;
	ElemType *head;
	ElemType *tail;
	int     queuesize;
}Queue;


/***************************************************************
            			数据结构-严魏敏--2020/4/21
						---栈和队列
****************************************************************/

Status InitStack(Sqstack *S)
//初始化一个栈
{
	S->base = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!S->base)
		exit(OVERKLOW);
	S->top = S->base;
	S->stacksize = LIST_INIT_SIZE;

	return OK;
}

Status GetTop(Sqstack *S)
//若栈不空，则返回栈顶元素
{
	if(S->top == S->base)
		return ERROR;
	ElemType e = *(S->top - 1);
	return e;
}

Status Push(Sqstack *S , ElemType e)
//插入e为栈顶的新元素
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (ElemType* )realloc(S->base , ( S->stacksize + LISTINCREMENT) * sizeof(ElemType));
	}
	if (!S->base)
	{
		exit(OVERKLOW);
	}
	*S->top = e;
	S->top += 1;
	return OK;
}


Status Pop(Sqstack *S)
//返回栈顶元素
{
	if (S->top == S->base)
	{
		printf("栈中已经没有值了\n");
		return ERROR;
	}
	ElemType e = *(S->top - 1);
	*(S->top - 1)= 0;
	S->top -= 1;
	return e;
}


void ShowStack(Sqstack *S)
//打印栈
{
	printf("栈顶——>");
	for (int i = 0; ; ++i)
	{
		if ((S->top - i + 1) == S->base)
		{
			break;
		}
		printf("         |%3d|\n",*(S->top - i));
	}
	printf("栈底————————^—————\n");
}


ElemType LengthStack(Sqstack *S)
//返回栈的长度
{	int* temp = S->top;
	for (int i = 0; ; ++i)
	{
		if (temp == S->base)
		{
			return i;
		}
		temp -=1 ;
	}
}

ElemType SEmpty(Sqstack *S)
//若栈为空，则返回TRUE，反之为FALSE
{
	if (S->top == S->base)
	{
		return TRUE;
	}
	return FALSE;
}
//***************************************************************
//初始化一个队列
void InitQueue(Queue *Q)
{
	Q->head = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!Q->head)
		exit(OVERKLOW);
	Q->tail = Q->head ;
	Q->queuesize = LIST_INIT_SIZE;
	Q->addr = Q->head;
	return OK;
}

void ShowQueue(Queue *Q)
//打印队列
{
	printf("队头————^—————\n");
	for (int i = 0; ; ++i)
	{	

		if (i >= (Q->tail - Q->head) )
		{
			break;
		}
		printf("         |%3d|\n",*(Q->head + i));
	}
	printf("队尾————^—————\n");
}



void EnQueue(Queue *Q,int e)
//往队尾插入一个值
{	
	if (Q->tail - Q->addr >= Q->queuesize)
	{
		Q->head = (ElemType* )realloc(Q->head , ( Q->queuesize + LISTINCREMENT) * sizeof(ElemType));
	}
	if (!Q->head)
	{
		exit(OVERKLOW);
	}
	*Q->tail = e;
	Q->tail += 1;
}

int LengthQueue(Queue *Q)
//返回队列的长度
{
	int e = (Q->tail - Q->head );
	return e;
}

int Deueue(Queue *Q)
//弹出队头的值
{
	int e = *Q->head;
	Q->head += 1;
	return e;
}




/***************************７、**********************************
使用栈的功能，对于输入的任意一个非负十进制整数，
打印输出与其对应的八进制树
****************************************************************/
void OtoH()
{	
	printf("输入一个整数,将返回一个八进制数\n");
	int N;
	scanf("%d",&N);
	Sqstack Sa;
	InitStack(&Sa);
	while(N){
		Push(&Sa, N % 8);
		N = N/8;
	}
	while(!SEmpty(&Sa)){
		int e = Pop(&Sa);
		printf("%d", e);
	}
	printf("\n");

}

//***********************************************************************
int main(void)
{
	Sqstack Sa;
	InitStack(&Sa);
	Push(&Sa,9);
	Push(&Sa,8);
	Push(&Sa,7);
	ShowStack(&Sa);
	printf("S栈中有:%2d个元素\n",LengthStack(&Sa) );
	printf("%d出栈了\n",Pop(&Sa)); 
	ShowStack(&Sa);

	//利用栈转换十进制和8进制
	//OtoH();

	Queue Qa;
	InitQueue(&Qa);


	for (int i = 2; i < 30; i += 3 )
	{
		EnQueue(&Qa,i);
	}

	ShowQueue(&Qa);
	printf("队列的长度是:%d\n",LengthQueue(&Qa));
	

	printf("弹出了%d\n",Deueue(&Qa) );
	ShowQueue(&Qa);
	printf("队列的长度是:%d\n",LengthQueue(&Qa));



}








