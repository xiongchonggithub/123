#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define EVERY_SIZE 1024

void copy(char *a,char *b)
{
	int fb1=open(a,O_RDWR);//打开文件1
	int fb2=open(b,O_RDWR);//打开文件2
	while(fb1==-1||fb2==-1)
	{
		if(fb1==-1)
		{
			printf("file1打开失败,重新创建file1\n");
			fb1=open(a,O_RDWR|O_CREAT);
		}
		if(fb2==-1)
		{
			printf("file2打开失败,重新创建file2\n");
			fb2=open(b,O_RDWR|O_CREAT);
		}
	}
	long size = lseek(fb1,0,SEEK_END);//计算文件1的大小
	char *p = (char * )malloc(EVERY_SIZE);//在堆空间里申请的内存
	lseek(fb1,0,SEEK_SET);//光标移到开头
	int wte =0,red;
	while(1)
	{
		lseek(fb1,0,SEEK_SET);
		lseek(fb2,0,SEEK_SET);
		while(red = read(fb1,p,EVERY_SIZE))
		{
			write(fb2,p,red);
		}
		char *str1=(char * )malloc(size),*str2=(char * )malloc(size);
		read(fb1,str1,size);
		read(fb2,str2,size);
		if(strcmp(str1,str2)==0)//判断两文件读取数据是否相同
		{
			printf("复制完毕！\n");
			close(fb1);
			close(fb2);
			free(p);free(str1);free(str2);
			return ;
		}
	}	
}

int main()
{
	char *a=malloc(10);
	char *b=malloc(10);
	printf("请输入您要拷贝的文件原本和副本: ");
	scanf("%s %s",a,b);
	copy(a,b);
	free(a);free(b);
	return 0;
}













