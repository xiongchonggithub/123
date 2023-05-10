#include<stdio.h>

int main()
{
	int a ;
	int i,k;
	printf("请输入一个数");
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		k=0;
		for(int j=1;j<=i;j++)
		{
			if(i%j==0)
			{
				k++;
			}
		}
		if(k==2)
		{
			printf("%d ",i);
		}
		
		
	}
	printf("\n");

	return 0;
}