#include<stdio.h>

	

void change(int *a,int *b)

{
	int p=*a;
	*a=*b;
	*b=p;
}

int main()
{
	int a=10,b=5;
	int *p=&a,*q=&b;
	printf("a=%p\n",p);
	printf("b=%p\n",q);
	printf("a=%d b=%d\n",a,b);
	change(p,q);
	printf("p=%p\n",p);
	printf("q=%p\n",q);
	printf("a=%d b=%d\n",a,b);
	
	
	
	return 0;
}