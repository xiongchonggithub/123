//5、声明一个枚举类型，使用 choices 作为标记，将枚举常量 no、yes 和 maybe 分别设置为 0、1 和 2。 

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef enum 
{
	no,
	yes,
	maybe,
}a;

int main()
{
	a choices;
	char *p=(char *)malloc(6);
	printf("请输入no yes maybe\n");
	scanf("%s",p);
	if(strcmp(p,"no")==0) 
		printf("no=%d\n",no);
	if(strcmp(p,"yes")==0)
		printf("yes=%d\n",yes);
	if(strcmp(p,"maybe")==0)
		printf("maybe=%d\n",maybe);
		
	free(p);
	return 0;
}