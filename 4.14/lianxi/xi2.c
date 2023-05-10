//4、定义一个结构体变量(包括年月日)。计算该日在本年中是第几天？注意闰年问题。


#include<stdio.h>
#include<stdlib.h>

typedef struct calendar   
{
	enum
	{
		common_year,
		leap_year
	}year;
	int a[12];  //={31,28,31,30,31,30,31,31,30,31,30,31}
}y_m_d;

int main()
{
	int year1,month,day,sum=0;
	y_m_d *p=(y_m_d *)malloc(sizeof(y_m_d));
	if(p==NULL)
	{
		return 1;
	}
	p->a[0]=31;p->a[1]=28;p->a[2]=31;p->a[3]=30;p->a[4]=31;p->a[5]=30;p->a[6]=31;p->a[7]=31;
	p->a[8]=30;p->a[9]=31;p->a[10]=30;p->a[11]=31;
	printf("请输入一个年月日 年月日之间用空格隔开");
	scanf("%d %d %d",&year1,&month,&day);
	for(int i=1;i<month;i++)
	{
		sum+=p->a[i];
	}
	if((year1%4==0&&year1%100!=0||year1%400==0))
	{
		sum+=leap_year;
	}
	else
	{
		sum+=common_year;
	}
	printf("是这一年的第%d天\n",sum);
	free(p);
	return 0;
}