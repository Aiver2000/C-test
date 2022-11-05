#pragma once
#include <vector>
#include <iostream>
using namespace std;

namespace CloseHash
{
	enum State
	{
		EMPTY,
		EXITS,
		DELETE,
	};


	template <class K,class V> 
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K> 
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		} 
	};

	//特化
	template<>
	struct Hash<string>
	{
		size_t operator()(const string& s)
		{
			size_t value = 0;
			for (auto ch : s)
			{
				value += ch;
				value *= 131; //BKDR Hash
			}

			return value;
		}
	};

	template <class K, class V,class HashFunc = Hash<K>>
	class HashTable
	{
	public:
	
		bool Insert(const pair<K, V>& kv)
		{
			
			HashData<K,V>* ret = Find(kv.first);
			if (ret)
			{
				return false;
			}
			if (_table.size() == 0)
			{
				_table.resize(10);
			}

			else if ((double)_n / _table.size() > 0.7)
			{
				////扩容并重新插入
				//vector<HashData> newtable;
				//newtable.resize(_table.size()*2)
				//for (auto& e : _table)
				//{
				//	if (e._state == EXITS)
				//	{
				//		
				//	}
				//}
				//_table.swap(newtable);

				HashTable<K, V,HashFunc> newHT;
				newHT._table.resize(_table.size() * 2);
				for (auto& e : _table)
				{
					if (e._state == EXITS)
					{
						newHT.Insert(e._kv);
					}
				}
				_table.swap(newHT._table);

			}
			HashFunc hf;
			size_t start = hf(kv.first) % _table.size();
			size_t index = start;

			size_t i = 1;
			while (_table[index]._state == EXITS)
			{
				//探测后面的位置 -- 线性探测or二次探测
				index = start +i;
				index %= _table.size();
				i++;

			}
			_table[index]._kv = kv;
			_table[index]._state = EXITS;
			++_n;
			return true;
		}
		HashData<K,V>* Find(const K& key)
		{
			if (_table.size() == 0)
			{
				return nullptr;
			}

			HashFunc hf;
			size_t start = hf(key) % _table.size();
			size_t index = start;

			size_t i = 1;
			while (_table[index]._state != EMPTY)
			{
				if (_table[index]._state == EXITS && _table[index]._kv.first == key)
				{
					return &_table[index];
				}
				index = start +i;
				index %= _table.size();
				++i;

			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
		}



	private:
		//HashData* _table;
		//size_t _size;
		//size_t _capacity;
		vector<HashData<K,V>> _table;
		size_t _n = 0;//存储有效数据个数

	};

	//struct IntHashFunc
	//{
	//	int operator()(int i)
	//	{
	//		return i;
	//	}
	//};

	void TestHashTable1()
	{
		int a[] = { 1, 5, 10, 100000, 100 ,18,15,7,40};
		HashTable<int, int> ht;
		for (auto e : a) 
		{
			ht.Insert(make_pair(e, e));
		}

		auto ret = ht.Find(100);
		if (ret)
		{
			cout << "找到了！" << endl;
		}
		else
		{
			cout << "没找到！" << endl;
		}

		ht.Erase(100000);

		ret = ht.Find(100);
		if (ret)
		{
			cout << "找到了！" << endl;
		}
		else
		{
			cout << "没找到！" << endl;
		}

		ht.Erase(100);

		ret = ht.Find(100);
		if (ret)
		{
			cout << "找到了！" << endl;
		}
		else
		{
			cout << "没找到！" << endl;
		}
	}

	//struct StringHashFunc
	//{
	//	size_t operator()(const string& s)
	//	{
	//		size_t value = 0;
	//		for (auto ch : s)
	//		{
	//			value += ch;
	//			value += 131; //BKDR Hash
	//		}

	//		return value;
	//	}
	//};

	void TestHashTable2()
	{
		string a[] = { "苹果", "西瓜", "香蕉", "苹果", "西瓜", "苹果", "西瓜" };
		HashTable<string, int> ht;
		for (auto str :a)
		{
			auto ret = ht.Find(str);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(str, 1));
			}

		}
	}

}


namespace OpenHash
{
	template<class K>
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	//特化
	template<>
	struct Hash<string>
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
	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)
			:_next(nullptr)
			, _data(data)
		{}
		
	};
	//前置声明：
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;
	//迭代器：
	template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
	struct __HTIterator
	{
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, KeyOfT, HashFunc> Self;
		typedef HashTable<K, T, KeyOfT, HashFunc> HT;
		Node* _node;
		HT* _pht;
		__HTIterator(Node* node, HT* pht)
			:_node(node)
			, _pht(pht)
		{}

		KeyOfT kot;
		HashFunc hc;
		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				size_t index = hc(kot(_node->_data)) % _pht->_table.size();
				++index;
				while (index<_pht->_table.size())
				{
					if (_pht->_table[index])
					{
						_node = _pht->_table[index];
						return *this;
					}
					else
					{
						++index;
					}
					
				}
				_node = nullptr;
				

			}
			return *this;
		}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};




	template<class K, class T, class KeyOfT,class HashFunc = Hash<K>>
	class HashTable
	{
		typedef HashNode<T>  Node;
		template<class K, class T, class KeyOfT, class HashFunc>
		friend struct __HTIterator;
	public:
		typedef __HTIterator<K, T, KeyOfT, HashFunc> iterator;
		//...
		HashTable() = default;
		HashTable(const HashTable& ht)
		{
			_n = ht._n;
			_table.resize(ht._table.size());

			for (size_t i = 0; i < ht._table.size(); i++)
			{
				Node* cur = ht._table[i];
				while (cur)
				{
					Node* copy = new Node(cur->_data);
					copy->_next = _table[i];
					_table[i] = copy;

					cur = cur->_next;

				}
			}

		}

		HashTable& operator= (HashTable ht)
		{	
			_table.swap(ht._table);
			swap(_n, ht._n);

			return *this;

		}


		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}

		iterator begin()
		{
			size_t i = 0;
			while (i < _table.size())
			{
				if (_table[i])
				{
					return iterator(_table[i], this);
				}
				++i;
			}
			return end();
		}
		
		iterator end()
		{
			return iterator(nullptr, this);
		}


		size_t GetNextPrime(size_t prime)
		{
			const int PRIMECOUNT = 28;
			static const size_t primeList[PRIMECOUNT] =
			{
				53ul, 97ul, 193ul, 389ul, 769ul,
				1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
				49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
				1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
				50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
				1610612741ul, 3221225473ul, 4294967291ul
			};
			size_t i = 0;
			for (; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] >prime)
					return primeList[i];
			}
			return primeList[i];
		}
		pair<iterator,bool> Insert(const T& data)
		{
			KeyOfT kot;
			HashFunc fc;
			auto ret = Find(kot(data));
			if (ret != end())
			{
				return make_pair(ret,false);
			}

			if (_n == _table.size())
			{
				vector<Node*> newtable;
				//size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
				//newtable.resize(newSize,nullptr);
				newtable.resize(GetNextPrime(_table.size()));
				

				for (size_t i = 0; i < _table.size(); ++i)
				{
					if (_table[i])
					{
						Node* cur = _table[i];
						while (cur)
						{
							Node* next = cur->_next;
							size_t index =fc(kot(cur->_data)) % newtable.size();
							cur->_next = newtable[index];
							newtable[index] = cur;

							cur = next;
						}
						_table[i] = nullptr;
					}
				}
				_table.swap(newtable);

			}
			size_t index = fc(kot(data)) % _table.size();
			Node* newnode = new Node(data);
			newnode->_next = _table[index];
			_table[index] = newnode;
			++_n;

			return make_pair(iterator(newnode,this),true);
		}

		iterator Find(const K& key)
		{
			KeyOfT kot;
			HashFunc fc;
			if (_table.size()==0)
			{
				return end();
			}
			size_t index = fc(key) % _table.size();
			Node* cur = _table[index];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this);
				}
				else
				{
					cur = cur->_next;
				}
			}
			return end();

		}

		bool Erase(const K& key)
		{
			HashFunc fc;
			size_t index = fc(key) % _table.size();
			Node* prev = nullptr;
			Node* cur = _table[index];

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (_table[index] == cur)
					{
						_table[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;

					}
					--_n;
					delete cur;
					return true;
				}
				prev = cur;
				cur = cur->_next;			
			}

			return false;



		}


	private:
		//Node** _table
		vector<Node*> _table;
		size_t _n = 0;

	};

	//void TestHashTable1()
	//{
	//	int a[] = { 1, 5, 30, 100000, 100, 18, 15, 7, 40,44 };
	//	HashTable<int, int> ht;
	//	for (auto e : a)
	//	{
	//		ht.Insert(make_pair(e, e));
	//	}
	//	ht.Insert(make_pair(25, 25));

	//}

}