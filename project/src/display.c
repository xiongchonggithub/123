
#include"../inc/display.h"


int xing_dis(int x)
{
	int i,j,k;
	for(i=0;i<x;i++)
	{
		for( k=0;k<x-i;k++)
		{
			printf(" ");
		}
		for( j=0;j<i;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	for(i;i>0;i--)
	{
		for( k=0;k<x-i;k++)
		{
			printf(" ");
		}
		for( j=0;j<i;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
}

void zimu_out(int x,int c)
{
	int i;
	int z=x<26?x:26;
	for(i=1;i<=x;i++)
	{
		int j=0;
		for(int k=0;k<z-i;k++)
		{
			printf(" ");
		}
		for(j;j<i-1;j++)
		{
			printf("%c",c+j);
		}
		for(j;j>=0;j--)
		{
			printf("%c",c+j);
		}
	printf("\n");
	}
}

int x_dis(int x,int y)
{
	int i,j,k=1;
	int n=x;
	if(x<0)
		return 0;
	if(x==0)
		return 0;
	if(x>0)
	{	
		n=x_dis(x-1,y);
	}
	for( i=0;i<y-x;i++)
	{
		printf(" ");
	}
	for( j=0;j<x;j++)
	{
		printf("* ");
	}
	
	printf("\n");
	
	return n;
}

void display()
{
	char y;
	int x;
	while(1)
	{
		
		scanf("%c",&y);
		if(y=='q')
		{
			printf("==============正在退出系统=================\n");
			break;
		}
		else if(y=='1')
		{
			printf("请输入打印行数\n");
			scanf("%d",&x);
			xing_dis(x);
		}
		else if(y=='2')	 
		{
			printf("请输入打印行数\n");
			scanf("%d",&x);
			x_dis(x,x);
		}
		
		else if(y=='3')
		{
			printf("请输入打印行数\n");
			scanf("%d",&x);
			zimu_out(x,65);
		}	
	}
}
