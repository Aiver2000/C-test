#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"






//printlist ��ӡ����Ҫ����ʲô��������һ��ģ��������͵��б�
template<class Con>
void PrintContainer(const Con& c)
{
	Con::const_iterator it = c.begin();
	while (it != c.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

void test_list1()
{
	cout << "list1ʹ��pushback�������ݵĴ�ӡ" << endl;
	LL::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_back(5);
	lt1.push_back(6);
	PrintContainer(lt1);
	//for (auto e : lt)
	//{
	//	cout << e << " ";

	//}
	//cout << endl;

	//LL::list<int>::iterator it = lt.begin();
	//while (it != lt.end())
	//{
	//	(*it)++;
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;


	cout << "��������list2�Ĵ�ӡ" << endl;
	LL::list<int> lt2(lt1);
	PrintContainer(lt2);
	
	//cout << "��list2��2λ��ǰinsertһ��0����ӡ" << endl;
	//LL::list<int>::iterator pos = find(lt2.begin(), lt2.end(),2);		
	//lt2.insert(pos,0);
	//PrintContainer(lt2);

	//cout << "��list2��2λ��ǰinsertһ��0����ӡ" << endl;
	//lt2.erase(pos);
	//PrintContainer(lt2);

	cout << "��list2��list3��ֵ,����ӡ" << endl;
	LL::list<int> lt3;
	lt3 = lt2;
	PrintContainer(lt3);

	cout << "���list3�ĵ�һ��Ԫ�غ����һ��Ԫ��" << endl;
	cout << lt3.front() <<"  ";
	cout << lt3.back() << endl;

	cout << "��һ��ȫ��0��list4������ӡ" << endl;
	LL::list<int> lt4;
	lt4.push_back(0);
	lt4.push_back(0);
	lt4.push_back(0);
	lt4.push_back(0);
	lt4.push_back(0);
	lt4.push_back(0);
	PrintContainer(lt4);

	cout << "��������list1��list4������ӡ" << endl;
	lt1.swap(lt4);
	PrintContainer(lt4);


	cout << "ͷɾlist4" << endl;
	lt4.pop_front_erase();
	PrintContainer(lt4);
	cout << "ͷ��list4" << endl;
	lt4.push_front_insert(0);
	PrintContainer(lt4);
	cout << "βɾlist4" << endl;
	lt4.pop_back_erase();
	PrintContainer(lt4);
	cout << "β��list4" << endl;
	lt4.push_back_insert(0);
	PrintContainer(lt4);


	cout << "list4�Ľڵ����" << endl;
	cout << lt4.size() << endl;

	cout << "�ж���list1�Ƿ�Ϊ������" << endl;
	cout << lt1.empty() << endl;




	cout << "    " << endl;
	cout << "    " << endl;
	cout << "    " << endl;
	cout << "    " << endl;

	cout << "    " << endl;
	cout << "    " << endl;
}


int main()
{

	test_list1();
	return 0;
}