#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//char * my_strstr(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	const char *cp = s1;
//	while (*cp)
//	{
//		const char * p1 = cp;
//		const char * p2 = s2;
//		while ((*p1) && (*p2) && (*p1 == *p2))
//		{
//			p1++;
//			p2++;
//		}
//		if (*p2 == '\0')
//		{
//			return (char *)cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//
//
//
//int main()
//{
//	char arr1[] = "abbcdefghdhi";
//	char arr2[] = "bbcd";
//	char /*ret = my_strstr(arr1, arr2);
//	if (ret != NULL)
//		printf("%s\n", ret);
//	else
//		printf("no find the str");
//	return 0;
//}
//
//
//char * my_strcat(char * dest, const char * src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//	printf("%s\n", my_strcat(arr1, arr2));
//	return 0;
//}

//int my_strcmp(const char *s1, const char*s2)
//{
//	assert(s1 && s2);
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//		{
//			return 0;
//		}
//		s1++;
//		s2++;
//	}
//	return *s1 - *s2;
//}
//
//
//
//int main()
//{
//	int ret = my_strcmp("abc", "abcdef");
//	printf("%d", ret);
//	return 0;
//}

//char* my_strcpy(char * dest, const char* src)
//{
//	assert(dest&&src);
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "*********";
//	char arr2[] = "hello bit";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//size_t my_strlen(const char* str)
//{
//	assert(str);
//	int count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abcdefghigklmnopqrstuvwxyz";
//	printf("%d", my_strlen(arr));
//	return 0;
//}

//void* my_memcpy(void*dest, const void*src,size_t count)
//{
//	void* ret = dest;
//	assert(dest&&src);
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6 };
//	int arr2[20] = { 0 };
//	my_memcpy(arr2, arr1, 16);
//	return 0;
//}

//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	void* ret = dest;
//	assert(dest&&src);
//	if (dest < src)
//	{
//			while (count--)
//			{
//				*(char*)dest = *(char*)src;
//				++(char*)dest;
//				++(char*)src;
//		
//			}
//	}
//	else
//	{
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	my_memmove(arr+2,arr,16);
//	return 0;
//}