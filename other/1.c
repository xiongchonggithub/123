#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
	int *arr;
	int size;
	int cnt;
}Heap,*HEAP;

//创建堆空间
HEAP create_heapst(int num)
{
	//顺序表结构体的堆空间
	HEAP head = malloc(sizeof(Heap));
	if(head == NULL)
	{
		printf("head malloc failed");
		return NULL;
	}
	
	//在堆空间申请连续内存
	head->arr = malloc(sizeof(int) * num);
	if(head->arr == NULL)
	{
		printf("head->arr malloc failed");
		return NULL;
	}
	
	//设置连续内存的容量
	head->size = num;
	
	//设置当前内存中的元素个数
	head->cnt = 0;
	
	return head;
}

//向顺序表中存入数据
void pop(HEAP head,int num)
{
	//判断顺序表是否已满
	if(head->cnt == head->size)
	{
		printf("顺序表已满\n");
		return ;
	}
	else{
		//让新数据存入到cnt下标的位置
		head->arr[head->cnt] = num;
		//存入元素的数量+1
		head->cnt++;
	}
}

//从顺序表的末尾删除
int push(HEAP head)
{
	//判断顺序表是否为空
	if(head->cnt == 0)
	{
		printf("顺序表为空\n");
		return 0;
	}
	else
	{
		//拿到下标cnt-1位置的元素
		int temp = head->arr[head->cnt-1];
		
		//删除cnt-1位置的元素，清零
		head->arr[head->cnt-1] = 0;
		//存入的元素数量-1
		head->cnt--;
		
		return temp;
	}
}



int main()
{
	HEAP head = create_heapst(100);
	
	//顺序表加入数据
	for(int i=0;i<10;i++)
		pop(head,3*i);
	
	//遍历数据
	for(int i=0;i<head->cnt;i++)
		printf("%d ",head->arr[i]);
	printf("\n");
	
	//删除末尾元素
	printf("删除元素 %d\n",push(head));
	
	//遍历数据
	for(int i=0;i<head->cnt;i++)
		printf("%d ",head->arr[i]);
	printf("\n");
}











