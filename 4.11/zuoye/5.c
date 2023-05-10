//5、编写一个程序，初始化一个 3x5 的二维 double 型数组，
//并利用一个基于变长数组的函数把该数组赋值到另一个二维数组，
//另外再写一个基于变长数组的函数来显示两个数组的内容。
//这两个函数应该能够处理任意的NxM 数组。


#include<stdio.h>

void display(int x,int y,double a[x][y],double b[x][y])
{
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			printf("a[%d][%d]=%.2f ",i,j,a[i][j]);	
			printf("b[%d][%d]=%.2f \n",i,j,b[i][j]);	
			
		}

	}
}

void fun(int x,int y,double a[x][y],double b[x][y])
{
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			b[i][j]=a[i][j];	
		}
	}
}
	
int main()
{
	double a[3][5]={1,2,3,4,2,2,2,2,2,5,5,5,5,5};
	double b[3][5]={0};
	fun(3,5,a,b);
	display(3,5,a,b);
	return 0;
}