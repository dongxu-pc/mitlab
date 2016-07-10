/*************************************************************************
	> File Name: ceil2.c
	> Author: dong xu
	> Mail: gwmxyd@163.com 
	> Created Time: 2016年07月10日 20:06:20
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t iceil2(uint32_t x)
{
	x=x-1;
	x = x | (x>>1);
	x = x | (x>>2);
	x = x | (x>>4);
	x = x | (x>>8);
	x = x | (x>>16);
	return x+1;
}

int main()
{
	int i;
	for(i=1;i<100;i++){
		printf("Ceil2 %d is %d.\n",i,iceil2(i));
	}
	return 0;
}
