
//int 4字节 4*8 32位
//一个十六进制4位

/* （1）int a[3] = {0x11223344, 0x12345678,0x55667788};
	int *ptr = a;
	求   *((char *)ptr+1) =
	     *((short *)ptr+2)= 
		 *((char *)(ptr+1)) = ______
		 *((short *)(ptr+2))= ______


		 
		 
		 
（2）输入一个变量，求这个变量的二进制中 1的个数








（3）把一个32位变量a的 第3bit设置为1，第6bit设置为0










（4）请写出整型，指针类型，浮点数类型和布尔类型与0值比较的语句 */
#include<stdio.h>

int main()
{
	int a=0x11223344;
	
	printf("%d %p  %d  %p  \n",a,&a,*((char *)&a+1),(char *)&a+1 );
	
	return 0;
}