#include<stdio.h>

int main()
{
	char str[]="22222222222";
	printf("%ld\n", sizeof(str)/sizeof(str[0]));
	printf("%ld\n", sizeof(str)/sizeof(*(str+0)));
	printf("%ld\n", sizeof(str)/sizeof('a'));
	printf("%ld\n", sizeof('a'));
	
	
	return 0;
}