/*
 *function:实时监测CPU的利用率
 *author:xiaomeng
 *date:3.8
 */


#include <curses.h>
#include <time.h>
#define FILEPATH "/proc/stat"
#define INTERVAL 1
int main(){
	int i;
	int stat[10];
	int total1=0,total2=0,idle1,idle2;
	float usage;
	char cpu[5]; //存放文件开头的cpu字符
	FILE *file;
	file=fopen(FILEPATH,"r");
	fscanf(file,"%s",cpu);
	printf("%s  ",cpu);
	for(i=0;i<10;i++){
		fscanf(file,"%d",&stat[i]);
		printf("%d\t",stat[i]);
		fgetc(file);
	}
	for(i=0;i<10;i++){
		total1+=stat[i];
	}   			//accumulate to total;
	idle1=stat[3];  //idle is the fourth number;
	printf("\n");
	//第二次取值
	sleep(INTERVAL);   //时间间隔
	rewind(file);  //将文件内部的位置指针重新指向流的开头
	fscanf(file,"%s",cpu);
	printf("%s  ",cpu);
	for(i=0;i<10;i++){
		fscanf(file,"%d",&stat[i]);
		printf("%d\t",stat[i]);
		fgetc(file);
	}
	for(i=0;i<10;i++){
		total2+=stat[i];
	}   			//accumulate to total;
	idle2=stat[3];  //idle is the fourth number;
	printf("\n");
	fclose(file);
	//calc the usage;
	//usage=(total2-total1-(idle2-idle1))/(total2-total1);
	usage=(float)(total2-total1-(idle2-idle1))/(total2-total1)*100;
	printf("total=%d\n",total2-total1);
	printf("idle=%d\n",idle2-idle1);
	printf("cpu use: %.2f%%\n",usage);
	/*initscr();    //开始curses编程
	while(i<=10){
		clear();
	    move(10,20);	
		
		refresh();
		sleep(2);
		i--;
	}
    endwin();*/
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

