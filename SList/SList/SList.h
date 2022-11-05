#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDateType;


typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;


void SListPrint(SLTNode* plist);

void SListPushBack(SLTNode** pplist, SLTDateType x);
void SListPushFront(SLTNode** pplist, SLTDateType x);

void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);

SLTNode* SListFind(SLTNode* plist, SLTDateType x);

void SListInsertAfter(SLTNode* pos, SLTDateType x);
void SListEraseAfter(SLTNode* pos);

