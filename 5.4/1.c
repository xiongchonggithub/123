#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	char filename[20]={0};
	printf("please input a filename  ");
	scanf("%s",filename);
	int fb = open(filename,O_RDWR);
	char key=0;
	if(fb==-1)
	{
		printf("not create this file\n");
		printf("input '1' create this file\ninput other quit system ");
		getchar();
		scanf("%c",&key);
		if(key=='1')
		{
			open(filename,O_CREAT|O_RDWR,0777);
		}
	}
	int bit=0;
	 char *p=(char *)malloc(20);
	bit=read(fb,p,20);
	printf("bit=%d p=%s\n",bit,p); 
	
	char *q=(char *)malloc(20);
	printf("please input some data  ");
	scanf("%s",q);
	write(fb,q,strlen(q)); 
	close(fb);
	fb = open(filename,O_RDWR);
	char *x=(char *)malloc(20);
	bit=read(fb,x,20);
	printf("bit=%d x=%s\n",bit,x); 
	
	close(fb);
	free(p);
	free(q);
	free(x);
	return 0;
}
