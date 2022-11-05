#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//#define INT_MAX 0X7FFFFFFF
//#define INT_MIN 0X80000000
#include <assert.h>
////模拟实现atoi
//
//
//
////模拟实现 atoi
////int atoi( const char *string );
////需要考虑情况5种：1.空指针 2.空字符串 3.空白字符 4.正负号 5.溢出（正负）
//
//enum Status
//{
//	VALID,//合法
//	INVALID//非法
//}; //检测状态值，只有一种情况为合法，其他均为非法，所以最开始最好初始化为非法
//
//enum Status status = INVALID;
//int my_atoi(const char* str)
//{
//	int flag = 1;//标记正负数
//	long long ret = 0;//要判断是否溢出，若定义为int则永远也不可能溢出
//	assert(str);//1.空指针
//
//	if (*str == '\0')//2.空字符串
//	{
//		return 0;
//	}
//	//3.空白字符
//	while (isspace(*str))
//	{
//		str++;
//	}
//	//4.+-
//	if (*str == '+')
//	{
//		str++;
//	}
//	if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	//正常字符
//	while (*str)
//	{
//		if (isdigit(*str))//1234a5 输出1234
//		{
//			ret = ret * 10 + flag*(*str - '0');
//			if (ret > INT_MAX || ret < INT_MIN)
//			{
//				if (flag == 1)
//				{
//					return INT_MAX;
//				}
//				else
//				{
//					return INT_MIN;
//				}
//			}
//		}
//		else
//		{
//			return ret;
//		}
//		str++;
//	}
//
//	status = VALID;
//	return (int)ret;
//}
//
//
//int main()
//{
//	char* str = "-123456";
//	int tmp = my_atoi(str);
//	printf("%s", str);
//	return 0;
//}
#include <string.h>

//char* My_Strncat(char* dest, char* src, size_t len)
//{
//	assert(dest&&src);
//	char* ret = dest;
//	int offset = 0;
//	while (*dest)
//	{
//		*dest++;
//	}
//	if (strlen(src) < len)
//	{
//		len = strlen(src);
//	}
//	while (len--)
//	{
//		*dest++ = *src++;
//	}
//
//	*dest = '\0';
//	return ret;
//}
//
//int main()
//{
//	char arr1[6] = "World";
//	char arr2[15] = "Hello ";
//	printf("%s\n", My_Strncat(arr2, arr1, 9));
//	return 0;
//}

//char* My_Strncpy(char* dest, const char* src, size_t n)
//{
//	assert(dest&&src);
//	char* ret = dest;
//	while (n--)
//	{
//		*dest++ = *src++;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "123456789";
//	char arr2[20] = "abcde";
//	printf("%s", My_Strncpy(arr1, arr2, 3));
//	return 0;
//}


void Find(int a[], int sz)
{
	int i = 0;
	int num1 = 0;
	int num2 = 0;
	int num = 0;
	int flag = 0;
	for (i = 0; i < sz; i++)
	{
		num = num^a[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) != 1)
		{
			flag++;
		}
		else 
			break;
	}

	for (i = 0; i < sz; i++)
	{
		if (((a[i] >> flag) & 1) == 1)
		{
			num1 ^= a[i];
		}
		else
		{
			num2 ^= a[i];
		}
	}
	printf("%d %d\n", num1, num2);
}


int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int sz = sizeof(a) / sizeof(a[0]);
	Find(a, sz);
	return 0;
}