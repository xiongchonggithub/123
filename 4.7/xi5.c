#include<stdio.h>

int main()
{
	float a,b;
	printf("请输入一个数");
	scanf("%f",&a);
	b=5.0*(a-32.0)/9.0; //c = 5(F-32)/9
	printf("他的温度为%.2f\n",b);
	return 0;
}