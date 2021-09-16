#pragma once 
#include <iostream>
#include <vector>
using namespace std;
namespace www
{

	template<class T>
	struct less
	{
		bool operator()(const T& l, const T& r)
		{
			return l < r;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& l, const T& r)
		{
			return l > r;
		}
	};

	template <class T,class Container=vector<T>,class Compare = less<T>>
	class priority_queue
	{
	public:
		//priority_queue();
		//template<class InputIterator>;
		//priority_queue(InputIterator first, InputIterator last);
		bool empty() const
		{
			return _con.empty();
		}
		size_t size() const
		{
			return _con.size();
		}
		const T& top() const
		{
			return _con[0];
		}


		void AdjustUp(size_t child)
		{			
			size_t parent = (child - 1) / 2;
			while (child>0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break; 
				}				
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}


		void AdjustDown(size_t parent)
		{
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					child++;
				}

				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
	private:
		Container _con;
		Compare com;
	};
}