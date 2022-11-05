#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>


//int is_prime(int n)
//{
//	int i = 0;
//	int flag = 1;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0)
//		{
//			flag = 0;
//			break;
//		}
//	}
//	return flag;
//}

//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//int binary_search(int arr[], int k,int sz )
//{	
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid]>k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//			
//		}
//	}
//	return -1;
//
//
//}
//int main()
//{
//	//有序的
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 7;
//	//二分查找的
//	//找到了，返回下标
//	//找不到，返回 -1
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, k, sz );
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//
//	return 0;
//}
//




//判断素数


//int is_prime(int i)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(i); j++)
//	{
//		if (i%j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//	
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 101; i <= 200; i += 2)
//
//	{
//		int ret = is_prime(i);
//		if (ret == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}



//判断是否为闰年

//int is_leap_year(int i)
//{
//	if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	
//	int i = 0;
//	
//	for (i = 1000; i <= 2000; i++)
//	{
//		int ret = is_leap_year(i);
//		if (ret == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	
//
//	return 0;
//}



//交换两个整数

//void swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	swap(&a,&b);
//	printf("%d %d", a, b);
//	return 0;
//}

//函数实现二分查找

//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	
//	while (left <= right)
//
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//
//	}
//	return -1;
//	
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 7;
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到");
//	}
//	else
//	{
//		printf("%d", ret);
//	}
//	return 0;
//}

//void chengfabiao(int a)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= a; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d\t", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int a = 0;
//	//int b = 0;
//	scanf("%d", &a);
//	chengfabiao(a);
//	return 0;
//}