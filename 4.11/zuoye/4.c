#include<stdio.h>


	
int main()
{
	int a[10]={-1,1,-2,9,8,7,5,-6,-8,9};
	int *p=a;
	int b[10][10]={0};
	int max=0;
	int i,j,k;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10-i;j++)
		{
			for(k=0;k<i;k++)
			{
				b[i][j]+=a[k+j];
			}
			if(max<b[i][j])
			{
				max=b[i][j]
			}
		}
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(max == b[i][j])
			{
				break;
			}
		}
	}
	printf("max =%d\n",max);
	
	return 0;
}