//4、编写一个程序，此程序要求输入天数，然后将该值转换为星期数和天数。例如输入 18，则要求输出：
//18 days are 2 weeks, 4days.
#include<stdio.h>

int main()
{ 
    int a;
    while (1)
    {
        printf("请输入一个天数");
        scanf("%d",&a);
        printf("星期数：%d 天数：%d\n",a/7,a%7);
    }
    
    return 0;
}