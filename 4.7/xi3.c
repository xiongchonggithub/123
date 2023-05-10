
#include<stdio.h>
#include <ctype.h>


int main()
{
	int a=0,b=1,c=0;
	char ch;
	while((ch=getchar())!='#')
	{
		a++;
		if(ch=='\n')
		{
			b++;
		}
		if(!isgraph(ch))
		{
			c++;
		}
	}
	printf("空格%d\n行数%d\n字符总数%d\n",c,b,a);
	return 0;
}