#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define NUM 10000

typedef struct hash{
	int data;
	int set;
	struct hash *next;
}Hash,*HASH;

//创建无序数组
int * get_arr()
{
	int *arr = calloc(NUM,sizeof(int));
	if(arr==NULL)
	{
		printf("calloc NUM failed\n");
		return NULL;
	}
	int i ;
	for(i=0;i<NUM;i++)
	{
		arr[i] = rand()%10000;
	}
	return arr;
}

HASH * create_hash(int *arr)
{
	HASH * h = calloc(100,sizeof(HASH));
	
	int i;
	for(i=0;i<100;i++)
	{
		h[i] =  calloc(1,sizeof(Hash));
		h[i]->next=NULL;
	}
	
	HASH node = NULL;
	
	int key;
	
	for(i=0;i<NUM;i++)
	{
		key=arr[i]%100;//通过哈希函数找到数值对于的关键值
					   //键值就是哈希表中指针数组的下标
		
		//创建出arr[i]数值的节点
		node = malloc (sizeof(Hash));
		if(node==NULL)
		{
			printf("node malloc failed");
			return NULL;
		}
		
		node->data = arr[i]; // 存入数值
		node->set  = i;      // 存入位置
		node->next = NULL;   // 指空
		
		printf("ready\n");
		
		//节点node 插入到hash[key]所指向的链表末尾
		HASH p= h[key];
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=node;
	}
	printf("ok\n");
	return h;
}

int main()
{
	int *arr=get_arr();
	
}
























