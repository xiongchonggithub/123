#include<stdio.h>

int main()
{
	int a;
	printf("Please enter a number ");
	scanf("%d",&a);
	if(a==1)
	{
		printf("1+2+3+....+n=%d\n",a);
	}
	else if(a>1)
	{
		printf("1+2+3+....+n=%d\n",(a*(a-1))/2);
	}
	else
	{
		printf("error");
	}
	return 0;
}