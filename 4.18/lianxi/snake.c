#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct node {
    int x;
    int y;
    struct node *next;
} Node;

typedef struct _snake_head 
{
    int x; // 贪吃蛇头部位置的横坐标
    int y; // 贪吃蛇头部位置的纵坐标
    int direction; // 贪吃蛇移动方向，0-上，1-右，2-下，3-左
} snake_head;

// 定义常量
#define GAME_WIDTH 30
#define GAME_HEIGHT 20
#define INITIAL_SPEED 3
#define SPEED 200000
#define HEAD_COLOR 1
#define SNAKE_COLOR 2
#define FOOD_COLOR 2


// 定义全局变量
int game_score = 0;           // 得分
int game_speed = 0;
int snake_length = 0;    // 蛇的长度
int direction = KEY_RIGHT;  // 蛇头方向
int game_over=0;        // 游戏是否结束
int food_x=0, food_y=0;      // 食物的坐标
int snake_x[GAME_WIDTH * GAME_HEIGHT], snake_y[GAME_WIDTH * GAME_HEIGHT];  // 蛇身的坐标
snake_head snakehead;

//函数声明
void init_game();
void init_game();
void generate_food();
void draw_snake();
void draw_food();
void draw_game();
void update_game();

Node * create_node(int x, int y) 
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}


// 检查蛇头是否撞到了边界
int check_collision(int x, int y) 
{
    if (x < 1 || x > GAME_WIDTH || y < 1 || y > GAME_HEIGHT) 
	{
        return 1; // 碰撞
    } 
	else 
	{
        return 0; // 没有碰撞
    }
}


void init_game() 
{
    // 初始化蛇头和蛇身
    snake_length = create_node(GAME_WIDTH / 2, GAME_HEIGHT / 2);
    direction = 0;

    // 初始化食物
    generate_food();

    // 初始化游戏参数
    game_score = 0;
    game_speed = INITIAL_SPEED;
    game_over = false;
}

void generate_food() 
{
    // 随机生成食物坐标
    do {
        food_x = rand() % GAME_WIDTH;
        food_y = rand() % GAME_HEIGHT;
    } while (check_collision(food_x, food_y));
}

void draw_snake() 
{
    // 绘制蛇头
    attron(COLOR_PAIR(HEAD_COLOR));
    mvprintw(snakehead.y, snakehead.x, "O");
    attroff(COLOR_PAIR(HEAD_COLOR));

    // 绘制蛇身
    Node *current_node = snakehead.direction;
    while (current_node != NULL) 
	{
        attron(COLOR_PAIR(SNAKE_COLOR));
        mvprintw(current_node->y, current_node->x, "o");
        attroff(COLOR_PAIR(SNAKE_COLOR));
        current_node = current_node->next;
    }
}

void draw_food() 
{
    attron(COLOR_PAIR(FOOD_COLOR));
    mvprintw(food_y, food_x, "@");
    attroff(COLOR_PAIR(FOOD_COLOR));
}


void draw_game() 
{
    // 清空屏幕
    clear();

    // 绘制蛇头和蛇身
    draw_snake();

    // 绘制食物
    draw_food();

    // 绘制游戏分数
    mvprintw(0, 0, "Score: %d", game_score);

    // 刷新屏幕
    refresh();
}


void update_game() 
{
    // 计算蛇头的新位置
    int new_x = snake_x[0];
    int new_y = snake_y[0];
    switch (direction) 
	{
        case KEY_LEFT:
            new_x--;
            break;
        case KEY_RIGHT:
            new_x++;
            break;
        case KEY_UP:
            new_y--;
            break;
        case KEY_DOWN:
            new_y++;
            break;
    }

    // 判断是否吃到食物
    if (new_x == food_x && new_y == food_y) 
	{
        // 得分+1
        game_score++;
        // 食物坐标随机生成
        food_x = rand() % GAME_WIDTH;
        food_y = rand() % GAME_HEIGHT;
        // 蛇身长度+1
        snake_length++;
    }

    // 移动蛇的身体
    for (int i = snake_length - 1; i > 0; i--) 
	{
        snake_x[i] = snake_x[i - 1];
        snake_y[i] = snake_y[i - 1];
    }

    // 更新蛇头位置
    snake_x[0] = new_x;
    snake_y[0] = new_y;

    // 判断是否游戏结束
    if (snake_x[0] < 0 || snake_x[0] >= GAME_WIDTH || snake_y[0] < 0 || snake_y[0] >= GAME_HEIGHT) 
	{
    // 蛇头碰到墙壁，游戏结束
		game_over = 1;
		
		for (int i = 1; i < snake_length; i++)
		{
			if (snake_x[0] == snake_x[i] && snake_y[i] == snake_y[i]) 
			{
				// 蛇头碰到自身身体，游戏结束
				game_over = 1;
				break;
			}
		}
	}
}



int main()
{
	init_game();
	while(1)
	{
		draw_game();
		
		update_game();
		usleep(100000);
		if(game_over==1)
		{
			break;
		}
		
	} 

	endwin();
	return 0;
}
