#include <stdio.h> 
int main(void) 
{ 
int a[4] = {1, 2, 3, 4}; 
int *p1=(int *)(&a+1); 
//&a������a�ĵ�ַ&a+1�������ַ������һ����λ�������ƶ�4*4���ֽ�
int *p2=(int *)((int)a+1); 

for(int i=0;i<4;i++)
{
	printf(" a[%d] %x\n",i,&a[i]);
}
printf("  %x\n",p2); 
return 0; 

} 