#pragma once
#include <iostream>
using namespace std;

namespace lqx
{
	class string
	{
	public:

		//构造函数
		string(const char* str = "")
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}

	//传统写法
		//拷贝构造		
		//s2（s1）
		string(const string &s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		//赋值运算符重载
		//s1 = s3
		//s1 = s1
		string& operator= (const string &s)
		{
			if (this != &s)            // 判断是否为自己给自己赋值
			{
				delete[] _str;                         //这里应该如何理解呢？
				_str = new char[strlen(s._str) + 1];   //两个字符串赋值：1、我们需要先删除原来的被赋值的字符串
													   //                   因为我们担心被赋值的字符串空间不够
													   //				 2、我们要去重新开辟和要赋值字符串一样的空间，
													   //				    +1为了存'\0'
				strcpy(_str,s._str);				   //                3、进行拷贝
			}
			return *this;              //引用返回指针，减少拷贝。
		}

    //现代写法
		string(const string &s)		   
			:_str(nullptr)             //这里初始化为空指针，因为如果不初始化，_str为随机值，当我们把它和tmp交换后，
									   //tmp变为随机值，出作用域时进行析构的时候会出错。
		{
			string tmp(s._str);        //先构造一个临时对象 tmp，再进行交换。
			swap(_str, tmp._str);      //这里的swap是库提供的函数模板
		}

		string& operator=(string s)    //这里进行传值传参，s是实参 深拷贝 下来的，这里s会自动析构，
									   //s交换完，本来就是需要被清理掉的,这时候就会很爽。
		{							   //当这个代码遇到自己给自己赋值的时候，自己的地址会发生改变
									   //我们看看下面的写法
			swap(_str, s._str);
			return *this;
		}

		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		swap(_str, tmp._str);
		//		return *this;

		//	}
		//}
/*---------------------------------------------------------------------------------------------------
 传统、现代效率一样  传统：开一个相同的空间存，进行深拷贝
                     
----------------------------------------------------------------------------------------------------*/

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		const char* c_str()
		{
			return _str;
		}
//================以上为默认成员函数以及深浅拷贝的接口，下来我们实现string增删查改等功能============

		//typedef char* iterator;

		//iterator begin()
		//{
		//	return _str;
		//}

		//iterator end()
		//{
		//	return _str + _size;
		//}

		//string(const char* str = "")


	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	};

	void string_test()
	{
		string s1("hello world");

	}
}

