#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct tree{
	int data;
	struct tree *left;
	struct tree	*right;
}Dtree,*DTREE;

typedef struct Dque{
	DTREE son;
	struct Dque *next;
	
}Dlque,*DLQUE;

typedef struct que{
	int size;
	struct Dque *front;
	struct Dque	*last;
}Dque,*DQUE;

DTREE creat_tree(int data);
void insert(DTREE root,DTREE node);
void front_display(DTREE root);
void mid_display(DTREE root);
void last_display(DTREE root);
DLQUE creat_Dlque(DTREE root);
DQUE creat_Dque();
DLQUE pop(DQUE q);
bool Is_empty(DQUE q);
void push(DQUE q,DLQUE p);
void show(DTREE root);

int main()
{
	int a[]={8,3,1,6,4,7,10,14,13};
	DTREE root=creat_tree(a[0]);
	for(int i=1;i<9;i++)
	{
		DTREE node = creat_tree(a[i]);
		insert(root,node);
	}
	front_display(root);
	printf("\n");
	mid_display(root);
	printf("\n");
	last_display(root);
	printf("\n");
	show(root);
	printf("\n");
	return 0;
}

DTREE creat_tree(int data)
{
	DTREE node = (DTREE)malloc(sizeof(Dtree));
	if(node==NULL)
	{
		printf("root malloc failed");
	}
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	
	return node;
}

//
void insert(DTREE root,DTREE node)
{
	if(root->data>node->data)
	{
		if(root->left!=NULL)
		{
			insert(root->left,node);
		}
		else
		{
			root->left=node;
		}
		
	}
	else if(root->data<node->data)
	{
		if(root->right!=NULL)
		{
			insert(root->right,node);
		}
		else
		{
			root->right=node;
		}
	}
}

//
void front_display(DTREE root)
{
	//
		printf("-%d-",root->data);
	//左子树
		if(root->left!=NULL)
		{
			front_display(root->left);
		}
	//右子树
		if(root->right!=NULL)
		{
			front_display(root->right);
		}
}

//
void mid_display(DTREE root)
{
	//左子树
	if(root->left!=NULL)
	{
			mid_display(root->left);
	}
	//	
	printf("-%d-",root->data);
	//右子树
	if(root->right!=NULL)
	{
		mid_display(root->right);
	}
}

//
void last_display(DTREE root)
{
	//左子树
	if(root->left!=NULL)
	{
			last_display(root->left);
	}
	//右子树
	if(root->right!=NULL)
	{
		last_display(root->right);
	}
	//
	printf("-%d-",root->data);
}

//
DLQUE creat_Dlque(DTREE root)
{
	DLQUE node = malloc(sizeof(Dlque));
	if(node==NULL)
	{
		printf("DLQUE malloc failed");
	}
	
	node->son=root;
	node->next=NULL;
	return node;
}

//
DQUE creat_Dque()
{
	DQUE q =malloc(sizeof(Dque));
	if(q==NULL)
	{
		printf("DQUE malloc failed");
		return NULL;
	}
	q->size=0;
	q->front=NULL;
	q->last=NULL;

}
//入队
void push(DQUE q,DLQUE p)
{
	if(q->size==0)
	{
		q->front=p;
		q->last=p;
	}
	else
	{
		q->last->next=p;
		q->last=p;
	}
	q->size++;
}

//判断队列是否为空
bool Is_empty(DQUE q)
{
	return q->size==0;
}
//出队
DLQUE pop(DQUE q)
{
	if(Is_empty(q))
	{
		return NULL;
	}
	DLQUE m=q->front;
	q->front=q->front->next;
	q->size--;
	return m;
}



void show(DTREE root)
{
	DQUE q=creat_Dque();
	
	DLQUE node=creat_Dlque(root);
	
	push(q,node);
	
	DLQUE m=NULL;
	
	while(!Is_empty(q))
	{
		
		if(q->front->son->left!=NULL)
		{
			node=creat_Dlque(q->front->son->left);
			push(q,node);
		}
		if(q->front->son->right!=NULL)
		{
			node=creat_Dlque(q->front->son->right);
			push(q,node);
		}
		
		m=pop(q);
		printf("-%d-",m->son->data);
		free(m);
	}
	free(q);
}


//===============================二叉树删除======================
//返回NULL，表示删除了节点，进行了free操作，其余时候都返回原本传入的节点
DTREE del_tree(DTREE root,int num)
{
	DTREE max=NULL,min=NULL;
	if(root->data>num)
	{
		if(root->left!=NULL)
		{
			root->left=del_tree(root->left,num);
		}
		else 
		{
			printf("not find targer");
		}
	}
	else if(root->data<num)
	{
		if(root->right!=NULL)
		{
			root->right=del_tree(root->right,num);
		}
		else 
		{
			printf("not find targer");
		}
	}
	else
	{
		if(root->left!=NULL)
		{
			max=root->left;
			while(max->left!=NULL)
			{
				max=max->left;
			}
			root->data=max->data;
			
			root->right=del_tree(root->right,max->data);
			
		}
		else(root->right!=NULL)
		{
			min=root->right;
			while(max->right!=NULL)
			{
				min=min->right;
			}
			root->data=min->data;
			
			root->left=del_tree(root->left,min->data);
			
		}
		else
		{
			free(root)
			return NULL;
			
			
		}
		
		
		
		
		
	}
	
	
	return root;
	
}







