#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define A 3
#define B (A+2)
#define C (B*A)



int main()
{
	printf("A=%d\n",A);
	
	printf("A+2=%d\n",A+2);
	printf("B=%d\n",B);
	

	printf("c=%d\n",C);
	printf("B*A=%d\n",B*A);

	printf("2*c=%d\n",2*C);
	return 0;
}