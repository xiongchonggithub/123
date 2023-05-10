#include<stdio.h>
#include<stdlib.h>

typedef struct list{
	int data; 	//数值
	struct list *next;//下一个节点的指针
}List,*LIST;

//创建头节点
LIST creat_head()
{
	LIST head = malloc(sizeof(List));
	if(head==NULL)
	{
		printf("head failed\n");
		return NULL;
	}
	
	head->next=NULL;
	
	return head;
}

//创建普通节点
LIST creat_node(int data)
{
	LIST node = malloc(sizeof(List));
	if(node==NULL)
	{
		printf("node failed\n");
		return NULL;
	}
	
	node->next=NULL;
	node->data=data;
	return node;
}

//取出链表中某个节点
LIST get_node(LIST head ,int data)
{
	LIST p = head->next ;
	while(p!=NULL)
	{
		if(p->data==data)
		{
			return p;
		}
	}
	return NULL;
}

//交换链表中两个节点
void node_change(LIST head,LIST node1,LIST node2)
{
	if(node2==NULL||node1==NULL)
	{
		return ;
	}
	LIST p = head;
	LIST q = head;
	LIST m = node1->next;
	LIST n = node2->next;
	while(p->next!=node1)//求node1的前一个节点
	{
		p=p->next;
	}
	while(q->next!=node2)//求node2的前一个节点
	{
		q=q->next;
	}
	p->next=node2;
	
	q->next=node1;
	if(m=node2)
	{
		m=node1;
	}
	node2->next=m;
	
	node1->next=n;
	
}

//头插
void insert_head(LIST head,LIST node)
{
	
	node->next=head->next;
	
	head->next=node;
	
}

//尾插
void insert_tail(LIST head,LIST node)
{
	LIST p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=node;
	
	
}

//将某个节点插入两个节点中间
void insert_middle(LIST head,LIST tail,LIST node)
{
	head->next=node;
	
	node->next=tail;
	
}

//遍历显示整个链表
void display(LIST head )
{
	LIST p=head->next;
	while(p!=NULL)
	{
		printf("-%d-",p->data);
		p=p->next;
	}
	printf("\n");
	
	
}

//使用冒泡排序排列整个链表
void sort_mao(LIST head)
{
	int i=0,j=0,k=0;
	LIST p = head->next;
	LIST q = NULL;
	while(p!=NULL)
	{
		q = head->next;
		while(q!=NULL)
		{
			if(q->next!=NULL)
			{
				if(q->data>q->next->data)
				{
					node_change(head,q,q->next);
				}
			}
			q=q->next;
		}
		p=p->next;
	}
}

int main()
{
	LIST head = creat_head();
	LIST node = NULL;
	int a[10]={7,8,6,2,0,1,3,9,4,5};
	
	for(int i = 0; i<10;i++)
	{
		node=creat_node(a[i]);
		insert_tail(head,node);
	}
	display(head);
	sort_mao(head);
	display(head);
	
}
























