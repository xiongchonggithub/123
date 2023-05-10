#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>


#define UP     1
#define DOWN  -1
#define LEFT   2
#define RIGHT -2
 
typedef struct Snake
{
    int hang;//横坐标
    int lie;//纵坐标
    struct  Snake* next;//下一个节点地址
}Snake;
 
struct Snake *head = NULL;
struct Snake *tail = NULL;
int key;
int dir;
 
struct Snake food;
 
 
void initfood();
int hasfood(int i,int j);
int hasSnake(int i,int j);
void initNcurses();
void gamePic();
void addnode();
void initSnake();
void delnode();
int ifsnakedle();
void moveSnake();
void refreshjiemian();
void changgeDir();




void initfood()
{
    int x = rand() % 20;//横坐标
    int y = rand() % 20;//纵坐标
    food.hang = x;
    food.lie = y;
}
 
 
int hasfood(int i,int j)
{
        if(food.hang == i && food.lie == j)
        {
            return 1;
        }
    return 0;
}
 
 
int hasSnake(int i,int j)
{
    struct Snake*p = head;
    while(p != NULL)
    {
        if(p->hang == i && p->lie == j)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}
 
 
void initNcurses()
{
    initscr();
    keypad(stdscr,1);
    noecho();
}
 
 
void gamePic()
{
    int hang;//行
    int lie;//列
    move(0,0);
    //从第0行开始循环
    for(hang = 0;hang<20;hang++)
    {
        if(hang ==0)
        {
            for(lie = 0;lie<20;lie++)
            {
                printw("--");
        }
        printw("\n");
            }
 
//-----------------------------------------------------------------
    if(hang>0 &&hang<=19)
    {
        for(lie = 0;lie<=20;lie++)
        {
            if(lie == 0||lie == 20)
            {
                printw("|");
            }
            //打印蛇的位置
            else if(hasSnake(hang,lie))
                {
                    printw("[]");
                    //打印食物的位置
            }else if(hasfood(hang,lie))
                {
                printw("##");
                }
                else{
                printw("  ");
                }
               }
        printw("\n");
             }
//------------------------------------------------------
 
            if(hang ==19)
    {
        for(lie =0;lie<20;lie++)
        {
            printw("--");
        }
        printw("\n");
        printw("My name is ChenYi   2023.3.2,food,hang =%d food.lie =%d ,key = %d\n ",food.hang,food.lie,key);
            }
        }
}
 
 
void addnode()
{
    //创建新节点
     Snake *new = (Snake*)malloc(sizeof(Snake));
    new->next = NULL;
    
    switch(dir)
    {
        case UP:
            new->hang =tail->hang-1;
            new->lie = tail->lie;
 
            break;
        case DOWN:
            new->hang =tail->hang+1;
            new->lie = tail->lie;
 
            break;
        case LEFT:
            new->hang =tail->hang;
            new->lie = tail->lie-1;
 
            break;
        case RIGHT:
            new->hang =tail->hang;
            new->lie = tail->lie+1;
 
            break;
    }
    //尾巴指向新节点
    tail->next = new;
    tail = new;
}
 
 
//初始化头节点，并赋值
void initSnake()
{
    struct Snake *p;
    dir = RIGHT;     
    //删除节点
    while(head!=NULL)
    {
        //临时变量保存头节点位置
        p = head;
        head = head->next;
        //释放头节点
        free(head);
    }
    //初始化食物函数
    initfood();
    //初始化头节点
    head = (Snake *)malloc(sizeof(Snake));
    //横坐标为2
    head->hang = 2;
    //纵坐标为1
    head->lie  = 1;
    head->next = NULL;
    //让头和尾都指向一个节点
    tail = head;
    //申请3个节点，让蛇初始长度为三
    addnode();
    addnode();
    addnode();
}
 
 
void delnode()
{
    Snake *new;
    new = head;
    head = head->next;
    free(new);
}
 
 
int ifsnakedle()
{
    struct     Snake *p;
    p = head;
    //判断蛇有没有超出边界
    if(tail->hang < 0|| tail->lie == 0 ||tail->hang == 20|| tail->lie == 20 )
    {
        return 1;
    }
    //判断蛇头有没有咬住尾巴
    while(p->next != NULL)
    {
        if(p->hang == tail->hang && p->lie == tail->lie)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}
 

void moveSnake()
{
    //添加新节点
    addnode();
    //如果蛇头坐标和食物坐标一样，说明食物被吃掉了
    if(hasfood(tail->hang,tail->lie))
    {
        //初始话食物，
        initfood();
    }else
    {
        //删除节点
        delnode();
    }
    //判断有没有咬到自己或超出边界
    if(ifsnakedle())
    {        
        //咬到自己或超出边界了，初始化
        initSnake();
    }
}
 

 
void refreshjiemian()
{
    while(1)
    {
            moveSnake();
            gamePic();
            refresh();
            //控制蛇的移动速度，
            usleep(100000);
    }
}
 
 
void trun(int diretction)
{
    if(abs(dir) != abs(diretction))
    {
        dir = diretction;
    }
}
 

 
void changgeDir()
{
    while(1)
    {
        key = getch();
        switch(key)
        {
            case KEY_DOWN:
                trun(DOWN);
                break;
            case KEY_UP:
                trun(UP);
                break;
            case KEY_LEFT:
                trun(LEFT);
                break;
            case KEY_RIGHT:
                trun(RIGHT);
                break;
        }
    }    
}
 
 
int main()
{
    pthread_t t1;
    pthread_t t2;
    
    initNcurses();
 
    initSnake();//初始化创建节点
 
    gamePic();//遍历
 
    pthread_create(&t1,NULL,refreshjiemian,NULL);
 
    pthread_create(&t2,NULL,changgeDir,NULL);
    while(1);
 
    getch();
 
    endwin();
 
    return 0;
}