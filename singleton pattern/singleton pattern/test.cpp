#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <mutex>
using namespace std;


//class HeapOnly
//{
//public:
//	static HeapOnly* CreatObj()
//	{
//		return new HeapOnly;
//	}
//private:
//	HeapOnly()
//	{}
//
//	//HeapOnly(const HeapOnly&);//拷贝构造私有，只声明不实现。
//
//public:
//
//	HeapOnly(const HeapOnly&) = delete;//c++11防拷贝
//
//};


//懒汉模式，有大量数据需要初始化-》main之前实例化（饿汉）会导致长时间进不了main函数
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (_inst == nullptr)
		{

			//只有第一次写入数据，需要加锁，保护线程安全。
			//以后都不需要加锁，为了提高效率，我们要使用双检查模式
			_mtx.lock();

			if (_inst == nullptr)
			{
				_inst = new Singleton;
			}
			_mtx.unlock();
			return _inst;
		}
	}
	static void DelInstance()
	{
		_mtx.lock();
		if (_inst)
		{
			delete _inst;
			_inst = nullptr;
		}
		_mtx.unlock();
	}

	void print()
	{
		printf("lalala");
	}


private:
	//第一步：三个私有
	Singleton()
		:_a(0)
	{}

	~Singleton()
	{
		//程序结束时，需要处理一下，持久化保存一些数据。
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	//实现一个内嵌垃圾回收类
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (_inst)
			{
				delete _inst;
				_inst = nullptr;
			}
		}

	};


	int _a;
	static Singleton* _inst;
	static std::mutex _mtx;
	static CGarbo _gc;
};




Singleton* Singleton::_inst = nullptr;
std::mutex Singleton::_mtx;
Singleton::CGarbo Singleton::_gc;



int main()
{
	//HeapOnly ho; //在栈上
	//HeapOnly* p = new HeapOnly;
	//HeapOnly* p = HeapOnly::CreatObj();
	//HeapOnly copy(*p);
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	Singleton::GetInstance()->print();
	//Singleton::print();

	return 0;
}




//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		//汉模式
//		return _inst;
//	}
//
//	void print()
//	{
//		printf("lalala");
//	}
//
//
//private:
//	//第一步：三个私有
//	Singleton()
//		:_a(0)
//	{}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	int _a;
//	static Singleton* _inst;
//};
//
//Singleton* Singleton::_inst = new Singleton;
//
//int main()
//{
//	//HeapOnly ho; //在栈上
//	//HeapOnly* p = new HeapOnly;
//	//HeapOnly* p = HeapOnly::CreatObj();
//	//HeapOnly copy(*p);
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	Singleton::GetInstance()->print();
//	//Singleton::print();
//
//	return 0;
//}