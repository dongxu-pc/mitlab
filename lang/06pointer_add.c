/*************************************************************************
	> File Name: 06pointer_add.c
	> Author: dong xu
	> Mail: gwmxyd@163.com 
	> Created Time: 2016年11月19日 星期六 21时16分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdint.h>

struct ball{
	char a;
	int b;
	void* c;
};

int main()
{
	char *cp;
	int *ip;
	uint8_t *ucp;
	long *lp;
	uint32_t *u32ip;
	void *vp;
	struct ball *sbp;
	uintptr_t prp;

	cp = (char *)malloc(sizeof(32));
	ip = (int*)cp;
	ucp = (uint8_t*)cp;
	lp = (long*)cp;
	u32ip = (uint32_t *)cp;
	sbp = (struct ball*)cp;
	vp = (void*)cp;
	prp = (uintptr_t)cp;

	printf("sizeof(char):%d:%p -> %p\n",sizeof(char),cp,cp+1);
	printf("sizeof(int):%d:%p -> %p\n",sizeof(int),ip,ip+1);
	printf("sizeof(uint8_t):%d:%p -> %p\n",sizeof(uint8_t),cp,ucp+1);
	printf("sizeof(long):%d:%p -> %p\n",sizeof(long),lp,lp+1);
	printf("sizeof(uint32_t):%d:%p -> %p\n",sizeof(uint32_t),u32ip,u32ip+1);
	printf("sizeof(void):%d:%p -> %p\n",sizeof(void),vp,vp+1);
	printf("sizeof(uintptr_t):%d:%d -> %d\n",sizeof(uintptr_t),prp,prp+1);
	printf("sizeof(struct ball):%d:%p -> %p\n",sizeof(struct ball),sbp,sbp+1);

	return 0;
}
