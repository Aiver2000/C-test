#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
//�ַ�����ת




//
//int str(char s1[], char s2[])
//{
//	char s[1000] = { 0 };
//	strcpy(s, s1);
//	strcat(s, s1);
//	char* ret = strstr(s, s2);
//	if (ret == NULL)
//	{
//		return 0;
//	}
//	return 1;
//
//}
//
//int main()
//{
//	char s1[] = "AABCD";
//	char s2[] = "BCDAA";
//	int ret = str(s1, s2);
//	if (ret == 1)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//}
//


//�ַ�������

//void Left(char c[], int len, int k)
//{
//	k %= len;
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		int j = 0;
//		char tmp = c[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			c[j] = c[j + 1];
//
//		}
//		c[j] = tmp;
//	}
//}
//
//
//int main()
//{
//	char c[] = "ABCDE";
//	int k = 0;
//	printf("�����ַ�������\n");
//	scanf("%d", &k);
//	int len = strlen(c);
//	printf("����ǰ��%s\n", c);
//	Left(c, len, k);
//	printf("������%s\n", c);
//
//	return 0;
//}


//���Ͼ���

//int find_num(int arr[3][3], int row, int col, int k)
//{
//	int x = 0;
//	int y = col - 1;
//	while (x <row && y>=0 )
//	{
//		if (arr[x][y] == k)
//		{
//			printf("�±�Ϊ ��%d %d\n", x, y);
//			return 1;
//		}
//		else if (arr[x][y] > k)
//		y--;
//		else if (arr[x][y] < k)
//		x++;
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int ret = find_num(arr, 3, 3, 7);
//	if (ret == 1)
//		printf("�ҵ���\n");
//	else
//		printf("�Ҳ���\n");
//	return 0;
//}