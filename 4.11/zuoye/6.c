#include<stdio.h>
/*
函数功能 去除字符串第n个字符
参数  p char *指针  n int数据
返回值 无
*/
void re(char *p,int n)
{
	int i=0;
	while(*(p+i)!='\0')
	{
		i++;
	}
	for(int j=n;j<i;j++)
	{
		*(p+j)=*(p+j+1);
	}
	
}
int main()
{
	int i=0,j=0;
	char a[100]={0};
	char *p=a;
	printf("请输入一段数据");
	scanf("%s",p);
	while(*(p+i)!='\0')
	{
		j=i+1;
		while(*(p+j)!='\0')
		{
			if(*(p+i)==*(p+j))
			{
				re(p,j);
				i--;
			}
			j++;
		}
		i++;
	}
	printf("%s\n",a);
	return 0;
}

/*
b=b-a;b=10-1=9
a++ a=2
b--;
b=8

b=b-a=8-2=6
a++  a=3
b-- b=5

b=b-a=5-3=2
a++ a=4
b-- b=1

b=b-a=1-4=-3
a++  a=5



*/