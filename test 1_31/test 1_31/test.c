#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d", a + b, c);
//	return 0;
//}
//
//

//杨辉三角
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	int arr[100][100] = { 0 };
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0 || i == j)
//			{
//				arr[i][j] = 1;
//			}
//			else
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//		
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}



//猜凶手

//int main()
//{
//	char killer;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
//		{
//			printf("%c", killer);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 0; a <= 5;a++)
//	for (b = 0; b <= 5;b++)
//	for (c = 0; c <= 5; c++)
//	for (d = 0; d <= 5; d++)
//	for (e = 0; e <= 5; e++)
//	{
//		if (a*b*c*d*e == 120)
//		{
//			if (((b == 2) + (a == 3) == 1) &&
//				((b == 2) + (e == 4) == 1) &&
//				((c == 1) + (d == 2) == 1) &&
//				((c == 5) + (d == 3) == 1) &&
//				((e == 4) + (a == 1) == 1))
//			{
//				printf("%d %d %d %d %d", a, b, c, d, e);
//			}			
//
//		}
//		
//	}
//
//	return 0;
//
//}
//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}

//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//
//int main()
//{
//	if (check_sys() == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	return 0;
//}

//1.输出什么
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	
//	return 0;
//}

//2.输出什么
//int main()
//{
//	char a = -128;
//	printf("%u\n", a);
//	return 0;
//}

//3.输出什么
//int main()
//{
//	char a = 128;
//	printf("%u\n", a);
//	return 0;
//}

//4.输出什么
//int main()
//{
//	int i = -20;
//	unsigned int j = 10;
//	printf("%d\n", i + j);
//	return 0;
//}


//5.输出
//#include <windows.h>
//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//		Sleep(1000);
//	}
//	return 0;
//}

//int main()
//{
//	char a[1000];
//	int i;
//	for (i =0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//
//	}
//	printf("%d", strlen(a));
//	return 0;
//}

unsigned char i = 0;

int main()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");
	}
	return 0;
}