#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//#define CHANGE(X) (((x&0x55555555)<<1)|((X&0xAAAAAAAA)>>1))
#define offsetof(TYPE,MEMBER) ((size_t)&((TYPE*) 0)->MEMBER)

struct s
{
	char a;
	int b;
	short c;
};
int main()
{
	size_t a =offsetof(struct s, b);
	printf("%d\n", a);
	//int x = 5;
	//printf("%d\n", CHANGE (x));
	
	return 0;
}



