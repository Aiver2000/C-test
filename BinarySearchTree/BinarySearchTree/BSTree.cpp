#define _CRT_SECURE_NO_WARNINGS 1
#include "BSTree.h"


int main()
{
	BSTree<int> t;
	//int a[] = { 5, 4, 3, 2, 9, 6, 8, 0, 7 };
	//for (auto e : a)
	//{
	//	t.Insert(e);
	//}
	//t.InOrder();

	//t.Erase(7);
	//t.InOrder();

	//t.Erase(0);
	//t.InOrder();

	int b[] = { 5, 4, 3, 2, 9, 6, 8, 0, 7,1 };
	for (auto e : b)
	{
		t.InsertR(e);
	}
	t.InOrder();

	for (auto e : b)
	{
		t.Erase(e);
		t.InOrder();
	}
	t.InOrder();

	return 0;
}