#include <stdio.h>
#include <stdlib.h>

//单链表节点
typedef struct list{
	int data;//数据域
	struct list *next;//指针域
}List,*LIST;

//创建头结点
LIST create_head()
{
	LIST head = malloc(sizeof(List));
	if(head == NULL)
	{
		printf("head malloc failed");
		return NULL;
	}
	head->next = NULL;
	return head;
}

//创建子节点
LIST create_node(int num)
{
	LIST node = malloc(sizeof(List));
	if(node == NULL)
	{
		printf("node malloc failed");
		return NULL;
	}
	node->data = num;
	node->next = NULL;
	
	return node;
}

//头部插入---插入到head头结点的后面
void insert_front(LIST head,LIST node)
{
	//必须先让node->next指针指向 头结点的下一个节点
	node->next = head->next;
	
	//头结点的next指针指向 新的node节点
	head->next = node;
}

//尾部插入---插入到链表的末尾
void insert_last(LIST head,LIST node)
{
	//找到链表中最后一个节点
	LIST p = head;
	while(p->next != NULL)
		p = p->next;
	
	//把新节点加入到链表末尾
	p->next = node;
	
}



//遍历
void showlist(LIST head)
{
	printf("head-");
	
	LIST p = head;
	while(p->next != NULL)
	{
		p = p->next;
		printf("%d-",p->data);
	}
	printf("\n");
}

int main()
{
	LIST head = create_head();
	
	for(int i=0;i<10;i++)
	{
		LIST node = create_node(10*i);
		//insert_front(head,node);
		insert_last(head,node);
	}
	showlist(head);
	
	
}