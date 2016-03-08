/*
 *function:编写一个C程序，使用基于文本的终端图形编程库（curses），分窗口显
 *示三个并发进程的运行（一个窗口实时显示当前时间，一个窗口实时检测CPU的利用
 *率，一个窗口做1到100的累加求和，刷新周期分别为1秒，2秒和3秒）
 *author:xiaomeng
 *date:3.7
 */

#include <curses.h>
int main()
{
    initscr();    
    clear();
    move(10,20);
    addstr("hello,world");
    move(LINES-1,0);
    refresh();
    getch();
    endwin();
    return 0;
}
