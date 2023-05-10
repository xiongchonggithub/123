#include<stdio.h>

void dis(int len,int a[])
{
	for(int i=0;i<len;i++)
	{
		printf("%2d ",a[i]);
	}
	printf("\n");
}

int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int b[10]={1,2,3,4,5,6,7,8,9,10};
	int c[10]={0};
	for(int i;i<10;i++)
	{
		c[i]=a[i]+b[i];
	}
	dis(10,a);
	dis(10,b);
	dis(10,c);
	return 0;	
}