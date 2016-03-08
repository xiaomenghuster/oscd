/*
 *function:用fread、fwrite等库函数实现文件拷贝
 *author:xiaomeng
 *date:3.7
 */
#include <stdio.h>
#define SOURCEFILE "hello.txt"
#define DESTINATIONFILE "hello_ectype.txt"
//#define SOURCEFILE "操作系统课程设计.ppt"
//#define DESTINATIONFILE "操作系统课程设计_ectype.ppt"

int main(){
	char c;
	FILE *fout,*fin;
	fout=fopen(SOURCEFILE,"rb");
	fin=fopen(DESTINATIONFILE,"wb");
	if(fout==NULL|fin==NULL){
		printf("fail to open file!");
		return 0;	
	}
	while(!feof(fout)){
		fread(&c,1,1,fout);
		//putchar(c);
		fwrite(&c,1,1,fin);
	}
	fclose(fout);
	fclose(fin);
	return 0;
}
