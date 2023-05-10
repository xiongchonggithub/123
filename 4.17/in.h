

#include<stdio.h>

int main()
{
	int a=0x12345678;
	if((*((char*)&a))==0x12)
	{
		printf("Ð¡¶ËÐò\n");
	}
	if((*((char*)&a))==0x78)
	{
		printf("´ó¶ËÐò\n");
	}

	return 0;
}


