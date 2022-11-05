#pragma once
#include <iostream>
#include <assert.h>
using namespace std;



template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;//平衡因子

	pair<K, V> _kv;


	AVLTreeNode(const pair<K, V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;


public:

	AVLTree()
		:_root(nullptr)
	{}


	//拷贝构造和赋值需要实现深拷贝

	void _Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Destory(root->_left);
		_Destory(root->_right);
		delete(root);
	}

	~AVLTree()
	{
		_Destory(_root);
		_root = nullptr;
	}

	V& operator[](const K& key)
	{
		pair<Node*, bool> ret =  Insert(make_pair(key,V()));
		return ret.first->_kv.second;
	}

	pair<Node*,bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root,true);
		}
		// 找到存储的位置，插入数据
		Node* parent = _root, *cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(cur, true);
			}
		}

		cur = new Node(kv);
		Node* newnode = cur;
		if (parent->_kv.first <kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//控制平衡
		//1.更新平衡因子
		//2.旋转不平衡树
		while (parent)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;

			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//继续更新
				cur = parent;
				parent = parent->_parent;

			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//parent所在子树已经不平衡，需要旋转处理
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						//右单旋
						RotateR(parent); 
					}
					else//cur->_bf == 1
					{
						RotateLR(parent);
						
					}
				}
				else
				{
					if (cur->_bf == 1)
					{
						//左单旋
						RotateL(parent);
					}
					else // cur->_bf == -1
					{
						RotateRL(parent);
					}
				}
				break;
			}
			else
			{
				//出入结点之前树中已经不平衡、或bf出错需要检查逻辑
				assert(false);


			}

		}

		return make_pair(newnode, true);

	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);
		//平衡因子的调节
		if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
			subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			subL->_bf = -1;
			parent->_bf = 0;
			subLR->_bf = 0;

		}
		else if (bf == 0)
		{
			subL->_bf = 0;
			parent->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}





	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);
		//平衡因子调节
		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			parent->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			subR->_bf = 0;
			parent->_bf = 0;
			subRL->_bf = 0;

		}
		else
		{
			assert(false);
		}
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}

		parent->_bf = subR->_bf = 0;
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL; 
			_root->_parent = nullptr;

		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			
			else
				parentParent->_right = subL;

			subL->_parent = parentParent;
		}

		subL->_bf = parent->_bf = 0;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first >key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		return false;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second <<endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
	}


	int _Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return rightHeight > leftHeight ? rightHeight + 1 : leftHeight + 1;
	}

	bool _IsBanlance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		//检查一下平衡因子是否正确
		if (rightHeight - leftHeight != root ->_bf)
		{
			cout << "平衡因子异常：" << root->_kv.first << endl;
			return false;
		}

		return abs(rightHeight - leftHeight) < 2
			&& _IsBanlance(root->_left)
			&& _IsBanlance(root->_right);

		

	}

	bool IsAvlTree()
	{
		return _IsBanlance(_root);
	}

private:
	Node* _root;


};