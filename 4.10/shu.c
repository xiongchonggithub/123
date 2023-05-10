#include<stdio.h>

int main()
{
	int a[100]={[0 ... 29]=123,[70 ... 99]=456};
	printf("%ld\n",sizeof(a)/sizeof(int));
	return 0;
}