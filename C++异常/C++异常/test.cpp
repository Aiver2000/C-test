#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <string>
#include <condition_variable>
using namespace std;


//int main()
//{
//
//
//	
//	
//	int n = 100;
//	mutex mtx;
//	condition_variable cv;
//	bool flag = true;
//
//	thread t1([&](){
//		int i = 1;
//		for (; i < n; )
//		{
//			unique_lock<mutex> lock(mtx);
//			cv.wait(lock, [flag]()->bool{return flag; });
//
//			cout << i << endl;
//			i += 2;
//			flag = false;
//			cv.notify_one();
//		}
//	
//	});
//
//
//	thread t2([&](){
//		int j = 2;
//		for (; j < n;)
//		{
//			unique_lock<mutex> lock(mtx);
//			cv.wait(lock, [flag]()->bool{return !flag; });
//
//			cout << j << endl;
//			j += 2;
//			flag = true;
//			cv.notify_one();
//		}
//
//
//	});
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}

//mutex mtx;
//
//void f(int N)
//{
//	mtx.lock();
//
//	for (int i = 0; i < N; ++i)
//	{
//		cout <<this_thread::get_id()<<":"<< i << endl;
//
//	}
//	mtx.unlock();
//
//}
//
//
//int main()
//{	
//	int n;
//	cin >> n;
//	mutex mtx;
//	vector<thread> vthreads;
//	vthreads.resize(n);
//	int N = 100000;
//	
//	atomic<int> x = 0;
//	//int x = 0;
//	for (auto& td : vthreads)
//	{
//		td = thread([&mtx, &N,&x]
//		{
//			for (int i = 0; i < N; ++i)
//			{
//				//mtx.lock();
//				//cout << this_thread::get_id() << ":" << x << endl;
//				++x;
//				//this_thread::sleep_for(chrono::milliseconds(500));
//				//mtx.unlock();
//
//			}
//		});
//		//cout << td.get_id() << endl;
//	}
//
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//	
//	printf("%d个老铁并行对 大傻逼 草了%d次,共cao %d\n", n, N,x);
//
//	return 0;
//}
//


//int main()
//{
//	try
//	{
//		char* p = new char[0x7fffffff];
//		/*if (p == nullptr)
//		{
//			cout << "new failed" << endl;
//		}*/
//
//
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//
//
//
//
//	return 0;
//
//}


//class MyExcetion
//{
//public:
//	MyExcetion(int errid, const char* errmsg)
//		:_errid(errid)
//		, _errmsg(errmsg)
//	{}
//
//	int GetErrId() const
//	{
//		return _errid;
//	}
//
//	const string& what() const
//	{
//		return _errmsg;
//	}
//
//
//private:
//	int _errid;
//	string _errmsg;
//	//
//};
//void f1()
//{
//	//mutex mtx;
//	//mtx.lock();
//
//	int i, j;
//	cin >> i >> j;
//	if (j == 0)
//	{
//		throw MyExcetion(1,"除零者");
//	}
//	cout << i / j << endl;
//
//	//mtx.unlock();
//}
//
//
//int* p2 = nullptr;
//FILE* p3 = nullptr;
//
//
//void f2()
//{
//	p2 = (int*)malloc(40);
//	if (p2 == nullptr)
//	{
//		throw MyExcetion(2,"malloc 你家地砖呢？ 没人给你用啊");
//	}
//}
//
//void f3()
//{
//	p3 = fopen("test.xpp", "r");
//	if (p3 == nullptr)
//	{
//		throw MyExcetion(3,"不要open不属于你的人生");
//	}
//}
//
//
//int main()
//{
//	try
//	{
//		
//		f1();
//		f2();
//		f3();
//
//		free(p2);
//		fclose(p3);
//	}
//	catch (int errid)
//	{
//		cout << "错误码："<<errid << endl;
//	}
//	catch (const string& s)
//	{
//		cout <<"错误描述："<< s << endl;
//
//		if (s == "不要open不属于你的人生")
//		{
//			free(p2);
//		}
//	}
//	catch (const MyExcetion& e)
//	{
//		cout << "错误描述：" << e.what() << endl;
//		if (e.GetErrId() == 3)
//		{
//			free(p2);
//		}
//	}
//	return 0;
//}


