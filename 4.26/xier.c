#include<stdio.h>
#include<stdlib.h>
int cnt=0;

void change(int *a,int *b);

void change(int *a,int *b)
{
	int p=*a;
	*a=*b;
	*b=p;
}

void charu(int *a , int len )
{
	int i=0,j=0;
	for(i;i<len-1;i++)
	{
		for(j=i+1;j>0;j--)
		{
			if(a[j-1]>a[j])
			{
				change(&a[j],&a[j-1]);
				
			}
		}
	}
}


void xier(int *a,int len,int x)
{
	if(x<1)
	{
		return ;
	}
	int i=0,j=0,z=0,m=0;
	int b[10]={0};
	int c[10]={0};
	for(z=0;z<x;z++)
	{
		for(i=z;i<len-1;i+=x)
		{
			b[j]=a[i];
			c[j]=i;
			j++;
			
		}
		charu(b,j+1);//数组插入排序
		charu(c,j+1);//下标排序
		for(m=0;m<=j;m++)
		{
			a[c[m]]=b[m];
		}
		j=0;
	}
	xier(a,len,x/2);
}

void show(int *a,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("-%d-",a[i]);
	}
	printf("\n");
}

int main()
{
	int a[10]={7,5,4,8,9,6,2,3,1,0};
	show(a,10);
	xier(a,10,5);
	show(a,10);
}