#pragma once
#include "HashTable.h"


namespace bit
{


	template<class K>
	class unordered_set
	{

		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:

		typedef typename OpenHash::HashTable<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
	
		

		pair<iterator,bool> insert(const K& key)
		{
			return _ht.Insert(key);

		}


	private:
		OpenHash::HashTable<K, K, SetKeyOfT> _ht;

	};

	void test_unordered_set()
	{
		unordered_set<int> us;
		us.insert(24);
		us.insert(1);
		us.insert(76);
		us.insert(42);
		us.insert(200);
		us.insert(7);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{ 
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}



}