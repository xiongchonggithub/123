#include<stdio.h>

	
int main()
{
	int a[3][4]={1,2,3,4,5,7,8,9,6,5,5,4};
	int *p[3]={a[0],a[1],a[2]};
	int sum=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			sum+=*(p[i]+j);
		}
	}
	printf("sum=%d\n",sum);
	
	return 0;
}
