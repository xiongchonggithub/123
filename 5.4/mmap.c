#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
	int fb = open("2.txt",O_RDWR);
	char * p = (char * )malloc(20); 
	if(fb==-1)
	{
		printf("not create this file\n");
		return -1;	
	}
	
	
	char * str = mmap(NULL,10,PROT_READ|PROT_WRITE,MAP_SHARED,fb,0);
	
	scanf("%s",str);
	lseek(fb,0, SEEK_SET);
	int red = read(fb,p,20);
	printf("%s",p);
	
	
	
	munmap(str,10);
	close(fb);
	free(p);
	return 0;
}






