/*************************************************************************
	> File Name: 07struct_static.c
	> Author: dong xu
	> Mail: gwmxyd@163.com 
	> Created Time: 2016年11月27日 星期日 21时01分54秒
 ************************************************************************/

#include <stdio.h>

struct test_static{
	//在C语言中没有这种语法,使用#define来替代
	//static const int ok = 0;
#define OK_STU 0
	int fault;
};

int main()
{
	struct test_static ts;

	return 0;
}

