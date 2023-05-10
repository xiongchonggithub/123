#include <curses.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[4][4] = {{2}};

int SRand()
{
	int number;
	int flag = 0;
	int i,x,y;
	int *p = arr[0];
	srand((unsigned int)time(NULL));
	

	for (i = 0; i < 15; i++)
	{
		if ((*p++) == 0)
		{
			break;
		}
	}
	if (i == 15)
	{
		return 100;
	}
	while(1)
	{
		x = rand()%4;
		y = rand()%4;
		
		if (arr[x][y] == 0)
		{
			arr[x][y] =2;
			return 4*x+4*y;
		}
	}
}

void show()
{

	attron(A_BOLD);
	move(5,20);
	hline('-',32);


	move(6,20);
	vline('|',12);


	move(17,21);
	hline('-',31);


	move(6,51);
	vline('|',12);

	move(8,21);
	hline('-',30);
	move(11,21);
	hline('-',30);
	move(14,21);
	hline('-',30);

	move(6,28);
	vline('|',12);
	move(6,36);
	vline('|',12);
	move(6,44);
	vline('|',12);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] != 0)
			{
				mvprintw(7+3*j,24+i*5,"%d",arr[i][j]);
			}
		}
	}

	attroff(A_BOLD);
	refresh();
}



int main(int argc, char const *argv[])
{
	initscr();//初始化

	//start_color();//开启颜色配置

	//init_pair(1,COLOR_GREEN,COLOR_BLACK);//配置颜色索引1
	curs_set(0);

	int key;
	int loop = 1;
	int rm;//生成一个有空位的数组位置，坐标为（rm/4,rm%4）
	keypad(stdscr,TRUE);
	noecho();//关闭键盘回显
	raw();



	do
	{
		show();
		
		key = getch();

		switch(key)
		{
			case KEY_UP:
				rm = SRand();
				if (rm == 100)
				{
					mvprintw(0,0,"%s","game over");
				}
				
				break;
			case KEY_DOWN:
				rm = SRand();
				if (rm == 100)
				{
					mvprintw(0,0,"%s","game over");
				}
				
				break;
			case KEY_LEFT:
				rm = SRand();
				if (rm == 100)
				{
					mvprintw(0,0,"%s","game over");
				}
				
				break;
			case KEY_RIGHT:
				rm = SRand();
				if (rm == 100)
				{
					mvprintw(0,0,"%s","game over");
				}
			
				break;
			case 'q':
			 	loop = 0;
				break;
			default:
				mvprintw(0,50,"%02d",key);
				break;
		}
		show();
	}while(loop);

	endwin();
	return 0;
}