#include<stdio.h>

void display(int a)
{
	int i,j,k;
	for(i=1;i<=a;i++)
	{
		for(k=1;k<=a-i;k++)
		{
			printf(" ");
		}
		for(j=1;j<i;j++)
		{
			printf("%c",j+64);
		}
		for(;j>=1;j--)
		{
			printf("%c",j+64);
		}
		printf("\n");
	}
}

int main()
{
	int a;
	
	printf("请输入一个数");
	scanf("%d",&a);
	display(a);
	return 0;
}