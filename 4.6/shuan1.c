#include<stdio.h>

int main()
{
    int a1=1234;
    int b1[4];
    b1[0]=a1/1000;
    b1[1]=a1%1000/100;
    b1[2]=a1%100/10;
    b1[3]=a1%10;
    printf("%d %d %d %d\n",b1[0],b1[1],b1[2],b1[3]);
	
    int a =12;
    int b =a++;           //b=a=12 a=13
    int c =(a++,b++,a+b); //a++ b++ a+b     a=14 b=13  a+b=17
    int d =++a;           //d=++a=15
    a++;  //a=16
    b++;  //b=14
    printf("%d %d %d %d\n",a,b,c,d);

    
    
    
	return 0;
}


