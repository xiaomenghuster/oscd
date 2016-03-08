/*
 *function:实现1到100累加
 *author:xiaomeng
 *date:3.8
 */

#include <curses.h>
#include <time.h>
#define REFRESH 3

int main(){
	WINDOW *subw;
	int i=1,sum=0;
	initscr();    //开始curses编程
	subw=newwin(3,COLS,15,0);
	while(i<=100){
		wclear(subw);
	    //move(10,20);	
		wprintw(subw,"i=%d,sum=%d\n\n",i,sum);
		wprintw(subw,"%d+%d=%d",i,sum,i+sum);
		sum+=i;
		wrefresh(subw);
		sleep(REFRESH);  //3秒刷新一次
		i++;	   // i递增
	}
    endwin();
	return 0;
}


