#include<stdio.h>


void insert(int n,int data);
void re(int n);
int test();
#define maxsize 100 
int arr[maxsize]={0,1,2,3,4,5,6,7};
int end =-1;
void dis();

int main()
{
	arr[10]=end;
	dis();
	insert(1,2);
	dis();
	re(3);
	dis();
	return 0;
}

void insert(int n,int data)
{
	
	int i=0,b;
	while(arr[i]!=end)
	{
		i++;
	}
	for(i;i>=n;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[n]=data;
}

void re(int n)
{
	int i;
	while(arr[i]!=end)
	{
		i++;
	}
	for(int j=n;j<i;j++)
	{
		arr[j]=arr[j+1];
	}
	
}

int test()
{
	int i=1;
	while(arr[i]!=end)
	{
		i++;
	}
	return i;
}

void dis()
{
	int len=test();
	for(int i=0;i<len;i++)
	{
		printf("a[%d]=%d ",i,arr[i]);
	}
	printf("\n");
	
}
