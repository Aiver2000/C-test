#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

ListNode* BuyListNode(LTDateType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}


ListNode* ListCreate()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;

}

void ListPushBack(ListNode* pHead, LTDateType x)
{
	assert(pHead);
	ListNode* tail = pHead->prev;
	ListNode* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->next = pHead;
	newnode->prev = tail;
	pHead->prev = newnode;
}

void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

}
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(pHead);
	pHead = NULL;
}


void ListPushFront(ListNode* pHead, LTDateType x)
{
	assert(pHead);
	ListNode* first = pHead->next;
	ListNode* newnode = BuyListNode(x);
	pHead->next = newnode;
	newnode->prev = pHead;
	newnode->next = first;
	first->prev = newnode;
}


void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	ListNode* first = pHead->next;
	ListNode* second = first->next;
	free(first);
	pHead->next = second;
	second->prev = pHead;
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListNode* tail = pHead->prev;
	ListNode* tailPrev = tail->prev;
	free(tail);
	tailPrev->next = pHead;
	pHead->prev = tailPrev;
}


ListNode* ListFind(ListNode* pHead, LTDateType x)
{
	assert(pHead);
	
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


void ListInsert(ListNode* pos, LTDateType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}


void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}



int ListEmpty(ListNode* pHead)
{
	return pHead->next == pHead ? 1 : 0;
}

int ListSize(ListNode* pHead)
{
	assert(pHead);
	int size = 0;
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		size++;
		cur = cur->next;
	}
	return size;
}