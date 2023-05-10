#include<stdio.h>

#define MAX(x) (0<x&&x<10)?(x+4):(x+1)

int main()
{
	int a= 2;
	int b=0;
	b = MAX(a)+2;
	printf("sum =%d\n",MAX(a));
	printf("sum =%d\n",b);
	return 0;
}