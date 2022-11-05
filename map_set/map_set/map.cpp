#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <queue>
using namespace std;


void test_map1()
{

	map<int, double> m;
	m.insert(pair<int, double>(1, 1.1));
	m.insert(pair<int, double>(5, 5.5));
	m.insert(pair<int, double>(2, 2.2));
	m.insert(make_pair(2, 2.2));



	map<int, double> ::iterator it = m.begin();
	while (it != m.end())
	{
		//cout <<( *it).first<<":"<<(*it).second << endl;
		cout <<it->first<<":"<<it->second << endl;
		++it;
	}
	cout << endl;

	//std::map<std::string, std::string> dict;
	//dict.insert(std::pair<std::string, std::string>("insert","插入"));
	//dict.insert(std::make_pair("sort", "排序"));
	//dict.insert(std::make_pair("left", "左"));

	////std::map<std::string, std::string>::iterator it = dict.begin();
	//auto dit = dict.begin();
	//while (dit != dict.end())
	//{
	//	cout << dit->first << ":" << dit->second << " ";
	//	++dit;
	//	cout << endl;
	//}
	
	//通过typedef简化命名
	typedef std::map<std::string, std::string> DICT;
	typedef std::pair<std::string, std::string> DICT_KV;
	typedef std::map<std::string, std::string>::iterator DICT_ITER;


	DICT dict;
	dict.insert(DICT_KV("insert", "插入"));
	dict.insert(std::make_pair("sort", "排序"));
	dict.insert(std::make_pair("left", "左"));

	//std::map<std::string, std::string>::iterator it = dict.begin();
	DICT_ITER dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << " ";
		++dit;
		cout << endl;
	}


}

void test_map2()
{
	typedef std::map<std::string, std::string> DICT;
	typedef std::pair<std::string, std::string> DICT_KV;
	typedef std::map<std::string, std::string>::iterator DICT_ITER;


	DICT dict;
	dict.insert(DICT_KV("insert", "插入"));
	dict.insert(DICT_KV("sort", "排序"));
	dict.insert(DICT_KV("left", "左边"));

	DICT_ITER dit = dict.begin();
	while (dit != dict.end())
	{
		dit->second.insert(0, "{");
		dit->second += "}";
		++dit;	
	}
	cout << endl;

	dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;

	auto ret = dict.find("left");
	if (ret != dict.end())
	{
		//可读性优化技巧
		//ret->second.insert(ret->second.size()-1,",剩余");
		string& str = ret->second;
		str.insert(str.size() - 1, ",剩余");
	}
	dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;
}


void test_map3()
{
	//1、统计次数  2、找出大家最喜欢的三种水果

	string arr[] = { "香蕉", "草莓", "香蕉", "香蕉", "西瓜", "香蕉", "西瓜", "香蕉", "榴莲", "香蕉", "可乐", "可乐" };
	//方式一：
	/*map<string, int> countMap;
	for (const auto& str : arr)
	{
		map<string, int>::iterator ret = countMap.find(str);
		if (ret != countMap.end())
		{
			ret->second++;
		}
		else
		{
			countMap.insert(make_pair(str, 1));
		}
	}
*/
	//方式二：
	//map<string, int> countMap;
	//for (const auto& str : arr)
	//{
	//	//
	//	//pair<map<string, int>::iterator, bool>
	//	auto ret  = countMap.insert(make_pair(str, 1));
	//	if (ret.second == false)
	//	{
	//		ret.first->second++;
	//	}
	//}


	//统计方式三
	map<string, int> countMap;
	for (const auto& str : arr)
	{
		countMap[str]++;
	}
	for (const auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;


	//扩展
	map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict["left"] = "左边"; //插入 +修改
	dict["insert"];//插入
	dict["insert"] = "插入";//修改




}

struct MapItCompare
{
	bool operator()(map<string, int>::iterator x, map<string, int>::iterator y)
	{
		return x->second > y->second;
	}
};

void test_map4()
{
	string arr[] = { "香蕉", "草莓", "香蕉", "香蕉", "西瓜", "香蕉", "西瓜", "香蕉", "榴莲", "香蕉", "可乐", "可乐" };
	map<string, int> countMap;
	for (const auto& str : arr)
	{
		countMap[str]++;
	}

	//topK：优先级队列、对所有水果次数排序思路
	//vector<pair<string, int>> v;
	vector<map<string,int>::iterator> v;
	map<string, int> ::iterator countMapIt = countMap.begin();
	while (countMapIt != countMap.end())
	{
		v.push_back(countMapIt);
		++countMapIt;
	}
	sort(v.begin(), v.end(), MapItCompare());

	//利用map排序
	map<int, string,greater<int>> sortMap;
	for (auto e : countMap)
	{
		sortMap.insert(make_pair(e.second, e.first));
	}

	//消除拷贝

	set<map<string, int>::iterator, MapItCompare> sortSet;
	countMapIt = countMap.begin();
	while (countMapIt != countMap.end())
	{
		sortSet.insert(countMapIt);
		++countMapIt;
	}

	typedef map<string, int>::iterator M_IT;

	priority_queue<M_IT, vector<M_IT>, MapItCompare> pq;
	countMapIt = countMap.begin();
	while (countMapIt != countMap.end())
	{
		pq.push(countMapIt);
		++countMapIt;
	}



	

}

void test_map5()
{
	map<string, string> dict;
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("left", "剩余"));

	multimap<string, string> mdict;
	mdict.insert(make_pair("left", "左边"));
	mdict.insert(make_pair("left", "剩余"));

}

int main()
{
	test_map5();

	return 0;
}