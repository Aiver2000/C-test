#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <thread>
using namespace std;





//�ɱ�������Ĵ�ӡ----------------------------------------------------------
//template <class T,class ...Args>
//void ShowList(T value, Args... args)
//{
//
//	cout << value << " ";
//	ShowList(args...);
//	
//}
//void ShowList()
//{
//	cout << endl;
//}

//�ɱ�������Ĵ�ӡ2 -------------------------------------------------------

//
//template <class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}
//
//
//template<class ...Args>
//void ShowList(Args... args)
//{
//	//�б��ʼ�� 
//	int arr[] = {(PrintArg(args),0)... };
//	cout << endl;
//}
//	cout << sizeof...(args) << endl;
//}

//int main()
//{
	/*ShowList(1,2);
	ShowList(1, 2, 'A', "sssss");
	ShowList(23,11.11,"121");*/
	/*ShowList(1, 2, 3, 5, 6, 7);
	ShowList(1, 2, 3);
	ShowList(1, 2, 3,"121212");
*/

	//int a[] = { 1, 2, 3, 4, 5 };
//	std::list<std::pair<int,std::string>> list;
//
//	auto kv = make_pair(20, "sort");
//	list.emplace_back(kv);
//	list.emplace_back(make_pair(10, "fuck"));
//	list.emplace_back(11, "me"); 
//
//
//
//	return 0;
//}
//template<class ...Args>
//void ShowList(Args... args)
//{



//#######################################################
//lambda���ʽ
//int main()
//{
//	int a = 0, b = 1;
//	//auto swap = [](int a, int b)-> void
//	//{ 
//	//	int temp = 0;
//	//	temp = a;
//	//	a = b;
//	//	b = temp;
//	//};
//
//	//////��׼д����
//	auto swap1 = [](int& a, int& b)->void
//	{
//		int temp = a;
//		a = b;
//		b = temp;
//	};
//
//	swap1(a, b);
//	//////////////��׽�б���׽�ֲ�����������ٴ��Σ�ʡ�Բ�������ֵ
//	auto swap2 = [&]()
//	{
//		int temp = a;
//		a = b;
//		b = temp;
//	};
//
//	swap2();
//
//	return 0;
//
//}


//////////////////////////////////////
//###################################
//��װ��

//int main()
//{
//
//	//��װlambda���ʽ
//	auto f5 = [](int a, int b)->int{return a + b; };
//	std::function<int(int, int)> ff1 = f5;
//	cout << ff1(1, 2) << endl;
//
//
//	return 0;
//}


//*************************
//bind:��������
//
//
//int Plus(int a, int b)
//{
//	return a + b;
//}
//
//
//
//class Sub
//{
//public:
//	int sub(int a, int b)
//	{
//		return a - b;
//	}
//};
//
//int main()
//{
//	std::function<int(int,int)> f1 = bind(Plus, placeholders::_1, placeholders::_2);
//	cout << f1(1, 2) << endl;
//	//��plus��Ϊһ��ֵ+10��
//	std::function<int(int)> f2 = bind(Plus,10, placeholders::_1);
//	cout << f2(1) << endl;
//
//	std::function<int(int, int)> f3 = bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2);
//	cout << f3(1, 2) << endl;
//
//	std::function<int(int, int)> f4 = bind(&Sub::sub, Sub(), placeholders::_2, placeholders::_1);
//	cout << f4(1, 2) << endl;
//	return 0;
//}
//
//


int main()
{
	size_t n = 100;
	thread t1([n]
	{
		for (size_t i = 0; i < n; i+=2)
		{
			cout << i << endl;
		}

	});
	thread t2([n]
	{
		for (size_t i = 1; i < n; i += 2)
		{
			cout << i << endl;
		}

	});

	t1.join();
	t2.join();
	return 0;
}