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
//	//HeapOnly(const HeapOnly&);//��������˽�У�ֻ������ʵ�֡�
//
//public:
//
//	HeapOnly(const HeapOnly&) = delete;//c++11������
//
//};


//����ģʽ���д���������Ҫ��ʼ��-��main֮ǰʵ�������������ᵼ�³�ʱ�������main����
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (_inst == nullptr)
		{

			//ֻ�е�һ��д�����ݣ���Ҫ�����������̰߳�ȫ��
			//�Ժ󶼲���Ҫ������Ϊ�����Ч�ʣ�����Ҫʹ��˫���ģʽ
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
	//��һ��������˽��
	Singleton()
		:_a(0)
	{}

	~Singleton()
	{
		//�������ʱ����Ҫ����һ�£��־û�����һЩ���ݡ�
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	//ʵ��һ����Ƕ����������
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
	//HeapOnly ho; //��ջ��
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
//		//��ģʽ
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
//	//��һ��������˽��
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
//	//HeapOnly ho; //��ջ��
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