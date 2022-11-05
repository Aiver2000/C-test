#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int LTDateType;
typedef struct ListNode
{
	LTDateType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;


ListNode* BuyListNode(LTDateType x);
//创建返回链表头结点
ListNode* ListCreate();
//销毁链表
void ListDestory(ListNode* pHead);
//双向链表打印
void ListPrint(ListNode* pHead);
//双向链表尾插
void ListPushBack(ListNode* pHead, LTDateType x);
//双向链表头插
void ListPushFront(ListNode* pHead, LTDateType x);
//双向链表头删
void ListPopFront(ListNode* pHead);
//双向链表尾删
void ListPopBack(ListNode* pHead);
//双向链表查找
ListNode* ListFind(ListNode* pHead, LTDateType x);
//双向链表在pos位前插入
void ListInsert(ListNode* pos, LTDateType x);
//双向链表删除pos位置的节点
void ListErase(ListNode* pos);
//判空
int ListEmpty(ListNode* pHead);
//大小
int ListSize(ListNode* pHead);