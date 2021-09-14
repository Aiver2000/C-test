#pragma once
#include <iostream>
#include <stack>
#include <queue>

using std::cout;
using std::endl;

namespace lqx
{
	template<class T,class Container = std::deque<T>>
	class stack
	{
	public:
		
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		T& top()
		{
			return _con.back();
		}

		const T& top() const
		{
			return _con.back();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};


	template<class T ,class Container = std::deque<T>>
	class queue
	{
	public:
		
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}
		T& back()
		{
			return _con.back();
		}
		const T& back()const
		{
			return _con.back();
		}
		T& front()
		{
			return _con.front();
		}
		const T& front() const
		{
			return _con.front();
		}
		size_t size() const
		{
			return _con.size();
		}
		bool empty() const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}
