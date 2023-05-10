#include<stdio.h>

double max_min_d(int len,double a[len])
{
	double max=0,min=0;
	for(int i=0;i<len;i++)
	{
		if(min>=a[i])
		{
			min=a[i];
		}
		if(max<=a[i])
		{
			max=a[i];
		}
	}
	return max-min;
}

int main()
{
	double a[10]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,9.9,8.8,0};
	for(int i=0;i<10;i++)
	{
		printf("%f ",a[i]);
	}
	printf("\n");
	printf("%f\n",max_min_d(10,a));
	
	
	
	return 0;
}