#include<stdio.h>

int main()
{
	int n=1;
	while(2*n-1<=50)
	{
		printf("第%d个奇数为%d\n",n,2*n-1);
		n++;
	}
	
	
	return 0;
}