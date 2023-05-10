#include<stdio.h>

typedef  union 
{ 
	long i;     //8
	int k[5];   //20
	char c;    //1
}fruit; 

struct creature 
{ 
	short cat;     // 2
	fruit apple;    //20
	double dog;  //8
}; 

fruit berry;
 
void main(void) 
{ 
	printf("%ld\n", sizeof(struct creature));
	printf("%ld\n", sizeof(berry));
	printf("%ld\n", sizeof(struct creature)+sizeof(berry));
} 