#include<stdio.h>

int main()
{
	int a ;
	for(;;)
	{
		printf("请输入一个天数");
		scanf("%d",&a);
		printf("星期数%d,天数%d\n",a/7,a%7);
		
	}
	
	
	
	
	return 0;
}