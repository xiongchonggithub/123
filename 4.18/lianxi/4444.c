#include<stdio.h>
#include<curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//�궨��
#define LENG 40
#define HIGH 20
#define ATOM_X 1
#define ATOM_Y 1


//ȫ�ֱ���
int key=0;
char snake_heart='O';//��ͷ
char snake_body='+';//����
char food='*';//ʳ��
int snake_game[HIGH][HIGH]={0};//��Ϸ����
int control=0;
int score=0;

//��������
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
			case 'q'://�ַ�'q'�˳� ---- ��Ӧ'q'��ASCIIֵ
			
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
	//��ʼ��
	
	keypad(stdscr,TRUE);
	//ȥ�����̵Ļ���
	noecho();
	//���������ַ�������
	raw();
	//������ɫ����
	start_color();
	//����������Ŀ��
	init_pair(1,COLOR_WHITE,COLOR_BLACK   );//��ɫ����1,���ְ�ɫ,������ɫ	������ֵ 2
	init_pair(2,COLOR_RED  ,COLOR_WHITE   );//��ɫ����2,���ֺ�ɫ,������ɫ	������ֵ 4,128
	init_pair(3,COLOR_GREEN,COLOR_YELLOW  );//��ɫ����3,������ɫ,������ɫ	������ֵ 8,256
	init_pair(4,COLOR_BLUE ,COLOR_MAGENTA );//��ɫ����4,������ɫ,������ɫ	������ֵ 16,512
	init_pair(5,COLOR_RED  ,COLOR_WHITE);//��ɫ����5,���ֺ�ɫ,������ɫ		������ֵ 32,1024
	init_pair(6,COLOR_CYAN ,COLOR_RED);//��ɫ����6,������ɫ,������ɫ		������ֵ 64,2048
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



