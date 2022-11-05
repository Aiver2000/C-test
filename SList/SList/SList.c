#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include "SList.h"

void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


SLTNode* BuySLTNode(SLTDateType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;

	return node;
}


void SListPushBack(SLTNode** pplist, SLTDateType x)
{
	SLTNode* newnode = BuySLTNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}


void SListPushFront(SLTNode** pplist, SLTDateType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPopBack(SLTNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;

		}
		free(tail);
		tail = NULL;

		prev->next = NULL;
	}
}


void SListPopFront(SLTNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		SLTNode* head = *pplist;
		*pplist = (*pplist)->next;
		free(head);
	}
}

SLTNode* SListFind(SLTNode* plist, SLTDateType x)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;

		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SLTNode* pos, SLTDateType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next != NULL)
	{
		SLTNode* next = pos->next;
		SLTNode* nextnext = next->next;
		pos->next = nextnext;
		free(next);
	}

}

