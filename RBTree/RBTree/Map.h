#pragma once
#include "RBTree.h"

namespace zzz
{
template<class K,class V>
class map
{
	struct MapKeyOft
	{
		const K& operator()(const pair<const K, V>& kv)
		{
			return kv.first;
		}
	};
public:
	typedef typename RBTree<K, pair<const K, V>, MapKeyOft>::iterator iterator;
	typedef typename RBTree<K, pair<const K, V>, MapKeyOft>::reverse_iterator reverse_iterator;

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

	pair<iterator,bool> insert(const pair<const K, V>& kv)
	{
		return _t.Insert(kv);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = insert(make_pair(key, V()));
		return ret.first->second;
	}
private:
	RBTree<K, pair<const K, V>, MapKeyOft> _t;
};

}