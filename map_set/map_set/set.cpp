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
	//����һ������+ȥ��
	//������ʽ1��������
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it += 1; set�޷��޸��Ѿ������ֵ
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

	//������ʽ2:
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;



	//���ö�����鵥��ƴд�Ƿ���ȷ

	//cout <<end;
	//cout <<endl;


	//�ʿ��еĵ��ʶ��Ž�set�����У�ÿ��д�����ĵ��ʲ�ѯset���ڲ��ڣ��ھ�����ȷ�ģ����ھ��Ǵ���ġ�
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
