#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
//
//
//
//
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//
//
//
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age- ((struct Stu*)e2)->age;
//}
//
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//
//
//
//void _swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
//
//bubble_sort(void* base, size_t sz, size_t width, int(*cmp)(const void* e1, const void* e2))
//{
//	size_t i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		size_t j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
//			{
//				_swap((char*)base + j*width, (char*)base + (j + 1)*width,width);
//			}
//		}
//	}
//}
//
//
//
//void test1()
//{
//	int arr[] = { 1, 5, 2, 4, 3, 9, 8, 6, 7, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//
//}
//
//
//
//
//
//void test2()
//{
//	struct Stu arr[] = { { "zhangsan", 20 }, { "lisi", 31 }, {"wangwu",15} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);
//	
//}
//
//
//
//int main()
//{
//	test1();//整形排序
//	test2();//结构体排序
//	return 0;
//}
//
//
//struct Stu
//{
//	char name[20];
//	int age;
//
//};
//int cmp_int(const void* x, const void* y)
//{
//	return *((int*)x) - *((int*)y);
//
//}
//
//int cmp_char(const void* x, const void* y)
//{
//	return *((char*)x) - *((char*)y);
//}
//
//int cmp_str(const void*x, const void* y)
//{
//	return strcmp(*(char **)x, *(char **)y);
//}
//
//
//int cmp_f(const void * x, const void * y)
//{
//	return *((double*)x) - *((double*)y);
//}
//
//int cmp_stu_age(const void * x, const void *y)
//{
//	return ((struct Stu *)x)->age - ((struct Stu *)y)->age;
//}
//
//int cmp_stu_name(const void *x, const void *y)
//{
//	return strcmp(((struct Stu*)x)->name, ((struct Stu*)y)->name);
//}
//
//void test1()
//{
//	int i = 0;
//	int arr[] = { 0, 9, 7, 5, 4, 1, 3, 2, 6, 8 };
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_int);
//	for (i = 0; i <sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void test2()
//{
//	int i = 0;
//	char arr[] = { 'a', 'c', 'f', 'e', 'W', 'D', 'A', 'G', 'L' };
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_char);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	printf("\n");
//
//	
//}
//
//void test3()
//{
//	int i = 0;
//	char* str[] = { "nnn", "ooo", "aaa", "bbb", "AAA", "CCC" };
//	qsort(str, sizeof(str) / sizeof(*str), sizeof(*str), cmp_str);
//	for (i = 0; i < sizeof(str) / sizeof(*str); i++)
//	{
//		printf("%s ", str[i]);
//	}
//	printf("\n");
//
//
//}
//
//void test4()
//{
//	int i = 0;
//	double arr[] = {4.4,6.3,9.0,0.2,0.4};
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_f);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%lf ", arr[i]);
//
//	}
//	printf("\n");
//}
//
//void test5()
//{
//	struct Stu arr[] = { { "zhangsan", 10 }, { "lisi", 11 }, { "wangwu", 12 } };
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_stu_age);
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_stu_name);
//
//}
//
//int main()
//{
//	
//	test1();//整形数组
//	test2();//字符数组
//	test3();//字符串
//	test4();//浮点数
//	test5();//结构体
//
//	return 0;
//}