#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPrint(&s);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPrint(&s);
	SeqListInsert(&s, 6,0);
	SeqListPrint(&s);
	SeqListErase(&s, 6);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	printf("%d\n", SeqListFind(&s, 7)); 

	SeqListDestory(&s);


}

int main()
{
	TestSeqList1();

	return 0;
}


