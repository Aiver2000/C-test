//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			printf("%d ", i);
//		}
//
//	}
//}
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//		{
//			continue;
//		}
//		printf("%d", i);
//		i++;
//	}
//
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int ret = 1;
//	int m = 0;
//	int n = 0;
//	
//	for (n = 1; n<=3; n++)
//	{
//		ret *= n;
//		m += ret;
//	}
//	printf("%d\n", m);
//	return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	int n = 0;
//	
//	scanf("%d %d %d", &i, &k, &j);
//
//	if (i < j)
//	{
//		n = j;
//		j = i;
//		i = n;
//	}
//	if (i < k)
//	{
//		n = k;
//		k = i;
//		i = n;
//	}
//	if (j < k)
//	{
//		n = k;
//		k = j;
//		j = n;
//	}
//	printf("%d %d %d\n", i, j, k);
//
//		
//
//	return 0;
//}
//int main()
//{
//
//	int i = 0;
//	for (i = 3; i < 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int n = 0;
//	int i = 0;
//	scanf("%d %d\n", &a, &b);
//	if (a > b)
//	{
//		n = a;
//		a = b;
//		b = n;
//	}
//	for (i = a; i > 0; i--)
//	{
//		if ((a % i == 0) && (b % i == 0))
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//
//
//	return 0;
//}
//
//int main()
//{
//
//
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
//	//շת�����
//	while (c = a%b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d\n", b);
//	return 0;
//}		
//int main()
//{
//	int i = 0;
//	for (i = 1000; i < 2001; i++)
//	{
//		if ((i % 400 == 0) || (i % 4 == 0) && (i % 100 != 0))
//		{
//			printf("\t%d", i);
//		}
//
//	}
//
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{	
//	for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			printf("%d ", i);
//		}
//
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int n = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			n++;
//		}
//		if (i / 10 == 9)
//		{
//			n++;
//		}
//		
//	}
//	printf("%d", n);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	double sum = 0;
//
//	for (i = 1; i < 100; i +=2)
//	{
//		sum += 1.0 / i;
//	}
//	for (j = 2; j <= 100; j += 2)
//	{
//		sum -= 1.0 / j;
//	}
//	printf("%lf", sum);
//
//
//}
//int main()
//{
//	int max = 0;
//	int arr[10] = { 0 };
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (arr[i]>max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d", max);
//
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <=9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("\t%d*%d=%d", i,j,i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int k = 7;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±���:%d\n", mid);
//			break;
//		}
//	}
//	if (left>right)
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//
//}