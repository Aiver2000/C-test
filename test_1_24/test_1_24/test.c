#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//冒泡排序
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	int flag = 1;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag = 1)
//			break;
//	}
//	
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[10] = { 1, 0, 2, 3,4, 5, 6, 7, 8, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	print_arr(arr, sz);
//	return 0;
//}
//
//
//*****************************************************************************************
//数组操作


//void init(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//}
//
//void reverse(int arr[], int sz)
//{
//	int tmp = 0;
//	int left = 0;
//	int right = sz - 1;
//	
//	while (left < right)
//	{
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//		
//	}
//}
//
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//init(arr,sz);
//	//print(arr,sz);
//	reverse(arr, sz);
//	print(arr, sz);
//	return 0;
//}



//交换数组A和数组B中的内容

//void swaparr(int arrA[], int arrB[],int sz)
//
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arrA[i];
//		arrA[i] = arrB[i];
//		arrB[i] = tmp;
//		
//	}
//}
//
//void printarr(int arrA[], int arrB[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ",arrA[i]);
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arrB[i]);
//	}
//}
//int main()
//{
//	
//	int arrA[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int arrB[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arrA) / sizeof(arrA[0]);
//	swaparr(arrA, arrB,sz);
//	printarr(arrA, arrB,sz);
//	return 0;
//}