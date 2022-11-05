#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void Swap(int * p1, int* p2)
{
	int tmp = *p1;
	*p1= *p2;
	*p2 = tmp;
	
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])  //找出两个孩子中大的那一个
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

void HeapSort(int*a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void HpPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
		
	}
	printf("\n");
	
}


void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp&&a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = hp->_capacity = n;
	memcpy(hp->_a, a, sizeof(HPDataType)*n);

	for (int i = (hp->_size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, hp->_capacity*sizeof(HPDataType));
		assert(hp->_a);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);

}
void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 1 : 0;
}
void AdjustUp(int * a, int n, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])   //大堆
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

int * getLeastNumbers(int *a, int arrSize, int k)
{
	if (k == 0)
	{
		return NULL;
	}
	int * arrRet = (int *)malloc(sizeof(int)*k);
	for (int i = 0; i < k; i++)
	{
		arrRet[i] = a[i];
	}

	for (int j = (k - 1 - 1) / 2; j >= 0; j--)
	{
		AdjustDown(arrRet, k, j);
	}
	for (int i = k; i < arrSize; i++)
	{
		if (a[i] < arrRet[0])
		{
			arrRet[0] = a[i];
			AdjustDown(arrRet, k, 0);
		}
	}
	return arrRet;
}

void PrintTopK(int * a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
		
	printf("\n");
}

