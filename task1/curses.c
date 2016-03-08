/*
 *function:编写一个C程序，使用基于文本的终端图形编程库（curses），分窗口显
 *示三个并发进程的运行（一个窗口实时显示当前时间，一个窗口实时检测CPU的利用
 *率，一个窗口做1到100的累加求和，刷新周期分别为1秒，2秒和3秒）
 *author:xiaomeng
 *date:3.7
 */

#include <curses.h>
#include <pthread.h>

pid_t pid1,pid2,pid3;

int main()
{
    if((pid1=fork())==0){
		execv("./showtime",NULL);
	}
	else {	
		if((pid2=fork())==0)
			execv("./showcpu",NULL);
		else{ 
			if((pid3=fork())==0)
				execv("./accumulate",NULL);		
		}
	}
	wait(NULL);
	wait(NULL);
	wait(NULL);
    return 0;
}
