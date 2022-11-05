#define _CRT_SECURE_NO_WARNINGS 1
//#include "RBTree.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Map.h"
#include "Set.h"

//void TestRBTree()
//{
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	
//	RBTree<int, int> t;
//	int n = 10000;
//	srand(time(0));
//	for (int i = 0; i < n;++i)
//	{
//		int e = rand();
//		t.Insert(make_pair(e, e));
//	}
//	t.InOrder();
//	cout << t.CheckBlance() << endl;
//	
//
//
//}

//int main()
//{
//	TestRBTree();
//	return 0;
//}

int main()
{
	zzz::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(4, 4));
	m.insert(make_pair(0, 0));
	m.insert(make_pair(2, 2)); 

	zzz::map<int, int> ::iterator it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first <<": "<<(*it).second<<endl;
		cout << it->first << ": " << it->second << endl;
		++it;
	}

	zzz::set<int,int> s;
	s.insert(1);
	s.insert(5);
	s.insert(8);
	s.insert(4);

	zzz::set<int, int> ::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;


	zzz::set<int, int> ::reverse_iterator rsit = s.rbegin();
	while (rsit != s.rend())
	{
		cout << *rsit << " ";
		++rsit;
	}
	cout << endl;
	return 0;
}