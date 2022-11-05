#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//¾²Ì¬Ë³Ðò±í
//#define N 100
//struct SeqList
//{
//	int a[N];
//	int size;
//};

typedef int SeqDataType;

typedef struct SeqList
{
	SeqDataType* a;
	int size;
	int capacity;
}SeqList,SEQ;

void SeqListInit(SeqList* pq);
void SeqListDestory(SeqList* pq);

void SeqListPrint(SeqList* pq);

void SeqListPushBack(SeqList* pq, SeqDataType x);
void SeqListPushFront(SeqList* pd, SeqDataType x);

void SeqListPopFront(SeqList* pq);
void SeqListPopBack(SeqList* pq);

void SeqListInsert(SeqList* pq, size_t pos, SeqDataType x);

void SeqListErase(SeqList* pq, size_t pos);

int SeqListFind(SeqList* pq, SeqDataType x);
