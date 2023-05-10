#include<stdio.h>
#include<curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//宏定义
#define LENG 40
#define HIGH 20
#define ATOM_X 1
#define ATOM_Y 1


//全局变量
int key=0;
char snake_heart='O';//蛇头
char snake_body='+';//蛇身
char food='*';//食物
int snake_game[HIGH][HIGH]={0};//游戏棋盘
int control=0;
int score=0;

//函数声明
void init_interface();
void memu();
void show();
void food_pro();


void memu()
{
	
	move(0+1,1);
	hline('_',39);
	move(1+1,0);
	vline('|',20);
	move(20+1,1);
	hline('_',40);
	move(1+1,40);
	vline('|',20);
	mvprintw(0,11,"Snake Eating Game");
	mvprintw(3,45,"Game Score");
	
}

void show()
{
	int i,j;
	for(i=0;i<HIGH;i++)
	{
		for(j=0;j<LENG;j++)
		{
			switch(snake_game[i][j])
			{	case 1 :
					mvprintw(ATOM_X+i,ATOM_Y+j,"%c",food);
					
					break;
				case 2 :
					mvprintw(ATOM_X+i,ATOM_Y+j,"%c",snake_heart);
					
					break;
				case 3 :		
					mvprintw(ATOM_X+i,ATOM_Y+j,"%c",snake_body);
					
					break;			
			}
		}
	}
	
}

int ddd()
{
	while(1)	
	{
		key=getch();
		switch(key)
		{
			case KEY_UP:   
						control=0;
			
							break;
			case KEY_DOWN: 
						control=1;
							break;
			case KEY_LEFT:
						control=2;	
							break;
			case KEY_RIGHT:
						control=3;
							break;
			case 'q'://字符'q'退出 ---- 对应'q'的ASCII值
			
				return 0;
				break;
		}
		
		memu();
	}
}


int main()
{
	int a=1;
	init_interface();
	snake_game[5][6]=2;
	snake_game[5][5]=3;
	snake_game[5][4]=3;
	
	refresh(); 
	memu();
	show();
	while(1)
	{
		food_pro();
	
		a=ddd();
		
		if(a==0)
		{
			break;
		}
		
	}
	
	
	
	
	
	refresh(); 
	endwin();
	return 0;
}


void init_interface()
{
	initscr();
	//初始化
	
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
}

void food_pro()
{
	int a,b;
	srand((unsigned int)time(NULL));
	while(1)
	{
		a=rand()%HIGH;
		b=rand()%LENG;
		if(snake_game[b][a]==0)
		{
			snake_game[b][a]=1;
			break;
		}
	}
	
}


void test()
{
	
	
	
	
}



void up()
{
	
}

void down()
{
	
}

void left()
{
	
}

void right()
{
	
}



