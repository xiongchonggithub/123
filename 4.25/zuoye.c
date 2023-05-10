#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 50

void change(char *a,char *b);
void maopao(char *p,int len);
void xuanze(char *p,int len);
void kuaisu(char *p,int left,int right);
void charu(char *p ,int len);
void del_repeat(char *p);

int main()
{
	char *p=(char *)malloc(MAXSIZE);
	printf("快输入一串字符");
	scanf("%s",p);
	char a[MAXSIZE],b[MAXSIZE],c[MAXSIZE],d[MAXSIZE],e[MAXSIZE];
	stpcpy(a,p);stpcpy(b,p);stpcpy(c,p);stpcpy(d,p);stpcpy(e,p);
	printf("原数组   %s\n",a);
	maopao(a,strlen(a));
	printf("冒泡排序 %s\n",a);
	xuanze(b,strlen(b));
	printf("选择排序 %s\n",b);
	del_repeat(c);
	kuaisu(c,0,strlen(c)-1);
	printf("去重快速排序 %s\n",c);
	charu (d,strlen(d));
	printf("插入排序 %s\n",d);
	del_repeat(e);
	printf("去重 %s\n",e);
	return 0;
}


void change(char *a,char *b)
{
	char p=*a;
	*a=*b;
	*b=p;
}

void maopao(char *p,int len)
{
	int i=0,j=0,k=0;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-k-1;j++)
		{
			if(p[j]>p[j+1])
			change(&p[j],&p[j+1]);
		}
		k++;
	}
	
}

void xuanze(char *p,int len)
{
	int i=0,j=0;
	char *max=NULL;
	for(i=0;i<len-1;i++)
	{
		max=&p[0];
		for(j=0;j<len-i;j++)
		{
			if((int)*max<(int)p[j])
			{
				max=&p[j];
			}
		}
		change(max,&p[len-1-i]);
	}
	
	
}

void kuaisu(char *p,int left,int right)
{
	if(left>=right)
	{
		return ;
	}
	int i=left,j=right,key=p[left];
	
	while(i<j)
	{
		while(p[j]>key&&i<j)
			j--;
		p[i]=p[j];
		
		while(p[i]<key&&i<j)
			i++;
		p[j]=p[i];
		
	}
	p[i]=key;
	
	kuaisu(p,left,i-1);
	kuaisu(p,j+1,right);
}

void charu(char *p ,int len)
{
	int i=0,j=0;
	for(;i<len-1;i++)
	{
		for(j=i+1;j>0;j--)
		{
			if(p[j-1]>p[j])
			{
				change(&p[j-1],&p[j]);
			}
		}
		
	}
}

void del_repeat(char *p)
{
	int i=0,j=0,k=0,x=0;
	int len = strlen(p);
	
	for(i=0;i<len-k;i++)
	{
		for(x=i+1;x<len-k;x++)
		{
			if(p[i]==p[x])
			{
				for(j=x;j<len;j++)
				{
					p[j]=p[j+1];
				}
				k++;
				i--;
			}
		}
		
	}
}


















