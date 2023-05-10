
#include<stdio.h>
#include<curses.h>
#include <unistd.h>

//定义全局变量
int month1[13]={31,31,28,31,30,31,30,31,31,30,31,30,31};
int month2[13]={31,31,29,31,30,31,30,31,31,30,31,30,31};
char *p[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int year=2023,month=4,day=18;
int flag;
int num[6][7];

//函数声明
int get_weekday(int year, int month);
void init_interface();
void display(int year, int month);
void year_determine(int year);
int control();

//界面显示
void init_interface()
{
	initscr();
	//开启颜色索引
	start_color();
	//设置索引的目标
	init_pair(1 ,COLOR_YELLOW ,COLOR_BLACK );//设置索引1： 文字黄色，背景黑色
	init_pair(2 ,COLOR_CYAN ,COLOR_BLACK );//设置索引2:文字青色，背景黑色
	init_pair(3 ,COLOR_GREEN ,COLOR_BLACK );//设置索引3：文字绿色，背景黑色
	init_pair(4 ,COLOR_RED ,COLOR_WHITE );//设置索引3：文字红色，背景白
	init_pair(5 ,COLOR_MAGENTA ,COLOR_WHITE );//设置索引3：文字绿色，背景白
	
	move(0,1);
	hline('_',59);
	
	move(1,0);
	vline('|',20);
	
	move(20,1);
	hline('_',60);
	
	move(1,60);
	vline('|',20);
	
	move(2,1);
	hline('*',59);
	attron(COLOR_PAIR(3));//开启颜色索引2
	for(int i=0;i<7;i++)
	{
		mvprintw(3,5+8*i,"%s",p[i]);
		if(i<=5)
		{
			move(3,10+8*i);
			vline('|',1);
		}
	}
	
	mvprintw(1,25,"%d",year);
	move(1,25+4);
	hline('\\',1);
	mvprintw(1,25+4+1,"%d",month);
	
	attroff(COLOR_PAIR(3));//关闭颜色索引2
	move(4,1);
	hline('*',59);
	
	
}

//显示
void display(int year, int month)
{
	get_weekday(year,month);
	year_determine(year);
	int i=0,j=0,k=1;
	int week_day=get_weekday(year,month);
	if(week_day!=1)
	{
		attron(COLOR_PAIR(2));//开启颜色索引2
		for(j=0;j<7;j++)
		{
			if(flag==1)
			{
				num[i][j]=month2[month-1]-week_day+2+j;
				if(num[i][j]>month2[month-1])
				{break;}
			}
			else
			{
				num[i][j]=month1[month-1]-week_day+2+j;
				if(num[i][j]>month1[month-1])
				{break;}
			}
			
			mvprintw(5+i,5+8*j,"%2d",num[i][j]);
		}
		attroff(COLOR_PAIR(2));//关闭颜色索引2
	}
	attron(COLOR_PAIR(3));//开启颜色索引3
	for(i;i<6;i++)
	{
		if(i>0)
		{
			j=0;
		}
		for(j;j<7;j++)
		{
			if(flag==1&&(k>month2[month]))
			{
				attroff(COLOR_PAIR(3));//关闭颜色索引3
				attron(COLOR_PAIR(2));//开启颜色索引2
				k=1;
			}
			else if(flag!=1&&(k>month1[month]))
			{
				attroff(COLOR_PAIR(3));//关闭颜色索引3
				attron(COLOR_PAIR(2));//开启颜色索引2
				k=1;
			}
			
			
				num[i][j]=k++;
				mvprintw(5+2*i,5+8*j,"%2d",num[i][j]);
			
			
		}
	}
	
}

//计算某一年某一月的第一天是星期几
int get_weekday(int year, int month) 
{
    int century, year_of_century, weekday;
    century = year / 100;
    year_of_century = year % 100;
    if (month == 1 || month == 2) {
        month += 12;
        year_of_century--;
    }
    weekday = (year_of_century + year_of_century / 4 + century / 4 - 2 * century + 26 * (month + 1) / 10) % 7;
    return (weekday + 7) % 7;
}

//计算是平年还是闰年
void year_determine(int year)
{
	if((year%4==0&&year%100!=0)||(year%400==0))
		flag = 1;
	else
		flag = 0;
}

int control()
{
	keypad(stdscr,TRUE);
	//去掉键盘的回显
	noecho();
	//启动特殊字符的输入
	raw();
	int key;
	//通过按键来获取键盘的输入
	key = getch();
	switch(key)
	{
		case KEY_UP:  year++;break;
		case KEY_DOWN: year--; break;
		case KEY_LEFT:
				month--;
				if(month == 0)
				{
					year--;
					month = 12;
				}
				break;
		case KEY_RIGHT:
				month++;
				if(month == 13)
				{
					year++;
					month = 1;
				}
				break;
		case 'q'://字符'q'退出 ---- 对应'q'的ASCII值
			return 0;
			break;
	}
	display(year,month);	
	attron(COLOR_PAIR(4));//开启颜色索引3
	mvprintw(1,25,"%d",year);
	move(1,25+4);
	hline('\\',1);
	mvprintw(1,25+4+1,"%d",month);
	attroff(COLOR_PAIR(4));//关闭颜色索引3
	return 1;
}

int main()
{
	int x=1;
	init_interface();
	display(year,month);
	while(x)
	{
		x=control();
		refresh();
	}
	endwin();
	return 0;
}
