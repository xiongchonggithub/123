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
	void (*p)(int *,int *)=change;
	printf("a=%d b=%d\n",a,b);
	p(&a,&b);
	printf("a=%d b=%d\n",a,b);
	
	
	
	return 0;
}