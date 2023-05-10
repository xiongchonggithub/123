#include<stdio.h>

int main()
{ 

    char a;
    printf("请输入一个字符");
    scanf("%c",&a);

    switch (a)
    {
        case 'a' ... 'z' :
            printf("小写");
            printf("%c\n",a);
            break;
         case 'A' ... 'Z' :
            printf("小写");
            printf("%c\n",a);
            break;
         case '0' ... '9' :
            printf("小写");
            printf("%c\n",a);
            break;
    default:
            printf("其他\n");
            break;
    }
    return 0;
}
