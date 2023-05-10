#include<stdio.h>

int main()
{
    unsigned char a=0xab,b=0xcd,e,f;
    unsigned short c;
    c=(a<<8)|b;
    
    e=c/(1<<8);
    f=c%(1<<8);
    printf("c=0x%x\ne=0x%x\nf=0x%x\n",c,e,f);
    
    
    
    
    
    
    
    
    
    
    return 0;
}