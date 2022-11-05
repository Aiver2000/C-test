#pragma once

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

namespace LL
{
	//������д����࣬��������ģ�壬��������structʵ�֣�Ĭ�������ǹ�����,�������඼���Ե��� 
	template<class T>
	//���н������Ҫ������������һ����ֵ������ָ��
	struct _list_node
	{
		T _val;
		_list_node<T>*  _next;
		_list_node<T>*  _prev;

		//������г���Ҫ����������������Ҫ��һ�����캯���������Ƕ���һ���½���ʱ�򣬽��й��캯����ʼ��
		//��������Ĳ�����һ��ȱʡ��valֵ ������ȱʡ�����������������캯���������const���ա�
		_list_node(const T& val = T())
			:_val(val)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	//����ʵ�ֵ������ࡣ��������������ʹ����ģ�� ���������������ģ�������ͬʱ�໹����struct��ʵ��
	//�ڵ��������У�������Ҫʵ�� 1������ 2�������ò���  3����= ��== ����  3��ǰ��++����++ --����
	template<class T, class Ref, class Ptr> //��������ģ�������ʲô��˼��?��������Ҫconst�������ͷ�const��������ʱ�����ǿ��Ը��ݵڶ��������Ĳ�ͬ��ʵ��������ͬ�ĵ��������Ͳ���Ҫд������������
	//typedef _list_iterator<T,T&,T*> iterator;
	//typedef _list_iterator<T,cosnt T&,const T*> const_iterator; //���ǿ��Ը���ģ�����ʵ��������ͬ�ĵ�������
	struct _list_iterator
	{
		typedef _list_node<T>  node;
		typedef _list_iterator<T, Ref, Ptr>  self;

		node* _pnode;

		//���캯������node��������Ȼ���ֵ���������ڲ�������_pnode,�ܲ������޸��ⲿָ��ɡ�
		_list_iterator(node * node)
			:_pnode(node)
		{}

		//�������ǲ���Ҫʵ�ֿ������졢operator=��������ֱ���ñ��������ɵģ�������������ֱ�ӽ���ǳ����
		//���Ƿ���ǳ����ָ�����list��˵��ȫû���⡣

		//�����ã����������Ƿ���ֵдΪRef ���������Ը���const�ͷ�const�����Ҿ������÷��ؿɶ����޸ģ����refΪconst���ǾͲ����޸�ֻ�ɶ���
		//���ﲻ��Ҫ�������������ֱ�ӽ��е��ã�����ֵ��ȻΪ��Ӧ��val����.
		Ref operator * ()
		{
			return _pnode->_val;
		}
		//ͬ�������дһ�����ָ������ã����ﷵ��ֵ������ģ��������ܷ��㰡������Ӧ�÷���һ����ַ��
		Ptr operator ->()
		{
			return &(_pnode->_val);
		}

		//��= �� == ��������ʹ�õ�������ʱ����Ҫ�Ƚ������������Ƿ����������ѭ�������ж����������Ǳ�Ҫ�ġ�
		//�������ﷵ��ֵ��Ȼ��bool�������������ǵĵ��������Ƚϵ������ڵĽڵ��Ƿ���ȡ��ټ���const��á�
		bool operator != (const self& s) const
		{
			return _pnode != s._pnode;
		}
		bool operator == (const self& s) const
		{
			return _pnode == s._pnode;
		}
		//��������ʵ��ǰ�ú���++--
		//ǰ�� ++ it  ���Ƿ���ֵ�� ԭ������
		self& operator++()
		{
			_pnode = _pnode->_next;
			return *this;
		}
		//���� ++ it ��������Ҫ���д��Σ���һ����������Ĭ�ϵ�this���ڶ�������Ϊ0
		//it ++ --> it.operator ++(&it,0);���ǿ���ȱʡ���ڶ�����������ΪĬ���ǴӲ����б�ĩβ��ʼƥ��ġ�
		//��Ȼ����ֵ�Ͳ��ܷ��������ˣ���Ϊ��������Ҫ����ʱ�������з���,�������ô����it��������һ����ʱ��������Ȼ���ڽ���++������
		//��Ϊ���üӼ����ȸ�ֵ��++��������������ʱ��������һ��֮ǰ�ĵ��������ٸ�֮ǰ�ĵ�����++������ٷ���δ�޸ĵ���ʱ��������
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




	//���������ǿ�ʼдlist��,��ȻҲҪ����ģ����д������Ҫʵ��1�������� 2������ 3��push_back �����������list�Ǵ�ͷ˫��ѭ���б�
	template <class T>
	class list
	{
		//��������ʵ��һ�µ�����,����������Ҫtypedef ���ǵĵ����� ��������ʵ�ֵ�������Ȼ����Ҫ����const�ͷ�const��beginend ,
		//������Ҫ��סend��beginҪ�з�const��cosnt����Ϊ�޷�ͬʱ������޸ĺͿɶ�������const����������ֻ�ܵ�const��end����const�ĵ�������Ȼ���Ե���const��end�����ǵ���Ȩ����С���޷��޸����ݡ�
		typedef _list_node<T> node;
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()                   //beginָͷ�����һ����㣬endָͷ��㡣
		{
			return iterator(_head->_next); //������õ�����������Ȼ��ֱ�ӷ��ء�
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


		//���캯��������ֱ�ӽ���ͷ���Ĵ������Լ����Լ���
		list()
		{
			//_head = new node(T());    ��Ȼ����������д������������������һ��ͷ��㣬�����Ǹ������͡�����������У����Ĺ��캯����һ���ģ�����дһ���ͺ��ˡ�
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//push_back ���Ǵ���һ��Ҫ�����ֵ�������½ڵ�������ӵĸ��¡�
		void push_back(const T& val)
		{
			node* newnode = new node(val);   //������Ϊ�����ڽ��Ĺ��캯����д��ģ����������������죬���Դ��������͡�
			node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

		}

		//��������  1�������µ�ͷ��㣬�Ѵ����listѭ����ֵ���µ�ͷ��㡣
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

		//insert����ָ��λ�ò���Ԫ�أ����ǲ��÷���ֵ��������pos��������val
		//�ȸ�һ��cur ��posλ�õĽ�㣬Ȼ����һ�����ǵ�prev��Ϊ��֮����½ڵ����ӡ�2�������½ڵ㣬�������Ӿͺ��ˡ�
		void insert(iterator pos, const T& val)   //���ﲻ��Ҫ��const ��Ϊ��const��������Ӧ��constlist ��const list��ô�������������أ�
		{
			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* newnode = new node(val);

			newnode->_next = cur;
			newnode->_prev = prev;
			prev->_next = newnode;
			cur->_prev = newnode;
		}

		//erase ,������һ��λ�õĵ�����������һ��pos
		//1������ָ���㣬���ҵ�ǰ������ڵ� 2���������� ɾ������ǰ�ڵ㡣3�����ص�������������Ҫǿת����ָ��ת�ɵ��������͡�
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


		//�������ڸ�ֵ��������ص�ʱ����Ҫ�����������Ľ�㣬��������ʵ��һ��clear
		//clear ���list�г���ͷ�����������н�㡣�ܺ�ʵ�֣�����ѭ��erase�ͺ��ˣ�erase������һ���ĵ����������Խ����䷵��ֵ�ͺ��ˡ�
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		//��ֵ��������أ�����ֵ�����͵����� ����������list
		//1�������ж��Ƿ���Լ���ֵ����������ɾ����ᷢ��Ұָ������� 2����������������������ڵ�һ�У�Ȼ��ѭ����ֵ����󷵻�*this��
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

		//����������Ҫ���ľ�������һ�У���clear����delete ͷ������ͷ����
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
			cout << "����ִ�гɹ�" << endl;
		}

		//��õ�һ��Ԫ�أ�����һ�������͵�����,����Ӧ���������汾������const������õ�ʱ�򣬻��޷����á����ﷵ��ҲҪ����const����������˼�͵͵������Ȩ�ޡ�
		T& front()
		{
			return _head->_next->_val;
		}

		const T& front() const
		{
			return _head->_next->_val;
		}
		//������һ��Ԫ��
		
		T& back()
		{
			return _head->_prev->_val;

		}
		const T& back() const
		{
			return _head->_prev->_val;

		}

		//��������list,����list������ֻ��Ҫ����һ��ͷ���Ϳ�����
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

		//�������ѭ������
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

		//resize ,����n���ռ䲢����ʼֵ�����������츳ֵ��
		//1������ɽ�����������Ϳռ���µĿռ�����Ǿ�ɾ������Ŀռ�2������ʹ��¿ռ俪ʼ���丳��ֵ��
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