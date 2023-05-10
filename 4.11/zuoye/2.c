#include <stdio.h> 
int main(void) 
{ 
int a[4] = {1, 2, 3, 4}; 
int *p1=(int *)(&a+1); 
//&a是数组a的地址&a+1既数组地址向右移一个单位即向右移动4*4个字节
int *p2=(int *)((int)a+1); 

for(int i=0;i<4;i++)
{
	printf(" a[%d] %x\n",i,&a[i]);
}
printf("  %x\n",p2); 
return 0; 

} 