#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace lqx
{
	class string
	{
	public:

		//构造函数
		string(const char* str = "")              								            		
		{									      // 注意一下:假设str有10byte，我们_size最大是9，因为有一个是\0	
			_size = strlen(str);			      //           _capacity此时可以是9也可以是10 ， 这里推荐大家是9	
			_capacity = _size;			
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//传统写法
		//拷贝构造		
		//s2（s1）
		//string(const string &s)
		//	:_str(new char[strlen(s._str) + 1])
		//{
		//	strcpy(_str, s._str);
		//}

		//赋值运算符重载
		//s1 = s3
		//s1 = s1
		//string& operator= (const string &s)
		//{
		//	if (this != &s)				              // 判断是否为自己给自己赋值
		//	{
		//		delete[] _str;                         //这里应该如何理解呢？
		//		_str = new char[strlen(s._str) + 1];   //两个字符串赋值：1、我们需要先删除原来的被赋值的字符串
		//											   //					 因为我们担心被赋值的字符串空间不够
		//												//				2、我们要去重新开辟和要赋值字符串一样的空间，
		//												//				    +1为了存'\0'
		//		strcpy(_str, s._str);				    //                3、进行拷贝
		//	}
		//	return *this;							   //引用返回指针，减少拷贝。
		//}

		//s1.swap(s2)       这个调用的是我们自己定义的
		//swap(s1,s3)       调用的是库模板
		                                       //显然我们自己定义的更好，因为库模板需要有一次拷贝构造，两次运算符重载。一共有三次深拷贝。代价是很大的。
		void swap(string& s)				
		{									
			::swap(_str, s._str);              //这三个swap会遵循就近原则，找到我们自己写的swap，但是参数个数都不一样。
			::swap(_size, s._size);			   //所以我们要使用类作用域限定符,左边没有指定为全局的。
			::swap(_capacity, s._capacity);

		}


		//现代写法
		string(const string &s)
			:_str(nullptr) 
			,_size(0)
			,_capacity(0)				//这里初始化为空指针，因为如果不初始化，_str为随机值，当我们把它和tmp交换后，									   //tmp变为随机值，出作用域时进行析构的时候会出错。
		{
			string tmp(s._str);        //先构造一个临时对象 tmp，再进行交换。
			swap(tmp);				           //这里的swap是库提供的函数模板
			
			
		}

		string& operator=(string s)     //这里进行传值传参，s是实参 深拷贝 下来的，这里s会自动析构，
										//s交换完，本来就是需要被清理掉的,这时候就会很爽。
		{							    //当这个代码遇到自己给自己赋值的时候，自己的地址会发生改变
			//我们看看下面的写法
			swap(s);
			return *this;
		}

		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				swap(_str, tmp._str);
				return *this;

			}
		}*/
		/*---------------------------------------------------------------------------------------------------
		传统、现代效率一样  传统：开一个相同的空间存，进行深拷贝

		----------------------------------------------------------------------------------------------------*/

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		//const char* c_str()
		//{
		//	return _str;
		//}
		//================以上为默认成员函数以及深浅拷贝的接口，下来我们实现string增删查改等功能============

		typedef char* iterator;       //迭代器，现在可以把迭代器想象成像指针一样的东西
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin()  const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		const char* c_str() const
		{
			return _str;
		}

		//string(const char* str = "")
		//遍历
		//改
		//at 作用和operator[]类似，失败抛异常
		const char& operator [](size_t i) const  //前后都加const，才可以成立，给const调用
		{
			assert(i < _size);
			return _str[i];
		}

		char& operator [](size_t i)  //给非const调用
		{
			assert(i < _size);
			return _str[i];
		}

		size_t size()  const //这里加上const，使const可以调它
		{
			return _size;
		}
		//开空间，扩展capacity
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strncpy(tmp, _str,_size+1);           //这里不能用strcpy，因为如果我们原字符串中有\0，\0为我们的有效字符，并非结束标识，那么就会提前结束。
				delete[] _str;
				_str = tmp;
			}
			_capacity = n;
		}
		//开空间+初始化，扩展capacity 并且初始化空间，size也会动。
		void resize(size_t n,char val = '\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n>_capacity)         //如果这里不判断，且我们不知道reserve函数中有没有if，那么我们可能就会缩容（不要缩容）。
				{					     //耦合度要低
					reserve(n);
				}
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = val;
				}
				_str[n] = '\0';
				_size = n;
			}

		}

		// 下面几个重要的增接口

		void push_back(char ch)         
		{
			if (_size = _capacity)
			{				
				reserve(_capacity == 0  ?  4:_capacity*2);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			++_size;

			//inset(_size,ch)
		}

		void append(const char* str)                //没有对齐的功能
		{
			size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, str);
			_size = len;

			//insert(_size,str);
		}

		string& operator += (char ch)           
		{
			push_back(ch);
			return *this;
		}
		string& operator += (const char* str)
		{
			append(str);
			return *this;
		}

		string& insert(size_t pos,const char* str)					//能不用就不用，因为效率不高  
		{														// “1234”+“345”  -> 头插  (N^2)   n个字符不断头插
																//                   ->尾插+逆置  （2*N）
																//
																
			assert(pos <=_size);
			size_t len = strlen(str);
			if (_size + strlen(str) > _capacity)
			{
				reserve(_size + len);
			}

			//挪动数据
			char* end = _str + _size;
			while (end >= _str + pos)
			{
				*(end + len) = *end;
				--end;
			}
			strncpy(_str + pos, str, len);     //这里不能使用strcpy 因为会把\0拷贝进去。
			_size += len;
			return *this;
			



		}
		//pos位置之前插入
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);  //当字符串为一个空串时候，需要给一个4，不然reserve会开2*0个空间。
			}
			//方案一								//我们从size（\0）位置开始挪动
			int end = _size;                        //这里为什么要用int 而不是size_t ，因为当在0位置插入一个字符的时候，0再-- 会变成42亿9千多的一个数据，也就是，2^32 -1 ;它是一个正数，它是大于pos的还会继续循环
			while (end >=(int) pos)                 //这里也要强转为int，因为范围小的会向范围大（无符号范围大于整形）的提升，又变为无符号了。
			{										
				_str[end + 1] = _str[end];				
				--end;

			}
		//	//方案二
		//	size_t end = _size + 1;
		//	while (pos > end)
		//	{
		//		_str[end] = _str[end-1];
		//		--end;
		//	}

		//	//方案三：指针

		//	char* end = _str + _size;
		//	while (end >= _str + pos)
		//	{
		//		*(end + 1) = *end;
		//	}



			_str[pos] = ch;
			_size++;
			return *this;
		}


		//删
		//pop_back();//尾删
		string& erase(size_t pos,size_t len = npos)   //越靠头去删，就要把之后的字符全往前移一下。
		{			
			assert(pos < _size);
			size_t leftLen = _size - pos;
			if (len >= leftLen) 
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size += len;


			}
			return *this;			
		
		}
		//查
		size_t find(char ch,size_t pos = 0)		//查字符、查字符串
		{
			assert(pos < _size);
			for (size_t i = pos; i <_size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
				else
				{
					return npos;
				}
			}

		}

		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			const char* ret = strstr(_str+pos,str);  //strstr匹配的比较暴力，第一个字符匹配到了，开始匹配第二个，如果没有匹配到，退出，从第二个字符开始匹配。
			if (ret)							     //方法二：KMP，字串重复很多，优化效果比较好。实际上这样的串不多
			{									     //方法三：BM匹配算法，在实际中，比KMP更加靠谱。
				return ret - _str;
			}
			else
			{
				return npos;
			}


		
		}
		//rfind(); //倒着找，复用find去解决。


		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos; //我们不能在这里给值，不然就变成缺省了。

	};

	const size_t string:: npos = -1;


	//一个字符一个字符比ascll，与长短无关
	inline bool operator<(const string& s1,const string& s2)         //一般实现成非成员函数，
	{
		return strcmp(s1.c_str(), s2.c_str()) <0; 

	}
	inline bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}
	inline bool operator == (const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	inline bool operator <= (const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	inline bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	inline bool operator != (const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	ostream& operator<<(ostream& out, string& s)     //cout是一个ostream类型的全局对象
	{											     //这里并不必须要定义成友元。 
		for (auto ch : s)
		{
			out << ch;
		}
		return out;						  //out为cout的别名，返回out可以使其连续输出（out<<c1）<<c2
	}


	istream& operator>>(istream& in, string&s)
	{
		s.clear();
		char ch;
		ch = in.get();         //遇到空格和回车，也会接收。
		while (ch != ' '&& ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}

}

