#include<stdio.h>

int main()
{ 
    unsigned int a=0x12345678;
    unsigned char b[4];
    unsigned int c;
    
    b[0]=a/(1<<24);
    b[1]=(a%(1<<24))/(1<<16);
    b[2]=(a%(1<<16))/(1<<8);
    b[3]=a%(1<<8);
    printf("a=0x%x\nb[0]=0x%x\nb[1]=0x%x\nb[2]=0x%x\nb[3]=0x%x\n",a,b[0],b[1],b[2],b[3]);
    c=(b[0]<<24)|(b[1]<<16)|(b[2]<<8)|b[3];
    printf("c=0x%x",c);
    
    return 0;
}