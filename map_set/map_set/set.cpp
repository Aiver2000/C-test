#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <set>
#include <string>
using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(1);
	s.insert(9); 
	s.insert(44);
	s.insert(0);
	s.insert(3);
	s.insert(77);
	s.insert(3);
	//作用一：排序+去重
	//遍历方式1：迭代器
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it += 1; set无法修改已经插入的值
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int> ::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	//遍历方式2:
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;



	//作用二：检查单词拼写是否正确

	//cout <<end;
	//cout <<endl;


	//词库中的单词都放进set对象中，每个写出来的单词查询set中在不在，在就是正确的，不在就是错误的。
	set<string> strSet;
	strSet.insert("apple");
	strSet.insert("fuck");
	strSet.insert("banana");
	strSet.insert("left");
	strSet.insert("right");
	//...

	for (const auto& e : strSet)
	{
		cout << e << " ";
	}
	cout << endl;
	set<string>::iterator ret = strSet.find("apple");
	if (ret != strSet.end())
	{
		cout << "find it !" << endl;
	}
	else
	{
		cout << "no find it" << endl;
	}


	ret = strSet.find("map");
	if (ret != strSet.end())
	{
		cout << "find it !" << endl;
	}
	else
	{
		cout << "no find it" << endl;
	}
}




void test_set2()
{
	set<int> s;
	s.insert(1);
	s.insert(9);
	s.insert(44);
	s.insert(0);
	s.insert(3);
	s.insert(77);
	s.insert(3);
	auto pos = s.find(9);
	s.erase(pos);

	//auto pos1 = s.find(40);
	//s.erase(pos1);


	s.erase(3);
	s.erase(39);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;



	
}


void test_set3()
{
	multiset<int> s;
	s.insert(1);
	s.insert(9);
	s.insert(44);
	s.insert(0);
	s.insert(3);
	s.insert(77);
	s.insert(3);

	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	multiset<int>::iterator pos = s.find(3);
	while (*pos == 3)
	{
		cout << *pos << endl;
		++pos;
	}
	cout << endl;

	cout << s.count(3) << endl;
	cout << s.count(3) << endl;
}
//int main()
//{
//	test_set3();
//
//	return 0;
//}
