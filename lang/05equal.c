/*************************************************************************
	> File Name: 05equal.c
	> Author: dong xu
	> Mail: gwmxyd@163.com 
	> Created Time: 2016年11月10日 星期四 09时23分28秒
 ************************************************************************/

#include<stdio.h>

int main()
{
	int a = 0;
	int b;

	if(0 == (a=b))
		printf("ZERO\n");
	else
		printf("Non-Zero.\n");

	return 0;
}
