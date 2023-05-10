#include <curses.h>
#include <stdio.h>
	
	int year = 2023;
	int month = 4;
	int day = 18;
	char week[7][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	
	int num[6][7];//用来显示图像格式6行7列
	
	//平年的每月日期数，从上一年的12月份开始计算
	int pear_month[13]={31,31,28,31,30,31,30,31,31,30,31,30,31};
	//润年的每月日期数，从上一年的12月份开始计算
	int run_month[13]={31,31,29,31,30,31,30,31,31,30,31,30,31};

//计算当前的year年和month月的dd号是星期几
int calc_week(int yy,int mm,int dd)
{
	int w,c,y,m,d;
	
	c = yy/100;//世纪数
	y = yy%100;//年份的末两位
	
	//蔡勒公式中：月份是3到14月
	if(mm <= 2)
	{
		m = mm+12;
	}
	else
	{
		m = mm;
	}
	d = dd;
	
	w = y+(y/4)+(c/4)-2*c+(26*(m+1)/10)+d-1;
	
	return w%7;
}

void show(int pear,int week_day)
{
	//=============显示第几行===========================
	int i=0;//表示行数
	int j=0;//表示列数
	int k=1;//表示几号，初始为1号
	  //判断1号是否为周日
	if(week_day == 0)
	{
		attron(COLOR_PAIR(2));//开启颜色索引2
		
		for(j=0;j<7;j++)//第一行全部显示上一个月的日期
		{
			if(pear)
				{
				num[i][j] = pear_month[month-1]-7+1+j;
				}
			else
				{
				num[i][j] = run_month[month-1]-7+1+j;
				}
			//显示数字
			mvprintw(4+i,2+5*j,"%d",num[i][j]);
		}
		attroff(COLOR_PAIR(2));//关闭颜色索引2
	}
	else
	{
		attron(COLOR_PAIR(2));//开启颜色索引2
		
		for(j=0;j<week_day;j++)//先显示上一个月的日期
		{
			if(pear)
				{
				num[i][j] = pear_month[month-1]-week_day+1+j;
				}
			else
				{
				num[i][j] = run_month[month-1]-week_day+1+j;
				}
			//显示数字
			mvprintw(4+i,2+5*j,"%02d",num[i][j]);
		}
		attroff(COLOR_PAIR(2));//关闭颜色索引2
		
		attron(COLOR_PAIR(3));//开始打印当前月份，开启颜色索引3
		//再显示当前月而定日期
		for(j=week_day;j<7;j++)
		{
			num[i][j] = k;
			//显示数字
			mvprintw(4+i,2+5*j,"%02d",num[i][j]);
			//日期数+1
			k++;
		}
	}
		//显示剩下的行数，第1行~第6行
	for(i=1;i<6;i++)
			
		for(j=0;j<7;j++)
		{
			//如果是平年，并且k已经跳月，再从1号开始打印
			if(pear && k > pear_month[month])
			{   //准备打印下个月的时候
				attroff(COLOR_PAIR(3));//关闭颜色索引3
				attron(COLOR_PAIR(2));	//开启颜色索引2
				k=1;
			}	
			else if(!pear && k > run_month[month])
			{
				//准备打印下个月的时候
				attroff(COLOR_PAIR(3));//关闭颜色索引3
				attron(COLOR_PAIR(2));	//开启颜色索引2
				k=1;
			}
			num[i][j] = k;
			mvprintw(4+i,2+5*j,"%02d",num[i][j]);
			k++;
		}
		
		attroff(COLOR_PAIR(2));	//关闭颜色索引2	
	
}	
	
int main()
{
	
	int flag;//判断平润年
	int week_day;
	printf("129\n");
	initscr();//初始化curses库
	//开启颜色索引
	start_color();
	//设置索引的目标
	init_pair(1,COLOR_YELLOW,COLOR_BLACK);//设置索引1：文字黄色，背景黑色
	init_pair(2,COLOR_CYAN,COLOR_BLACK);//设置索引2：文字青色，背景黑色
	init_pair(3,COLOR_GREEN,COLOR_BLACK);//设置索引3：文字绿色，背景黑色
	move(0,0);//右上角顶点
	hline('-',40);
	printf("139\n");
	
	move(1,0);//在（1,0）往下打印
	vline('|',10);
	
	move(10,0);
	hline('-',40);
	
	move(1,39);
	vline('|',10); 
	//====================显示星期几的表头============
	//设置显示时候的属性
	//开启颜色索引1
	attron(COLOR_PAIR(1));
	//开启加粗模式
	attron(A_BOLD);
	printf("155\n");
	//显示星期文字
	for(int i=0;i<7;i++)
	{
	mvprintw(3,2+5*i,"%s",week[i]);	
	}
	//关闭颜色索引1
	attroff(COLOR_PAIR(1));
	//关闭加粗
	attroff(A_BOLD);
	//===================显示年份和月份===========
	mvprintw(1,20,"%d",year);
	mvprintw(1,24,"%s","/");
	mvprintw(1,25,"%02d",month);
	printf("169\n");
	
	
	// 如果当前月份的1号是周日，那么第一行全部显示上一个月的日期
	// 如果当前月份的1号不是周日，那么第一行先显示上一月的日期，再显示当前月份的日期
	week_day = calc_week(year,month,1);
	
	//计算平年或者闰年
	if((year%4==0&&year%100!=0)||year%400==0)
	{
		flag = 1;//闰年
	}
	else
	{
		flag = 0;//平年
	}
	
	//显示日期
	show(flag,week_day);
	printf("169\n");
	//刷新界面
	refresh();
	printf("191\n");
	//开启特殊按键
	keypad(stdscr,TRUE);
	//去掉键盘的回显
	noecho();
	//启动特殊字符的输入
	raw();
	printf("198\n");
	int key;
	
	int quit = 1;//循环标志位
	while(quit)
	{
		//通过按键来获取键盘的输入
		key = getch();
		switch(key)
		{
				case KEY_UP: year++;break;
				case KEY_DOWN: year++;break;
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
			
		case 'q'://字符q退出-----对应q的ASCII值	
			quit = 0;
			break;
		default:
			mvprintw(10,0,"%02d",key);
			break;
		}
		//------显示年份和月份-----------
		mvprintw(1,20,"%d",year);
		mvprintw(1,24,"%s",'/');
		mvprintw(1,25,"%02d",month);
		
		//计算新的月份的1号是周几
		week_day = calc_week(year,month,1);
		
		//计算平年还是闰年
		if( (year%4==0&&year%100!=0) || (year%400==0 ))
		{
			flag = 1;//闰年
		}
		else
		{
			flag = 0;//平年
		}	
		
		//显示日期
		show(flag,week_day);
		
		//刷新界面
		refresh();
	}
	
	//关闭curses库，并重置tty终端
	endwin(); 
	return 0;	
}
