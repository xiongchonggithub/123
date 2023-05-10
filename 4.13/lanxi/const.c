#include<stdio.h>



int main()
{
	int a=10,b=8;
	int const *p=&a;
	p=&b;
	printf("%d\n",*p);
	int  *const q=&a;
	*q=1000;
	printf("%d\n",*q);
	
	
	

	return  0;
}
