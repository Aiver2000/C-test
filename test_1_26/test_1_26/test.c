#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	//odd
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", ((a >> i) & 1));
//	}
//	printf("\n");
//	//even
//	for (i = 32; i > 1; i -= 2)
//	{
//		printf("%d ", ((a >> i) & 1));
//	}
//	return 0;
//}
//
//


//统计1 的 个数
//1
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int count = 0;
//	while (num)
//	{
//		if (num & 1)
//		{
//			count++;
//		}
//		num >>= 1;
//	}
//	printf("%d", count);
//	return 0;
//}

//2
int main()
{
	int num = 0;
	scanf("%d", &num);
	int count = 0;
	while (num)
	{
		count++;
		num = num&(num - 1);
	}
	printf("%d", count);
	return 0;
}