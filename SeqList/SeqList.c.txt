#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SeqList* pq)
{
	assert(pq);
	pq->a = NULL;
	pq->size = pq->capacity = 0;
}

void SeqListDestory(SeqList* pq)
{
	assert(pq);
	free(pq->a);
	pq->a = NULL;
	pq->capacity = pq->size = 0;
}

void SeqListPrint(SeqList* pq)
{
	assert(pq);
	for (int i = 0; i < pq->size; i++)
	{
		printf("%d ",pq->a[i]);
	}
	printf("\n");
}

void SeqCheckCapacity(SeqList* pq)
{
	if (pq->size == pq->capacity)
	{
		int newcapacity = pq->capacity == 0 ? 4 : pq->capacity * 2;
		SeqDataType* newA = realloc(pq->a, sizeof(SeqDataType)*newcapacity);
		if (newA == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		pq->a = newA;
		pq->capacity = newcapacity;
	}
}


void SeqListPushBack(SeqList* pq, SeqDataType x)
{
	assert(pq);

	SeqCheckCapacity(pq);

	pq->a[pq->size] = x;
	pq->size++;
}

void SeqListPushFront(SeqList* pq, SeqDataType x)
{
	assert(pq);

	SeqCheckCapacity(pq);

	int end = pq->size - 1;
	while (end >= 0)
	{
		pq->a[end + 1] = pq->a[end];
		--end;
	}
	pq->a[0] = x;
	pq->size++;
}

void SeqListInsert(SeqList* pq, size_t pos, SeqDataType x)
{
	assert(pq);
	SeqCheckCapacity(pq);
	size_t end = pq->size;
	if (pos == end)
	{
		pq->a[pos] = x;
		pq->size++;
	}
	else if (pos < pq->size)
	{
		size_t i = pq->size;
		while (pos <=i)
		{
			pq->a[i] = pq->a[i - 1];
			i--;
		}
		pq->a[pos-1] = x;
		pq->size++;
	}
}


void SeqListErase(SeqList* pq, size_t pos)
{
	assert(pq);
	if (pos == pq->size)
	{
		pq->size--;
	}
	else if (pos < pq->size)
	{
		size_t i = pos;
		while (i < pq->size)
		{
			pq->a[i-1 ] = pq->a[i];
			i++;
		}
		pq->size--;
	}
}

void SeqListPopFront(SeqList* pq)
{
	assert(pq);

	size_t i =0;
	for ( i = 0; i < pq->size; i++)
	{
		pq->a[i] = pq->a[i + 1];
	}
	pq->size--;
}

void SeqListPopBack(SeqList* pq)
{
	assert(pq);

	pq->size--;
}

int SeqListFind(SeqList* pq, SeqDataType x)
{
	assert(pq);

	size_t i = 0;
	while (i < pq->size)
	{
		if (pq->a[i] == x)
		{
			return i + 1;
		}
		else
			i++;
	}
	return -1;

}