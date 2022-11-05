#define _CRT_SECURE_NO_WARNINGS 1
#include "AVLTree.h"

void TestAVLTree()
{
	int a[] = { 1, 3, 5, 7, 6 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e,e));
	}

	t.InOrder();
	cout << t.IsAvlTree() << endl;
}



int main()
{
	TestAVLTree();
	return 0;
}
