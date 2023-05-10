#include<stdio.h>

//a += a                   a=12
//a -= 2                    a=10
//a *= 2+3                  a=60
//a /= a+a                   a=0.5
//a %= (n%2)，n 的值为 5    a=0
//a += a -= a *= a

int main()
{ 
    int a=12;
    printf("%d\n%d\n%d\n%d\n%d\n%d\n",a+=a,a-=2,a*=2+3,a/=(a+a),a%=1,a*=a);

    return 0;
}