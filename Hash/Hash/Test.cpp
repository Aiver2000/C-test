#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <string>
#include <time.h>
#include "BitSet.h"
#include "BloomFilter.h"

using namespace std;

#include "HashTable.h"
#include "UnorderedMap.h"
#include "UnorderedSet.h"

namespace std
{
	void test_unordered_set1()
	{
		unordered_set<int> us;
		us.insert(2);
		us.insert(1);
		us.insert(2);
		us.insert(4);
		us.insert(2);
		us.insert(7);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e :us)
		{
			cout << e << " ";
		}
		cout << endl;

		auto pos = us.find(8);                //unordered_set专用算法：哈希特性查找，快     O（1）
		//auto pos = find(us.begin(),us.end(),9); //STL库的find ，通用算法，用于各种容器 缺点：暴力查找 O(n)；
												
		if (pos != us.end())
		{
			cout << "找到了" << endl;
		}
		else
		{
			cout << "没找到" << endl;
		}

	}

	void test_unordered_map1()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "排序"));
		dict["left"] = "左边";
		dict["left"] = "剩余";

		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":"<<it->second;
			++it;
			cout << endl;
		}
		
	}

	void test_op()
	{
		int N = 10000;
		vector<int> v;
		v.reserve(N);
		srand(time(0));
		for (int i = 0; i < N; ++i)
		{
			v.push_back(rand());
		}
		unordered_set<int> us;
		set<int> s;

		size_t begin1 = clock();
		for (auto e : v)
		{
			s.insert(e);
		}
		size_t end1 = clock();


		size_t begin2 = clock();

		for (auto e : v)
		{
			us.insert(e);
		}
		size_t end2 = clock();

		cout <<"set insert:"<< end1 - begin1 << endl;
		cout <<"unordered_set insert:"<< end2 - begin2 << endl;

	}
}

int main()
{
	//OpenHash::TestHashTable1();
	//std::test_unordered_map1();
	//test_op();
	//bit::test_unordered_set();
	//bit::test_unordered_map1();

	TestBloomFilter();
	return 0;
}