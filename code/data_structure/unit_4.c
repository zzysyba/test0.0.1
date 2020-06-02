#include "zhaizy.h"
int many = 0;

typedef struct BstNode
//二叉树的结构
{
    ElemType data;//数据域
    struct BstNode *Left;//左指针
    struct BstNode *Right;//右指针
 
}BstNode, *Bstnode;

/***************************************************************
            			数据结构-严魏敏--2020/4/23
						以及网上课后习题-----二叉树
****************************************************************/
BstNode* CreatBstNode(ElemType data)
/*初始化二叉树*/
{
    BstNode* root = (BstNode *)malloc(sizeof(*root) );
    root->data  = data;
    root->Left  = NULL;
    root->Right = NULL;
 
    return root;
}




void insertT(BstNode *T,int number)
//插入一个节点到二叉树中
{	
    //创建节点
    BstNode* root = (BstNode *)malloc(sizeof(*root));
    root->data  = number;
    root->Left  = NULL;
    root->Right = NULL;

    //插入的节点比根小
    if (T->data > number)
    {
        if (T->Left == NULL)
        {
            T->Left = root;
            return;
        }
        insertT(T->Left , number);
    }

    //插入的节点比根大
    if (T->data <= number )
    {
        if (T->Right == NULL)
        {
            T->Right = root;
            return;
        }
        insertT(T->Right , number);
    }
	
}





void DrawByTree(BstNode *T, int depth)
//按照树状打印二叉树
{
    if (NULL == T)
    {

        return ;
    }
 
    DrawByTree(T->Right, depth+1);//打印右子树，并将层次加1
 
    for (int i = 0; i < depth; i++)//按照递归的层次打印空格
    {
        printf("   ");
    }
 
    printf("%d\n", T->data);//输出根结点
 
    DrawByTree(T->Left, depth+1);//打印左子树，并将层次加1
}


void torder(BstNode *T)
{
    if(NULL == T)
    {
        return ;
    }
 
    torder(T->Right);
 
    printf("%d ",T->data);
    torder(T->Left);
}




//先序遍历二叉树
void pre_order(BstNode *T)
{
    if(NULL == T)
    {
        return ;
    }
 
    /*step 1:访问根*/
    printf("%d ",T->data);
 
    /*step 2:用先序的方式去访问左子树*/
    pre_order(T->Right);
 
    /*step 3:用先序的方式去访问右子树*/
    pre_order(T->Left);
}

BstNode* FindFather(BstNode *T,int key, int *Tr )
//寻找输入节点的父节点
{
	BstNode* p = T;
    BstNode* backfather = p;

	if(NULL == T)
    {
        return NULL ;
    }
    /*step 1:访问根*/
    else if (T->Left != NULL && T->Left->data == key)
    {
    	printf(" lift n`s father is %d\n",T->data);
    	*Tr = -1;
    	return backfather;
    }
    else if (T->Right != NULL && T->Right->data == key)
    {
    	printf(" right n`s father is %d\n",T->data);
    	*Tr = 1;
    	return backfather;
    }
 
    /*step 2:用先序的方式去访问左子树*/
    FindFather(T->Right, key , Tr);
 
    /*step 3:用先序的方式去访问右子树*/
    FindFather(T->Left, key , Tr);
}


BstNode* DeleteBstNode(BstNode* root, const ElemType key)
//删除指定节点
{
    int pos = 0;
    int *Tr = &pos;
    BstNode *backfather;//父结点指针
    BstNode *ptr;//删除结点指针
    BstNode *next;//子结点指针
    BstNode **fap;//父节点指向删除节点的指针
 	


    backfather = FindFather(root, key , Tr );
    if (NULL == backfather)
    {
        return root;
    }
 	printf("father`s data is %d.\n",backfather->data );
 
    switch (pos)
    {
        case -1:
        {
            ptr = backfather->Left;
            fap = &(backfather->Left);
            break;
        }
        case  1:
        {
            ptr = backfather->Right;
            fap = &(backfather->Right);
            break;
        }
        case  0:
        {
            ptr = backfather;
            fap = &(root);//不能用backfather，操作backfather不会作用到root
            break;
        }
    }

    //第一种情况，没有左子树
    if (NULL == ptr->Left)
    {
        //以当前节点的右子节点替换当前节点
        *fap = ptr->Right;
 		 printf("删除%d.\n",ptr->data );
        free(ptr);
        ptr = NULL;
        return root;
    }

    //第二种情况，没有右子树
    if (NULL == ptr->Right)
    {
        //以当前节点的左子节点替换当前节点
        *fap = ptr->Left;
 		printf("删除%d.\n",ptr->data );
        free(ptr);	
        ptr = NULL;
        return root;
    }

    //第三种情况，有左子树也有右子树
    backfather = ptr;  //父节点指向当前节点
    next = backfather->Left;   //设置子节点
    while (NULL != next->Right)//找到最接近ptr->data的节点
    {
        backfather = next;
        next = next->Right;
    }
    ptr->data = next->data;  //替换数据
 
    //此时 next->Right == NULL
    if (backfather->Left == next)
    {
        backfather->Left = next->Left;
    }
    else
    {
        backfather->Right = next->Right;//NULL
    }
    printf("删除%d.\n",next->data );
    free(next);
    return root;
 
}


int GetDepth(BstNode* T)
//树的深度
{
    if (NULL == T)
    {
        return 0;//空树深度为0
    }
 
    int ld, rd;
    ld = 1 + GetDepth(T->Left );
    rd = 1 + GetDepth(T->Right);
 
    return (ld > rd) ? ld : rd;
}


/***************************７、**********************************
假设二叉树用二叉链表存储，
设计一个算法，求二叉树的结点个数。
****************************************************************/


void keymany(BstNode *T)
{
    if(NULL == T)
    {
        return;
    }
 
    /*step 1:访问根*/
    many += 1;
 
    /*step 2:用先序的方式去访问左子树*/
    keymany(T->Right);
 
    /*step 3:用先序的方式去访问右子树*/
    keymany(T->Left);
}


/***************************8、**********************************
编写一个递归算法，
将用二叉链表表示的二叉树的所有结点的左、右子树交换。
****************************************************************/

void exchange(BstNode *T) 
{	
	if(!T)
		return; 
	BstNode * temp; 

	temp=T->Left; 
	T->Left=T->Right; 
	T->Right=temp; 

	exchange(T->Left); 
	exchange(T->Right); 
}


/***************************9、**********************************
试写出二叉链表表示的二叉树的先序遍历的非递归算法。
****************************************************************/
void preorder(BstNode* T)
{
    BstNode* Seqstack[MAXSIZE];         
    int top = -1;
    BstNode* p;
    
    if(T != NULL)
    {
        top++;
        Seqstack[top] = T;                      // 先将根结点压栈
        while(top > -1)                         // 栈不为空时循环
        {
            p = Seqstack[top];                  // 栈顶元素出栈
            top --;
            printf("%d ", p->data);             // 访问栈顶元素
            if(p->Right != NULL)               // 如果右孩子不为空，则进栈
            {
                top ++;
                Seqstack[top] = p->Right;
            }
            if(p->Left != NULL)               // 如果左孩子不为空，则进栈
            {
                top ++;
                Seqstack[top] = p->Left;
            }
        }
    }
}


//***************************************************************
int main(void)
{	
	int kill = 100;
	int num[10];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; ++i)
    {
    	num[i] =  rand() % 100;
    	printf("%d,",num[i]  );
    	if (kill > num[i])
    	{
    		kill = num[i];
    	}

    }

    printf("\n");


    BstNode* Troot = CreatBstNode(num[0]);
    printf("*************************\n");
    DrawByTree(Troot ,0 );
    printf("*************************\n");

    for (int i = 1; i < 10; ++i)
    {
    	insertT(Troot ,num[i] );
		printf("*************************\n");
		DrawByTree(Troot ,0 );
		printf("*************************\n");
    }

    printf("树的深度：%d\n",GetDepth(Troot) );

	pre_order(Troot);
	printf("\n");
	printf("n is %d.\n",kill);
	DeleteBstNode(Troot, kill );

	printf("*************************\n");
	DrawByTree(Troot ,0 );
	printf("*************************\n");

	keymany(Troot);
	printf("树的节点数%d\n", many);

	//exchange(Troot);
	printf("*************************\n");
	DrawByTree(Troot ,0 );
	printf("*************************\n");

    torder(Troot);  

	printf("\n");



	return 0;
}
