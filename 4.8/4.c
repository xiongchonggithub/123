#include<stdio.h>
#include <string.h>


int main(int argc,char *argv[])
{
	if(argc>2)
	{
		printf("error input excessive password\n");	
	}
	else if(argc==1)
	{
		printf("error did not input  password\n");	
	}
	else if(argc==2)
	{
		if(!strcmp(argv[1],"123456"))
		{
			printf("welcome to this system\n");
		}
		else if(strcmp(argv[1],"123456"))
		{
			printf("error input wrong password\n");
			
		}
		
	}
	return 0;
}