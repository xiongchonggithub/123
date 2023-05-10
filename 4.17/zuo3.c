#include<stdio.h>

float my_power(int n,float x)
{
	if(n==0)
		return 1;
	if(n==1)
		return x;
	if(n>1)
		return my_power(n-1,x)*x;
	if(n<0)
		return my_power(n+1,x)/x;
}


int main()
{
	float a = 1.1,c=0;
	int b=0;
	printf("please input a number ");
	scanf("%d",&b);
	c=my_power(b,a);
	printf("this number is %.6f\n",c);
	
	return 0;
}