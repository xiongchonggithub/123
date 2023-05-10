
#include<stdio.h>

int main()
{
	int a=0x12345678;
	if((*((char*)&a))==0x12)
	{
		printf("小端序\n");
		return 1;
		
	}
	if((*((char*)&a))==0x78)
	{
		printf("大端序\n");
		return 0;
	}

	return 0;
}
