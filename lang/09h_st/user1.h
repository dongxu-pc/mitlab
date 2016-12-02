/*************************************************************************
	> File Name: user1.h
	> Author: dong xu
	> Mail: gwmxyd@163.com 
	> Created Time: 2016年11月29日 星期二 11时36分04秒
 ************************************************************************/

#ifndef __USER_1_H__
#define __USER_1_H__

#include "user.h"

struct userb{
	int a;
	int b;
};

void do_userb(struct userb *ub,struct user* ua)
{
	ub->a = ua->a;
	ub->b = ua->b;
}

#endif

