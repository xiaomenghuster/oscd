/*
 *function:实现1到100累加
 *author:xiaomeng
 *date:3.8
 */

#include <curses.h>
#include <time.h>

int main(){
	int i=1,sum=0;
	initscr();    //开始curses编程
	while(i<=100){
		clear();
	    move(10,20);	
		printw("i=%d,sum=%d\n\n",i,sum);
		printw("\t\t    %d+%d=%d",i,sum,i+sum);
		sum+=i;
		refresh();
		sleep(3);  //3秒刷新一次
		i++;	   // i递增
	}
    endwin();
	return 0;
}


