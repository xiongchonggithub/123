/* 编写一个 transform()函数，它接受 4 个参数：包含 double 类型数据的源数组名，double 类型的目标数组名， 
表示数组元素个数的 int 变量以及一个函数名(或者等价的指向函数的指针)。transform()函数把指定的函数作 
用于源数组的每个元素，并将返回值放到目标数组中。 
例如：transform(source, target, 100, sin); 
这个函数调用 sin(source[0])赋给 target[0]，等等。共有 100 个元素。在一个程序中测试该函数，调用 4 次 
transform()，分别使用 math.h 函数库中的两个函数以及自己设计的两个适合的函数作为参数。 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double x[100]={0},y[100]={0};

double sin(double x)
{
	return x+1;
}

void transform(int len,double x[],double y[],double p(double ))
{
	for(int i=0;i<len;i++)
	{
		y[i]=p(x[i]);
	}
}

void display(double a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%.1f\t",a[i]);
		if((i+1)%10==0)
		{
			printf("\n");
		}
	}
}

int main()
{
	for(int i=0;i<100;i++)
	{
		x[i]=i;
	}
	transform(100,x,y,sin);
	printf("x\n");
	display(x,100);
	printf("y\n");
	display(y,100);
	return 0;
}
