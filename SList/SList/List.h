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
//������������ͷ���
ListNode* ListCreate();
//��������
void ListDestory(ListNode* pHead);
//˫�������ӡ
void ListPrint(ListNode* pHead);
//˫������β��
void ListPushBack(ListNode* pHead, LTDateType x);
//˫������ͷ��
void ListPushFront(ListNode* pHead, LTDateType x);
//˫������ͷɾ
void ListPopFront(ListNode* pHead);
//˫������βɾ
void ListPopBack(ListNode* pHead);
//˫���������
ListNode* ListFind(ListNode* pHead, LTDateType x);
//˫��������posλǰ����
void ListInsert(ListNode* pos, LTDateType x);
//˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
//�п�
int ListEmpty(ListNode* pHead);
//��С
int ListSize(ListNode* pHead);