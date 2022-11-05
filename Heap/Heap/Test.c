#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
test1()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	Heap hp;
	int n = sizeof(a) / sizeof(a[0]);
	HeapCreate(&hp, a, n);
	HpPrint(&hp);
	HeapPush(&hp, 20);
	HpPrint(&hp);
	HeapPop(&hp);
	HpPrint(&hp);



	HeapDestory(&hp);
}



void TestTopk()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(a) / sizeof(a[0]);
	int * topk = getLeastNumbers(a, n,5);
    PrintTopK(topk, 5);

}

int main()
{
	TestTopk();
	return 0;
}