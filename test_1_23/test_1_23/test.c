#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



//求数字的每一位

//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n%10);
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	print(a);
//	return 0;
//}


//递归求阶乘
//int fac(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n*fac(n - 1);
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("%d", ret);
//	return 0;
//}


//非递归求阶乘
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int sum = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	printf("%d", sum);
//	return 0;
//}



//srtlen 递归实现
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(&arr);
//	printf("%d", len);
//	return 0;
//}



//非递归实现strlen
//int my_strlen(char* str)
//
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//
//	return count;
//	
//
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(&arr);
//	printf("%d", len);
//	return 0;
//}

//递归实现字符串逆序
//char reverse_string(char* string)
//{
//	
//	if (*string)           //while (*string != '\0')
//	{
//		reverse_string(string + 1);
//		printf("%c", *string);
//		
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(&arr);
//	return 0;
//}


//计算每位之和

//int DigitSum(int n)
//{
//	int sum = 0;
//	int a = 0;
//	if (n != 0) 
//	{
//		 a = n % 10;		
//		sum = a+DigitSum(n / 10);
//	}
//	return sum;
//	
//}
//
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = DigitSum(a);
//	printf("%d", ret);
//	return 0;
//}


//递归实现n的k次方
//int my_pow(int n, int k)
//{
//	int sum = 1;
//	if (k  > 0)
//	{
//		sum = n*my_pow(n, k - 1);
//	}
//	return sum;
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	int ret = my_pow(n, k);
//	printf("%d", ret);
//	return 0;
//}

//递归求fib数列
//int count = 0;
//
//int fib(int n)
//{
//
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//
//}
//
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	int ret = fib(n);
//	printf("%d", ret);
//	return 0;
//}


//非递归fib数列
//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fib(n);
//	printf("%d", ret);
//	return 0;
//}


//hanoi ----
//void move(char x, char y)
//{
//	printf("%c-->%c", x, y);
//}
//
//void hanoi(int n, char a, char b, char c)
//{
//	if (n == 1)
//		move(a, c);
//	else
//	{
//		hanoi(n - 1, a, c, b);
//		printf("\n");
//		move(a, c);
//		printf("\n");
//		hanoi(n - 1, b, a, c);
//		printf("\n");
//
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	hanoi(n, 'A', 'B', 'C');
//	return 0;
//}