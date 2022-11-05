#pragma once 
#include <vector>
//#include <map>

//template<class T>
//class UnionFindSet
//{
//public:
//	UnionFindSet(const T* a, size_t n)
//	{
//		for (size_t i = 0; i < n; ++i)
//		{
//			_a.push_back(a[i]);
//			_IndexMap[a[i]] = i;
//		}
//	}
//private:
//	vector<T> _a;					//编号找人
//	map<T, int> _IndexMap;			//人找编号
//
//
//};

class UnionFindSet
{
public:
	UnionFindSet(size_t n)
		:_ufs(n, -1)
	{}

	void Union(int x1, int x2)
	{
		//1、合并前先找根 ,判断是否zai  同一个set
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if (root1 == root2)
			return;

		if (abs(_ufs[root1]) < abs(_ufs[root2]))
			swap(root1, root2);

		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;

	}

	int FindRoot(int x) //当前号下，负数为根
	{
		int root = x;
		while (_ufs[root] >= 0)  //大于等于0  找根
		{
			root = _ufs[root];
		}

		//路径压缩
		while (_ufs[x] >=0)
		{
			int parent = _ufs[x];
			_ufs[x] = root;
			x = parent;
		}


		return root;
	}

	bool InSet(int x1,int x2)
	{
		return FindRoot(x1) == FindRoot(x2);
	}

	size_t SetSize()
	{
		size_t size = 0;
		for (size_t i = 0; i < _ufs.size(); ++i)
		{
			if (_ufs[i] < 0)
				++size;
		}
		return size;
	}

private:
	vector<int> _ufs;
};

void TestUnionFindSet()
{
	UnionFindSet ufs(10);
	ufs.Union(8, 9);
	ufs.Union(7, 8);
	ufs.Union(6, 7);
	ufs.Union(5, 6);
	ufs.Union(4, 5);

	ufs.FindRoot(6);

	ufs.FindRoot(9);


}