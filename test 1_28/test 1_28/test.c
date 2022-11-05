#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hello bit \n");
//	}
//
//	return 0;
//}
//

//#include <assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[10] = "qqqqqqqqqq";
//	char arr2[] = "abcdef";
//	char* p2 = arr2;
//	printf("%s\n", my_strcpy(arr1, p2));
//	return 0;
//}

//int my_strlen(char* arr)
//
//{
//	int i = 0;
//	while (*(arr++) != '\0')
//	{			
//		i++;
//	}
//	return i;
//}
//
//
//int main()
//{
//	char arr[] = "abcdefg";
//	printf("%d\n", my_strlen(arr));
//
//}

//void swap(int* arr)
//{
//	int tmp = 0;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			tmp = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = tmp;
//		}
//	}
//	
//}
//
//int main()
//{
//	int i = 0;
//	int arr[20] = {1,2,3,4,5,6,7,8,9,10};
//	//for (i = 0; i < 20; i++)
//	//{
//	//	scanf("%d", arr[i]);
//	//}
//	for (i = 0; i < 10; i++)
//	{
//		swap(arr);
//		printf("%d ",arr[i] );
//	}
//	return 0;
//}

void Depart_Arry(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		while (left < right &&arr[left] % 2 != 0)
		{
			left++;
		}
		while (left < right && arr[right] % 2 == 0)
		{
			right--;
		}

		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}

}

void Print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}

}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Depart_Arry(arr,sz);
	Print(arr, sz);

	return 0;
}