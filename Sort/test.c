#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"


void TestInsertSort()
{
	int a[] = { 4, 3, 7, 1, 9, 8, 4, 3, 5 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestShellSort()
{
	int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int *)malloc(sizeof(int)*N);
	int* a2 = (int *)malloc(sizeof(int)*N);
	int* a3 = (int *)malloc(sizeof(int)*N);
	int* a4 = (int *)malloc(sizeof(int)*N);
	int* a5 = (int *)malloc(sizeof(int)*N);
	int* a6 = (int *)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];		
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("InsertSort:%d\n", end2 - begin2);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	


}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	TestOP();
	return 0;
}


