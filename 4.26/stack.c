#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//定义结构体
typedef struct stack{
	int data;
	struct stack *next;
}Stack,*STACK;

typedef struct linkstack{
	struct stack *top;
	int size;
	struct stack *str;
}link,*LINK;


LINK creat_link()
{
	LINK link = malloc(sizeof(link));
	if(link==NULL)
	{
		printf("link malloc failed");
		return NULL;
	}
	link->top=NULL;
	link->size=0;
	return link;
}

STACK creat_node(int data)
{
	STACK node=malloc(sizeof(Stack));
	if(node==NULL)
	{
		printf("node malloc failed");
		return NULL;
	}
	node->next=NULL;
	node->data=data;
}

bool isempty(LINK link)
{
	return link->top==NULL;
}

void push(LINK link,int data)
{
	STACK node = creat_node(data);
	if(isempty(link))
	{
		link->top=node;
	}
	else
	{
		node->next=link->top;
		link->top=node;
	}
	link->size++;
}

STACK pop(LINK link)
{
	STACK p=link ->top;
	
	link->top=p->next;
	
	p->next=NULL;
	
	return p;

}

void show(LINK link)
{
	STACK p=link->top;
	
	while(p!=NULL)
	{
		printf("-%d-",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	LINK link=creat_link();
	STACK q=NULL;
	int a=0;
	while(1)
	{
		printf("请输入一个数");
		scanf("%d",&a);
		if(a>0)
		{
			push(link,a);
		}
		else if(a<0)
		{
			q=pop(link);
			free(q);
		}
		else
		{
			break;
		}
		show(link);
	}
	
	
}












