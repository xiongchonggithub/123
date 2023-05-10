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
	
	int (*p[10])(int )={func};
	
	printf("%d\n",p[0](a));

	return 0;
}

