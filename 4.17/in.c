#include<stdio.h>

static inline void func2(int a)
{
	
	printf("%d\n",a);
}


//extern inline void func2(int a);

int main()
{
	func2(10);
	return 0;
}


