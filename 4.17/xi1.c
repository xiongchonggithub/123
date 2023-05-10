#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int func(int x)
{
	return x;
}



int main()
{
	int a=1;
	
	int (*p)(int )={func};
	
	printf("%d\n",p(a));

	return 0;
}