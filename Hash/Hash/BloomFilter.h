#pragma once
#include "BitSet.h"



struct HashBKDR
{
	size_t operator()(const string& s)
	{
		size_t value = 0;
		for (auto ch : s)
		{
			value += ch;
			value += 131; //BKDR Hash
		}

		return value;
	}
};

struct APHash
{
	size_t operator()(const string& s){
		register size_t hash = 0;
		size_t ch;
		for (long i = 0; i<s.size(); i++)
		{
			ch = s[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};


struct DJBHash
{
	size_t operator()(const string& s){
		register size_t hash = 5381;
		for (auto ch :s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	} 
};

template<size_t N , class K = string, 
class Hash1 = HashBKDR,
class Hash2 = APHash,
class Hash3 = DJBHash>

class BloomFilter
{

public:
	void Set(const K& key)
	{
		size_t i1 = Hash1()(key)% N;
		size_t i2 = Hash2()(key)% N;
		size_t i3 = Hash3()(key)% N;
		cout << i1<<" "<<i2<<" "<<i3 << endl;

		_bitset.Set(i1);
		_bitset.Set(i2);
		_bitset.Set(i3);

	}

	bool Test(const K& key)
	{
		size_t i1 = Hash1()(key) % N;
		if (_bitset.Test(i1) == false)
		{
			return false;
		}
		size_t i2 = Hash2()(key) % N;
		if (_bitset.Test(i1) == false)
		{
			return false;
		}
		size_t i3 = Hash3()(key) % N;
		if (_bitset.Test(i1) == false)
		{
			return false;
		}
		return true;//三个位都在，不准确的，可能误判。不在是准确的。
	}
private:
	atm::BitSet<N> _bitset;

};

void TestBloomFilter()
{
	BloomFilter<100> bf;
	bf.Set("张三");
	bf.Set("李四");
	bf.Set("牛魔王");
	bf.Set("艾欧尼亚");

}