#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <assert.h>

using namespace std;

namespace xxx
{
	template <class T>
	class Vector
	{
	public:  //c++中默认是private，所以要加上pblic
		//一：先来搞迭代器   迭代器怎么搞呢		1、先写指针 
										//	2、 写begin 和end  当然要有const和非const版本了
		
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}

		const_iterator cend() const
		{
			return _finish;
		}

		// 二 、我们开始实现默认成员函数
		// 构造函数：构造函数要怎么实现呢？函数名和类名一样，Vector，主要完成初始化列表，让他自动调用自动初始化。
		// 我们需要初始化什么呢？那就是那几个成员变量而已啦，我们在private中写的只是声明，这里才会真正的定义。顶多加上缺省功能。
		//我们注意一下，这里初始化可不是用等号初始化的，要用小括号。而且不需要带类型名。这里就是不用带iterator
		//而且只有第一个变量前是 ： 其他都是 ，
		
		//Vector() = default; //这里是让系统生成默认的构造函数
		
		Vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			printf("构造函数很好，over\n");
		
		}
		

		//析构函数：函数和类同名，前面加上~,函数里面要实现 1、if 判空  2、delete 注意delete不加=  3、指针赋空
		~Vector()
		{
			
			if (_start)
			{
				delete[]  _start;
				_start = _finish = _end_of_storage = nullptr;

				
			}
			printf("  ~析构函数很好，over\n");
		}
		//我们给这两个函数加上const,使调用者缩小权限。
		size_t Capacity()   const
		{
			return _end_of_storage - _start;
		}
		size_t Size()  const           
		{
			return _finish - _start;
		}

		//reserve开辟capacity空间
		//返回void ，传入开辟的size_t 一般实参就为capacity 
		//1,判断是否需要扩容，如果需要扩容，我们开辟一个临时变量存新开辟的数组。2，需要判空 3，若不为空就循环赋值给临时数组4，更新三个变量的值。
		//这里我们解释一下这个函数的功能：v2（v1） 这里的rerserve是v2的，当然如果之前有数据的话，size（）就不是0，这里开辟新的够大空间，把原来的数据拷贝的新数组里。
		void reserve(size_t n)
		{
		
			
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n]; //这里可以理解为，T类型的数组开n个空间。
				if (_start)     
				{

					//memcpy(tmp, _start, sizeof(T)*size);       //这里我们换一种写法。
					for (size_t i = 0; i < size; i++)
					{
						tmp[i] = _start[i];
					 }
					//delete[] _start;          //把原来的_start删了，不然还是用的原来的。
					
				}
				_start = tmp;
				_finish = _start + size;
				_end_of_storage = _start + n;
			}
			
		}


		//resize 传参为大小和一个缺省构造。1、判断并缩容 2、否则如果n过大就增容，循环给默认值并更新变量

		void resize(size_t n, const T& val = T()) //这里T（）为构造函数且是val 的缺省值，默认是0；
		{
			if (n <= Size())
			{
				_finish =_start + n;
			}
			else
			{
				if (n>Capacity())
				{
					reserve(n);
				}

				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
				
				

			}
			//这里为什么不更新_endof
		}





		//*****拷贝构造****** 难点
		//拷贝构造是构造函数的重载，所以函数写法一样，只是参数不一样，参数这里使用类模板并且取引用
		//功能如何实现呢？1、首要new一个新空间,T类型的数组，capacity那么大,指向新start。2、然后把传进来的类一个一个赋值给新空间3、修改另外两个变量的值
		/*Vector(Vector <T> & v)
		{
			printf("我是构造函数的弟弟，我很好，over\n");
			_start = new T[v.Capacity()];
			for (int i = 0; i < v.Size(); i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.Size();
			_end_of_storage = _start + v.Capacity();
			
		}*/

		//拷贝构造还有第二种实现方法 v2(v1)
		//我们传入const 变量，因为我们不会去修改小v的内容，一般传进来权限缩小，变为只读。同时我们进行初始化列表初始化，这里有个问题，这里不是和构造函数的初始化列表一样吗？所以我们可得，调用拷贝构造出来的函数，不会再去调用它的构造函数了。
		// 1 ,用reserve开空间  2, 我们用两组迭代器，一组是this的迭代器，一组是const的迭代器，循环赋值 3，更新另外两个变量

		Vector(const Vector<T> & v)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.Capacity());  

			iterator vi = begin();
			const_iterator cvi = v.cbegin();

			while (cvi != v.cend())
			{
				*vi++ = *cvi++;
			}
			_finish = _start + v.Size();
			_end_of_storage = _start + v.Capacity();
		
		}


		//****赋值运算符重载*****
		//函数的返回值是类的引用， 参数是const引用，1、判断是否给自己赋值2、删除之前的空间，并开辟新的空间3、然后把数据拷贝过来4、更新变量5、返回值
		//Vector<T>& operator=(const Vector<T>& v)
		//{
		//	if (this != &v)        //注意这里是取地址V
		//	{
		//		delete[] _start;
		//		_start = new T[sizeof(T)*v.Size()];  //这里为什么要sizeof（T），不是应该T类型有几个就是几个吗，为什么要算字节呢？
		//		//reserve(sizeof(T)*v.Size());       //这里为什么不去调用开辟函数呢？
		//		memcpy(_start, v._start, v.Size()*sizeof(T));
		//		_finish = _start + v.Size();
		//		_end_of_storage = _start + _capacity;
		//	}
		//	return *this;
		//}
		//当然还有第二种实现方法
		// 我们返回值依然是引用返回，而参数变成非const 非引用。1、我们进行swap，2、返回
		// 这里解释一下这个函数，当我们拷贝构造一个v传进来。我们在里面进行交换，有用的已经被this存下来了，没用的出函数栈帧自动销毁了。
		Vector<T>& operator=(Vector<T> v)   
		{
			Swap(v);
			return *this;
		}

		void Swap(Vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		//pushback 1、判断扩容 2、更新变量
		void pushback(const T& val)
		{
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				reserve(newcapacity);

			}
			*_finish = val;
			_finish++;
			//insert(_finish, val);  用insert的时候一定要结合find找新的迭代器，不然开新空间后，直接找不到
		}

		//popback 1、断言 2、变量更新
		void popback()
		{
			assert(Size() > 0);
			--_finish;

			//erase(--end());

		}





		//insert 插入 ：插入不需要返回值、参数是pos位置的迭代器，还有T类型引用，当然还要const。
		//1、我们先断言一下pos位置的正确性。2、存一下pos位置(避免迭代器失效) 3、判断空间大小，不够需要扩容并更新 4、迭代器循环移动空位。5，存入数据。6、更新变量
		void insert(iterator pos, const T& val)
		{
			assert(pos <= _finish);
			size_t posindex = pos - _start;
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				reserve(newcapacity); 
				pos = _start + posindex;
			}

			iterator end = _finish;
			while (pos < end)    //从后往前挪
			{
				*end = *(end - 1);
				end--;
			}
			*pos = val;
			_finish++;


		}


		//Erase 返回下一个位置（这里默认用pos迭代器返回值自动更新） ，参数pos迭代器。
		//1、pos给一个迭代器。2、循环给空3、更新变量
		iterator erase(iterator pos)
		{
			iterator begin = pos;
			while (pos != _finish)
			{
				*pos = *(pos + 1);	
				++pos;
			}
			--_finish;
			return begin;
		}




		//operator[] 这里应该有两个版本 返回引用，使之可修改，参数传一个位置就行
		//1、断言 2、返回
		T& operator [] (size_t pos)    //可读可写
		{
			assert(pos < Size());
			return _start[pos];
		}
		//当我们用const对象掉上面的函数时候，是无法调用的，当调用下面的函数时，返回应该是const，不然被动的扩大了权限。本来const调用的你，在你函数里面转一圈我被修改了。
		//const T& operator[] (size_t pos)  const    //只可读
		//{
		//	assert(pos < Size());
		//	return _start[pos];
		//}

		void print()
		{
			for (size_t i = 0; i < Size(); i++)
			{
				cout << _start[i] << " ";

			}
			cout << endl;
		}










	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;



		
	};


	void test1()            //测试构造、析构、pushback popback 迭代器 ，拷贝构造 .访问
	{
		Vector<int> v1;
		v1.pushback(1);
		v1.pushback(2);
		v1.pushback(3);
		v1.pushback(4);
		v1.pushback(5);
		v1.pushback(6);
		v1.print();
		v1.popback();
		v1.print();
		cout << endl;
		Vector<int>v2(v1);
		v2.print();
		Vector<int>::iterator  it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << "  " ;
			it++;
		}
		cout << "我是循环迭代器";
		cout << endl;
		

		for (auto e : v1)
		{
			cout << e << "   ";
			
		}
		cout << "我是for迭代器";
		cout << endl;

		Vector<int> v3;
		v3 = v2;
		v3.print();
		


	}

	void test2()     //测试insert和erase
	{
		Vector<int> v1;
		v1.pushback(1);
		v1.pushback(2);
		v1.pushback(3);
		v1.pushback(4);
		v1.pushback(5);

		v1.print();

		Vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
		v1.insert(pos, 250);
		v1.print();
		v1.insert(pos, 0);

		Vector<int>::iterator pos1 = find(v1.begin(), v1.end(), 250);
		Vector<int> ::iterator e_ret = v1.erase(pos1);
		e_ret = v1.erase(e_ret);
		e_ret = v1.erase(e_ret);
		v1.print();

	}


}


