#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

void swap(int a, int b)
{
	/*int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
	printf("%d %d", a, b);*/
	//a = a + b;
	//b = a - b;
	//a = a - b;
	a = a^b;
	b = a^b;
	a = a^b;
printf("%d %d \n", a, b);


}

int main()
{
	int a = 10;
	int b = 20;
	printf("%d %d \n", a, b);
	swap(a, b);
	return 0;
}
