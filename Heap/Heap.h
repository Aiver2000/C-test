#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int  HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapCreate(Heap* hp, HPDataType* a, int n);

void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
void AdjustUp(int * a, int n, int child);
void HpPrint(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
void AdjustDown(int * a, int n, int parent);

void HeapSort(int*a, int n);

int * getLeastNumbers(int *a, int arrSize, int k);

void PrintTopK(int * a, int n);


