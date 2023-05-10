#include<stdio.h>

void da(int i)
{
	for(int j=1;j<=i;j++)
	{
		printf("*");
	}
}

void kong(int i)
{
	for(int k=0;k<i;k++)
	{
		printf(" ");
	}
}

int main()
{
	int a;
	int i,j;
	printf("请输入一个数");
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		kong(a-i);
		da(2*i-1);
		printf("\n");
	}
	i=i-2;
	for(i;i>0;i--)
	{
		kong(a-i);
		da(2*i-1);
		printf("\n");
	}
	return 0;
}