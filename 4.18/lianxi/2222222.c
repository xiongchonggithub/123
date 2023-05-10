#include<stdio.h>
#include<curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define atom 2

//全局变量
int num[4][4];
int x,y;
int score=0;

//函数声明
void display();
void init_interface();
void seed_pro();
void change(int *a,int *b);
int control();
int down();
int up();
int left();
int right();
void mu();

int main()
{
	initscr();
	init_interface();
	int a=1;
	display();

	while(a)
	{
		a=control();
		if(a!=2)
		{
			seed_pro();
		}
		refresh();
		display();
		if(a==2)
		{
			break;
		}
		
	}
	refresh();
	endwin();
	if(a==2)
		printf("geme over\n");
	return 0;
}
//
void seed_pro()
{
	int a=1,b=0,i=0,j=0;
	srand((unsigned int)time(NULL));
	while(a)
	{
		
		x=rand()%4;
		y=rand()%4;
		if(num[x][y]==0)
		{
			num[x][y]=atom;
			a=0;
		}
		for(;i<4;i++)
		{
			for(;j<4;j++)
			{
				if(num[i][j]!=0)
				{
					b++;
				}
			}
		}
		if(b==0)
		{
			break;
		}
	}

}
//显示函数
void display()
{
	mu();
	int lcd_color=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(num[i][j]!=0)
			{
				switch(num[i][j])
				{
					case 0:
					case 2:
						lcd_color = 1; break;
					
					case 4:
					case 128:
						lcd_color = 2; break;
						
					case 8:
					case 256:
						lcd_color = 3; break;
						
					case 16:
					case 512:
						lcd_color = 4; break;
					
					case 32:
					case 1024:
						lcd_color = 5; break;
						
					case 64:
					case 2048:
						lcd_color = 6; break;
				}
				attron(COLOR_PAIR(lcd_color));//开启颜色索引lcd_color
				mvprintw(3+5*i,3+10*j,"%4d",num[i][j]);
				attroff(COLOR_PAIR(lcd_color));//关闭颜色索引3
			}
		}
	}
	
	for(int n=0;n<4;n++)
	{
		for(int m=0;m<4;m++)
		{
			score+=num[n][m];
			
		}
	}
	mvprintw(3,45,"Game Score");
	mvprintw(3,45+11,"%d",score);
	score=0;
}

void mu()
{
	move(0,1);
	hline('_',39);
	move(1,0);
	vline('|',20);
	move(20,1);
	hline('_',40);
	move(1,40);
	vline('|',20);
	for(int i=0;i<4;i++)
	{
		move(1,10*i);
		vline('|',19);
		move(5*i,1);
		hline('_',39);
	}
	mvprintw(3,45,"Game Score");
}
void init_interface()
{
	keypad(stdscr,TRUE);
	//去掉键盘的回显
	noecho();
	//启动特殊字符的输入
	raw();
	
	//开启颜色索引
	start_color();
	//设置索引的目标
	init_pair(1,COLOR_WHITE,COLOR_BLACK   );//颜色索引1,文字白色,背景黑色	用于数值 2
	init_pair(2,COLOR_RED  ,COLOR_WHITE   );//颜色索引2,文字红色,背景白色	用于数值 4,128
	init_pair(3,COLOR_GREEN,COLOR_YELLOW  );//颜色索引3,文字绿色,背景黄色	用于数值 8,256
	init_pair(4,COLOR_BLUE ,COLOR_MAGENTA );//颜色索引4,文字蓝色,背景粉色	用于数值 16,512
	init_pair(5,COLOR_RED  ,COLOR_WHITE);//颜色索引5,文字红色,背景白色		用于数值 32,1024
	init_pair(6,COLOR_CYAN ,COLOR_RED);//颜色索引6,文字青色,背景白色		用于数值 64,2048
	mu();
	
}

int control()
{
	int s=0;
	
	
	int key;
	//通过按键来获取键盘的输入
	key = getch();
	switch(key)
	{
		case KEY_UP:    s=up();
						break;
		case KEY_DOWN: 
						s=down(); 
						break;
		case KEY_LEFT:
						s=left();
						break;
		case KEY_RIGHT:
						s=right();
						break;
		case 'q'://字符'q'退出 ---- 对应'q'的ASCII值
			return 0;
			break;
	}
	clear();
	display();
	return s;
}
//下
int down()
{
	int tree=0;
	for(int k=0;k<4;k++)
	{
		for(int i=2;i>=0;i--)
		{
			for(int j=0;j<4;j++)
			{
				
				if(num[i+1][j]==0)
				{
					num[i+1][j]=num[i][j];
					num[i][j]=0;
					tree++;
				}
				
				
				
				
				if(num[i+1][j]==num[i][j])
				{
					num[i+1][j]+=num[i][j];
					num[i][j]=0;
					tree++;
				}
			}
		}
	}
	if(tree==0)
	{
		return 2;
	}
	return 1;
}
//上
int up()
{
	int tree=0;
	for(int k=0;k<4;k++)
	{
		for(int i=1;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				
				if(num[i-1][j]==0)
				{
					num[i-1][j]=num[i][j];
					num[i][j]=0;
					tree++;
				}
				if(num[i-1][j]==num[i][j])
				{
					num[i-1][j]+=num[i][j];
					num[i][j]=0;
					tree++;
				}
				
			}
		}
	}
	if(tree==0)
	{
		return 2;
	}
	return 1;
}

//左
int left()
{
	int tree=0;
	for(int k=0;k<4;k++)
	{
		for(int i=0;i<4;i++)
		{
			for(int j=1;j<4;j++)
			{
				
				if(num[i][j-1]==0)
				{
					num[i][j-1]=num[i][j];
					num[i][j]=0;
					tree++;
				}
				if(num[i][j-1]==num[i][j])
				{
					num[i][j-1]+=num[i][j];
					num[i][j]=0;
					tree++;
				}
				
			}
		}
	}
	if(tree==0)
	{
		return 2;
	}
	return 1;
}
//右
int right()
{
	int tree=0;
	for(int k=0;k<4;k++)
	{
		for(int i=0;i<4;i++)
		{
			for(int j=2;j>=0;j--)
			{
				if(num[i][j+1]==0)
				{
					num[i][j+1]=num[i][j];
					num[i][j]=0;
					tree++;
				}
				if(num[i][j+1]==num[i][j])
				{
					num[i][j+1]+=num[i][j];
					num[i][j]=0;
					tree++;
				}
				
			}
		}
	}
	if(tree==0)
	{
		return 2;
	}
	return 1;
}