#pragma once
#include "RBTree.h"

namespace zzz
{
	template<class K, class V>
	class set
	{
		struct SetKeyOft
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOft>::iterator iterator;
		typedef typename RBTree<K, K, SetKeyOft>::reverse_iterator reverse_iterator;

		reverse_iterator rbegin()
		{
			return _t.rbegin();
		}


		reverse_iterator rend()
		{
			return _t.rend();
		}

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator,bool> insert(const K& k)
		{		
			return _t.Insert(k);
			
		}
	private:
		RBTree<K, K, SetKeyOft> _t;
	};

}