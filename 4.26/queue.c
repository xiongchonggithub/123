#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct que{
	int data;
	struct que *next;
}Que,*QUE;

typedef struct contr{
	int size;
	struct que *last,*front;
}Cque,*CQUE;

QUE creat_node(int data)
{
	QUE node=malloc(sizeof(Que));
	if(node==NULL)
	{
		printf("node malloc failed");
		return NULL;
	}
	node->data=data;
	node->next=NULL;
	return node;
	
}

CQUE que_Init()
{
	CQUE contr= malloc(sizeof(Cque));
	if(contr==NULL)
	{
		printf("contr malloc failed");
		return NULL;
	}
	contr->front=NULL;
	contr->last=NULL;
}

//入队
void push(CQUE contr,int data)
{
	QUE node=creat_node(data);
	if(contr->front==NULL)
	{
		contr->front=node;
		contr->last=node;
	}
	else
	{
		contr->last->next=node;
		contr->last=node;
	}
	contr->size++;
}

//出队
QUE pop(CQUE contr)
{
	QUE node=contr->front;
	if(contr->front==NULL)
	{
		return NULL;
	}
	else
	{
		contr->front=node->next;
		node->next=NULL;
		contr->size--;
		return node;
	}
}

void show(CQUE contr)
{
	QUE p=contr->front;
	while(p!=NULL)
	{
		printf("-%d-",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	int a=0;
	CQUE contr=que_Init();
	QUE q=NULL;
	while(1)
	{
		printf("请输入一个数");
		scanf("%d",&a);
		if(a>0)
		{
			push(contr,a);
		}
		else if(a<0)
		{
			q=pop(contr);
			free(q);
		}
		else
		{
			break;
		}
		show(contr);
	}
	return 0;
}










