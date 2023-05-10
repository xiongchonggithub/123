

#include"../inc/ymd.h"

void ymd()
{
	
	while(1)
	{
		char q;
		int year,month,day,day1=0;
		int month1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		
		printf("请输入某年某月某天");
		scanf("%d %d %d",&year,&month,&day);
		for(int i=0;i<month-1;i++)
		{
				day1+=month1[i];
		}
		if((year%4==0)&&(year%100!=0))
		{
			printf("%d是闰年",year);
			printf("%d年%d月%d日是这一年的第%d天\n",year,month,day,day1+1);
		}
		else
		{
			printf("%d是平年",year);
			printf("%d年%d月%d日是这一年的第%d天\n",year,month,day,day1);	
		}
		printf("输入q退出系统\n");
		
		scanf(" %c",&q);
		 if(q=='q')
		{
			break;
		}
		 
	}
}