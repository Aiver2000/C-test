#define _CRT_SECURE_NO_WARNINGS 1


#include "SList.h"
#include "List.h"


void TestSList1()
{
	SLTNode* plist = NULL;
	SLTNode* Finded = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SListPushFront(&plist, 0);
	SListPrint(plist);

	/*SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);*/

	SListPopFront(&plist);
	
	SListPrint(plist);

	Finded = SListFind(plist, 3);

	SListEraseAfter(plist);
	SListPrint(plist);
	SListInsertAfter(plist, 6);
	SListPrint(plist);

	



}

void TestSList2()
{
	ListNode * plist = ListCreate();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListPrint(plist);
	ListPushFront(plist,0);
	ListPushFront(plist, 0);
	ListPushFront(plist, 0);
	ListPushFront(plist, 0);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);

	ListPrint(plist);
	
	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPrint(plist);

	ListNode* pp = ListFind(plist,3);
	if (pp)
	{
		ListInsert(pp, 5);
	}
	
	ListPrint(plist);
	ListErase(pp);
	ListPrint(plist);

	




	ListDestory(plist);
	plist = NULL;
	

}



int main()
{
	TestSList2();
	return 0;
}