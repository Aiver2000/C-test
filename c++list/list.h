#pragma once

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

namespace LL
{
	我们先写结点类，这里用类模板，并且是用struct实现，默认内容是公开的,其他的类都可以调用 
	template<class T>
	其中结点类中要有三个变量，一个存值，两个指针
	struct _list_node
	{
		T _val;
		_list_node<T>*  _next;
		_list_node<T>*  _prev;

		结点类中除了要有三个变量，还需要有一个构造函数。当我们定义一个新结点的时候，进行构造函数初始化
		我们这里的参数是一个缺省的val值 ，其中缺省参数给的是匿名构造函数。最好以const接收。
		_list_node(const T& val = T())
			:_val(val)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	这里实现迭代器类。首先我们依旧是使用类模板 ，我们这里给三个模板参数，同时类还是用struct来实现
	在迭代器类中，我们主要实现 1、构造 2、解引用操作  3、！= 和== 操作  3、前置++后置++ --操作
	template<class T, class Ref, class Ptr> 这里三个模板参数是什么意思呢?当我们需要const迭代器和非const迭代器的时候我们可以根据第二个参数的不同来实例化出不同的迭代器，就不需要写两个迭代器了
	typedef _list_iterator<T,T&,T*> iterator;
	typedef _list_iterator<T,cosnt T&,const T*> const_iterator; 我们可以根据模板参数实例化出不同的迭代器。
	struct _list_iterator
	{
		typedef _list_node<T>  node;
		typedef _list_iterator<T, Ref, Ptr>  self;

		node* _pnode;

		构造函数，把node传进来，然后把值赋给我们内部创建的_pnode,总不能乱修改外部指针吧。
		_list_iterator(node * node)
			:_pnode(node)
		{}

		这里我们不需要实现拷贝构造、operator=、析构，直接用编译器生成的，对于内置类型直接进行浅拷贝
		我们发现浅拷贝指针对于list来说完全没问题。

		解引用，解引用我们返回值写为Ref ，这样可以根据const和非const，并且就是引用返回可读可修改，如果ref为const，那就不可修改只可读。
		这里不需要传入参数，我们直接进行调用，返回值当然为对应的val引用.
		Ref operator * ()
		{
			return _pnode->_val;
		}
		同理的我们写一下这个指针解引用，这里返回值依旧用模板参数，很方便啊。我们应该返回一个地址。
		Ptr operator ->()
		{
			return &(_pnode->_val);
		}

		！= 和 == ，当我们使用迭代器的时候，需要比较两个迭代器是否相等来进行循环条件判定，所以这是必要的。
		我们这里返回值当然是bool，参数传入我们的迭代器，比较迭代器内的节点是否相等。再加上const最好。
		bool operator != (const self& s) const
		{
			return _pnode != s._pnode;
		}
		bool operator == (const self& s) const
		{
			return _pnode == s._pnode;
		}
		接着我们实现前置后置++--
		前置 ++ it  我们返回值是 原迭代器
		self& operator++()
		{
			_pnode = _pnode->_next;
			return *this;
		}
		后置 ++ it ，我们需要进行传参，第一个参数就是默认的this，第二个参数为0
		it ++ --> it.operator ++(&it,0);我们可以缺省掉第二个参数，因为默认是从参数列表末尾开始匹配的。
		当然返回值就不能返回引用了，因为这里我们要用临时变量进行返回,我们先用传入的it拷贝构造一个临时迭代器。然后在进行++操作。
		因为后置加加是先赋值再++所以我们先用临时变量保存一下之前的迭代器，再给之前的迭代器++，最后再返回未修改的临时迭代器。
		self operator++(int)
		{
			self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;
		}

		self& operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}


	};




	接下来我们开始写list类,当然也要用类模板来写，里面要实现1、迭代器 2、构造 3、push_back 。我们这里的list是带头双向循环列表
	template <class T>
	class list
	{
		我们先来实现一下迭代器,我们首先需要typedef 我们的迭代器 ，所以先实现迭代器。然后需要定义const和非const的beginend ,
		这里需要记住end和begin要有非const和cosnt，因为无法同时满足可修改和可读。比如const迭代器调用只能掉const的end，非const的迭代器虽然可以调用const的end，但是导致权限缩小，无法修改内容。
		typedef _list_node<T> node;
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()                   //begin指头结点后第一个结点，end指头结点。
		{
			return iterator(_head->_next); //这里调用的是匿名构造然后直接返回。
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}


		构造函数，这里直接进行头结点的创建（自己链自己）
		list()
		{
			_head = new node(T());    当然可以有这种写法，我们用匿名构造一个头结点，可以是各种类型。这里和上文中，结点的构造函数是一样的，我们写一个就好了。
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		push_back 我们传入一个要插入的值，创建新节点进行链接的更新。
		void push_back(const T& val)
		{
			node* newnode = new node(val);   //这里因为我们在结点的构造函数中写了模板参数类型匿名构造，可以传任意类型。
			node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

		}

		拷贝构造  1、创造新的头结点，把传入的list循环赋值给新的头结点。
		list(const list<T>& l)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			const_iterator it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
		}

		insert，在指定位置插入元素，我们不用返回值，参数是pos迭代器和val
		先给一个cur 存pos位置的结点，然后定义一个我们的prev，为了之后和新节点链接。2、创建新节点，更新链接就好了。
		void insert(iterator pos, const T& val)   //这里不需要用const 因为，const迭代器对应了constlist ，const list怎么会来插入数据呢？
		{
			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* newnode = new node(val);

			newnode->_next = cur;
			newnode->_prev = prev;
			prev->_next = newnode;
			cur->_prev = newnode;
		}

		erase ,返回下一个位置的迭代器，传入一个pos
		1、保存指向结点，并找到前后的两节点 2、更新链接 删除掉当前节点。3、返回迭代器。这里需要强转，从指针转成迭代器类型。
		iterator erase(iterator pos)
		{
			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* next = cur->_next;
			
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			return (iterator)next;
		}


		那我们在赋值运算符重载的时候需要先清理掉自身的结点，所以我们实现一下clear
		clear 清空list中除了头结点以外的所有结点。很好实现，我们循环erase就好了，erase返回下一个的迭代器，所以接收其返回值就好了。
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		赋值运算符重载，返回值是类型的引用 ，参数传入list
		1、首先判断是否给自己赋值，否则我们删除后会发生野指针的问题 2、条件成立我们先清除现在的一切，然后循环赋值。最后返回*this；
		list<T>& operator = (list<T>& l)
		{
			if (this != &l)
			{
				clear ();
				iterator it = l.begin();
				while (it != l.end())
				{
					push_back(*it);
					it++;
				}
				
			}
			return *this;
		}

		析构：析构要做的就是析构一切，先clear，在delete 头，并给头赋空
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
			cout << "析构执行成功" << endl;
		}

		获得第一个元素，返回一定是类型的引用,这里应该有两个版本，否则当const对象调用的时候，会无法调用。这里返回也要返回const，否则你给人家偷偷扩大了权限。
		T& front()
		{
			return _head->_next->_val;
		}

		const T& front() const
		{
			return _head->_next->_val;
		}
		获得最后一个元素
		
		T& back()
		{
			return _head->_prev->_val;

		}
		const T& back() const
		{
			return _head->_prev->_val;

		}

		交换两个list,传入list。我们只需要交换一下头结点就可以了
		void swap(list<T>& l)
		{
			::swap(_head, l._head);
		}

		void push_back_insert(const T& val)
		{
			insert(end(), val);
		}

		void push_front_insert(const T& val)
		{
			insert(begin(), val);
		}

		void pop_front_erase()
		{
			erase(begin());
		}
		void pop_back_erase()
		{
			erase(--end());
		}

		求结点个数循环计数
		size_t size()
		{
			size_t count = 0;
			auto it = begin();
			while (it != end())
			{
				++it;
				++count;

			}
			return count;
		}

		bool empty()
		{
			return begin() == end();		
		}

		resize ,开辟n个空间并赋初始值，用匿名构造赋值。
		1、计算旧结点个数，如果就空间比新的空间大，我们就删除多余的空间2、否则就从新空间开始给其赋初值。
		void resize(size_t newsize, T& val = T())
		{
			size_t oldsize = size();
			if (oldsize > newsize)
			{
				for (int i = newsize; i < oldsize; i++)
				{
					pop_back_erase();
				}
			}
			else
			{
				for (int i = oldsize; i < newsize; i++)
				{
					push_back_insert(val);
				}
			}
		}




	private:
		node* _head;
	};

}
