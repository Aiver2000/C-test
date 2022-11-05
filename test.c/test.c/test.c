//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
////#include <math.h>
//
////int main()
////{
////	
////	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
////	int * p = arr;
////	int i = 0;
////	for (i = 0; i < 10; i++)
////	{
////		
////		printf("%d ", *(p + i));
////	}
////
////	return 0;
////}
////
////
////#include <string.h>
////#include <stdio.h>
////int main()
////{
////	
////	char arr[100] ;
////	int i = 0;
////	gets(arr);
////	for (i = strlen(arr) - 1; i >= 0; i--)
////	{
////		putchar(arr[i]);
////	}
////
////	return 0;
////}
//
//
////
////int main()
////{
////	int a = 0;
////	int i = 0;
////	int n = 0;
////	int Sn = 0;
////	scanf("%d", &a);
////	for (i = 0; i < 5; i++)
////	{
////		
////		n = n * 10 + a;
////		Sn += n;
////		
////	}
////	printf("%d", Sn);
////	return 0;
////}
//
//
////int main()
////{
////	int i = 0;
////	int j = 0;
////	int a = 0;
////	int n = 0; 
////	int m = 0;
////	int sum = 0;
////	
////	for (a = 0;  a<= 100000; a++)
////	{
////		while (n )
////		{
////			n = a;
////			n /= 10;
////			i++;
////		}
////		while (a)
////		{
////			m = a % 10;
////			a = a / 10;
////			sum += pow(m, i);
////		}
////		if (a == sum)
////		{
////			printf("%d ", a);
////		}
////	}
////
////	return 0;
////}
//
//
//
//
////#include <stdio.h>
////
////#include <math.h>
////
////int main()
////{
////	int i = 0;
////	for (i = 1; i <= 99999; i++)
////	{
////		int tmp = i;
////		int count = 0;
////		int sum = 0;
////
////		while (tmp)
////		{
////			tmp /= 10;
////			count++;
////		}
////		tmp = i;
////		while (tmp)
////		{
////			sum += pow((tmp % 10), count);
////			tmp /= 10;
////		}
////		if (sum == i)
////		{
////			printf("%d是水仙花数\n", i);
////		}
////	}
////	return 0;
////}
//
//
////int main()
////{
////	int i = 0;
////	int j = 0;
////	for (i = 0; i < 6; i++)
////	{
////		for (j = 0; j < 6-i;j++)
////		{
////			printf(" ");
////		}
////		for (j = 0; j <2*i+1 ;j++)
////		{
////			printf("*");
////		}
////		printf("\n");
////	}
////	for (i = 0; i < 7; i++)
////	{
////		for (j = 0; j < i; j++)
////		{
////			printf(" ");
////		}
////		for (j = 0; j < 13 - 2 * i; j++)
////		{
////			printf("*");
////		}
////		printf("\n");
////	}
////	return 0;
////
////}
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//
//	scanf("%d", &money);
//	total = money;
//	empty = money;
//	while (empty > 1)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//
//	}
//	printf("%d", total);
//	return 0;
//}