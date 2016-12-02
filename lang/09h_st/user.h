/*************************************************************************
	> File Name: user.h
	> Author: dong xu
	> Mail: gwmxyd@163.com 
	> Created Time: 2016年11月29日 星期二 11时33分34秒
 ************************************************************************/

#ifndef __USER_H_
#define __USER_H_

#include "stdio.h"
#include "stdlib.h"

struct user{
	int a;
	int b;
};

int do_user(struct user* u)
{
	if(u == NULL){
		printf("NULL.\n");
		exit(-1);
	}
	u->a = 2;
	u->b = 3;

	return 0;
}

#endif
