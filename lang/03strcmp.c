/*************************************************************************
	> File Name: 03strcmp.c
	> Author: dong xu
	> Mail: gwmxyd@163.com 
	> Created Time: 2016年11月02日 星期三 20时23分51秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char * a = "coust";
	char * b = "cou";
	const char *c = NULL;
	printf("compare coust and cou :%d\n",strcmp(a,b));
	printf("next:%d\n",'s');
	c = a;
	printf("%s\n",c);
	

	return 0;
}

