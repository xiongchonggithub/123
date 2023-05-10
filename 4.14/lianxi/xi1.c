#include<stdio.h>
#include<stdlib.h>

struct stu{
	char name[20];
	char num[20];
	int age;
	char sex[20];
};

void display(struct stu *pstu) 
{ 
	printf("name \tnum \tage \tsex \n");
	for(int i=0;i<5;i++)
	{
		printf("%s \t%s \t%d \t%s \n",(pstu+i)->name,(pstu+i)->num,(pstu+i)->age,(pstu+i)->sex);
	}	
} 
void input(struct stu *pstu)
{
	for(int i=0;i<5;i++)
	{  
		printf("请输入姓名");
		scanf("%s",(pstu+i)->name);
		printf("请输入学号");
		scanf("%s",(pstu+i)->num);
		printf("请输入年龄");
		scanf("%d",&(pstu+i)->age);
		printf("请输入性别");
		scanf("%s",(pstu+i)->sex);
		printf("下一位\n");
	}
}
void main(void) 
{ 
	struct stu *pstu=(struct stu *)malloc(sizeof(struct stu)*5);
	input(pstu);
	display(pstu);
	free(pstu);
} 