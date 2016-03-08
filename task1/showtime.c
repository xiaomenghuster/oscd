/*
 *function:实时显示当前时间
 *author:xiaomeng
 *date:3.8
 */

#include <curses.h>
#include <time.h>
#define CYCLE 300
#define REFRESH 1

int main(){
	WINDOW *subw;
	int i=CYCLE;
	time_t rawtime;
	struct tm * timeinfo;
	initscr();    //开始curses编程
	subw=newwin(3,COLS,0,0);
	while(i){
		wclear(subw);
	    //move(10,20);	
		time ( &rawtime );  //获取当前秒数
		timeinfo = localtime ( &rawtime );  //转换后存储到结构体中
		//printf ( "The current date/time is: %s", asctime (timeinfo) );
		wprintw(subw,"%d:%d:%d\n",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
		move(LINES-1,0);
		wrefresh(subw);
		sleep(REFRESH);
		i--;
	}
    endwin();
	return 0;
}


