/*
 *function:实时监测CPU的利用率
 *author:xiaomeng
 *date:3.8
 */


#include <curses.h>
#include <time.h>
#define FILEPATH "/proc/stat"
#define INTERVAL 1
#define REFRESH 2
#define CYCLE 150
int main(){
	WINDOW *subw;
	int i,j=0;
	int stat[10];
	int total1,total2,idle1,idle2;
	float usage;
	char cpu[5]; //存放文件开头的cpu字符
	FILE *file;
	initscr();    //开始curses编程
	subw=newwin(10,COLS,5,0);

	while(j<CYCLE){
		total1=total2=0;
		wclear(subw);
		file=fopen(FILEPATH,"r");
		fscanf(file,"%s",cpu);
		wprintw(subw,"%s  ",cpu);
		//wprintw(subw,"hello");
		for(i=0;i<10;i++){
			fscanf(file,"%d",&stat[i]);
			wprintw(subw,"%d    ",stat[i]);
			fgetc(file);
		}
		for(i=0;i<10;i++){
			total1+=stat[i];
		}   			//accumulate to total;
		idle1=stat[3];  //idle is the fourth number;
		wprintw(subw,"\n");
		//wrefresh(subw);	
		//第二次取值
		sleep(INTERVAL);   //时间间隔
		rewind(file);  //将文件内部的位置指针重新指向流的开头
		fscanf(file,"%s",cpu);
		wprintw(subw,"%s  ",cpu);
		for(i=0;i<10;i++){
			fscanf(file,"%d",&stat[i]);
			wprintw(subw,"%d    ",stat[i]);
			//fgetc(file);
		}
		for(i=0;i<10;i++){
			total2+=stat[i];
		}   			//accumulate to total;
		idle2=stat[3];  //idle is the fourth number;
		wprintw(subw,"\n");
		//calc the usage;
		usage=(float)(total2-total1-(idle2-idle1))/(total2-total1)*100;
		wprintw(subw,"total=%d\n",total2-total1);
		wprintw(subw,"idle=%d\n",idle2-idle1);
		wprintw(subw,"cpu use: %.2f%%\n",usage);
		wrefresh(subw);
		sleep(REFRESH);
		j++;
		fclose(file);
	}
    endwin();
	return 0;
}



/*
1、 采样两个足够短的时间间隔的Cpu快照，分别记作t1,t2，其中t1、t2的结构均为：

(user、nice、system、idle、iowait、irq、softirq、stealstolen、guest)的9元组;

2、 计算总的Cpu时间片totalCpuTime

a) 把第一次的所有cpu使用情况求和，得到s1;

b) 把第二次的所有cpu使用情况求和，得到s2;

c) s2 - s1得到这个时间间隔内的所有时间片，即totalCpuTime = j2 - j1 ;

3、计算空闲时间idle

idle对应第四列的数据，用第二次的第四列 - 第一次的第四列即可

idle=第二次的第四列 - 第一次的第四列

6、计算cpu使用率

pcpu =100* (total-idle)/total

*/

