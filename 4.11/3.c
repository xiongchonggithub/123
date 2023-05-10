#include<stdio.h>

void transform(char *p)
{
	
	while(*p!='\0')
	{
		if(*p<=90&&*p>=65)
		{
			*p+=32;
		}
		p++;
	}
}

int main()
{
	char a[20]={0};
	scanf("%s",a);
	transform(a);
	printf("a=%s\n",a);
	
	return 0;
}