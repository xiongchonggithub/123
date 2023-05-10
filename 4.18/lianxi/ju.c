
#include<curses.h>
#include<stdio.h>
#include <unistd.h>


int main()
{
	
	initscr();

	 move(0,1);
	hline('_',19);
	move(1,0);
	vline('|',10);
	move(10,1);
	hline('_',20);
	move(1,20);
	vline('|',10);
	refresh();
	move(20,20); 
/* 	curs_set(0);
	mvprintw(11, 29, "      #         #");
    mvprintw(12, 28, "        #     #");
    mvprintw(13, 27, "          # #");
    mvprintw(14, 27, "           #");
    mvprintw(15, 28, "          # #");
    mvprintw(16, 29, "        #     #");
    mvprintw(17, 30, "      #         #");
	 refresh();
    sleep(5); */

    endwin();
	//while(1);
	return 0;
}