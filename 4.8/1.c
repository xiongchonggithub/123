#include<stdio.h>

int multiply(int x,int y)
{
	return x*y;
}

int main()
{
	int a=2 , b=3 ,c;
	c=multiply(a,b);
	printf("c %d\n",c);
	return 0;
}