//声明 4 个函数，并把一个指针数组初始化为指向它们。每个函数接受两个 double 参数并返回 double 值。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double func1(double x,double y)
{
	return x+y;
}

double func2(double x,double y)
{
	return x-y;
}
double func3(double x,double y)
{
	return x*y;
}
double func4(double x,double y)
{
	return x/y;
}

int main()
{
	double (*fun[4])(double ,double)={func1,func2,func3,func4};
	double a[4],x=10,y=5;
	for(int i=0;i<4;i++)
	{
		a[i]=fun[i](x,y);
		printf("a[%d]=%.2f\n",i,a[i]);
	}
	return 0;
}