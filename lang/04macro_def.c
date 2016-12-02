/*************************************************************************
	> File Name: 04macro_def.c
	> Author: dong xu
	> Mail: gwmxyd@163.com 
	> Created Time: 2016年11月09日 星期三 21时46分42秒
 ************************************************************************/

#include <stdio.h>

//#define DEBUG 1
#define DEBUG

int main()
{
#ifdef DEBUG
	printf("Debug:ifdef works.\n");
#endif
	return 0;
}

