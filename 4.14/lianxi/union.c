#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef  union 
{ 
long i;     //8
int k[5];   //20
char c;    //1
} fruit; 



int main()
{
	fruit a;
	
	printf("%ld\n",sizeof(a));
	return 0;
}