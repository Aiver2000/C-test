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
	//dict.insert(std::pair<std::string, std::string>("insert","����"));
	//dict.insert(std::make_pair("sort", "����"));
	//dict.insert(std::make_pair("left", "��"));

	////std::map<std::string, std::string>::iterator it = dict.begin();
	//auto dit = dict.begin();
	//while (dit != dict.end())
	//{
	//	cout << dit->first << ":" << dit->second << " ";
	//	++dit;
	//	cout << endl;
	//}
	
	//ͨ��typedef������
	typedef std::map<std::string, std::string> DICT;
	typedef std::pair<std::string, std::string> DICT_KV;
	typedef std::map<std::string, std::string>::iterator DICT_ITER;


	DICT dict;
	dict.insert(DICT_KV("insert", "����"));
	dict.insert(std::make_pair("sort", "����"));
	dict.insert(std::make_pair("left", "��"));

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
	dict.insert(DICT_KV("insert", "����"));
	dict.insert(DICT_KV("sort", "����"));
	dict.insert(DICT_KV("left", "���"));

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
		//�ɶ����Ż�����
		//ret->second.insert(ret->second.size()-1,",ʣ��");
		string& str = ret->second;
		str.insert(str.size() - 1, ",ʣ��");
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
	//1��ͳ�ƴ���  2���ҳ������ϲ��������ˮ��

	string arr[] = { "�㽶", "��ݮ", "�㽶", "�㽶", "����", "�㽶", "����", "�㽶", "����", "�㽶", "����", "����" };
	//��ʽһ��
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
	//��ʽ����
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


	//ͳ�Ʒ�ʽ��
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


	//��չ
	map<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict["left"] = "���"; //���� +�޸�
	dict["insert"];//����
	dict["insert"] = "����";//�޸�




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
	string arr[] = { "�㽶", "��ݮ", "�㽶", "�㽶", "����", "�㽶", "����", "�㽶", "����", "�㽶", "����", "����" };
	map<string, int> countMap;
	for (const auto& str : arr)
	{
		countMap[str]++;
	}

	//topK�����ȼ����С�������ˮ����������˼·
	//vector<pair<string, int>> v;
	vector<map<string,int>::iterator> v;
	map<string, int> ::iterator countMapIt = countMap.begin();
	while (countMapIt != countMap.end())
	{
		v.push_back(countMapIt);
		++countMapIt;
	}
	sort(v.begin(), v.end(), MapItCompare());

	//����map����
	map<int, string,greater<int>> sortMap;
	for (auto e : countMap)
	{
		sortMap.insert(make_pair(e.second, e.first));
	}

	//��������

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
	dict.insert(make_pair("left", "���"));
	dict.insert(make_pair("left", "ʣ��"));

	multimap<string, string> mdict;
	mdict.insert(make_pair("left", "���"));
	mdict.insert(make_pair("left", "ʣ��"));

}

int main()
{
	test_map5();

	return 0;
}