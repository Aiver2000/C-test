#include <iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;

	K _key;

	BSTreeNode(const K& Key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(Key)
	{}
	
	
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
private:
	Node* _FindR(Node* root,const K& key)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (root->_key < key)
		{
			return _FindR(root->_right, key);

		}
		else if (root->_key < key)
		{
			return _FindR(root->_left, key);
		}
		else
		{
			return root;
		}
	}

	bool _InsertR(Node*& root,const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key < key)
		{
			return _InsertR(root->_right, key);
		}
		else if (root->_key>key)
		{
			return _InsertR(root->_left, key);
		}
		else
		{
			return false;
		}
	}

	bool _EraseR(Node*& root,const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->_key > key)
		{
			return _EraseR(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _EraseR(root->_right, key);
		}
		else
		{
			if (root->_left == nullptr)
			{
				Node* del = root;
				root = root->_right;
				delete del;
			}
			else if (root->_right == nullptr)
			{
				Node* del = root;
				root = root->_left;
				delete del;
			}
			else
			{
				Node* minRightParent = root;
				Node* minRight = root->_right;
				while (minRight->_left)
				{
					minRightParent = minRight;
					minRight = minRight->_left;
				}
				root->_key = minRight->_key;

				if (minRightParent->_left == minRight)
				{
					minRightParent->_left = minRight->_right;
				}
				else
				{
					minRightParent->_right = minRight->_right;
				}
				delete minRight;
			}
			return true;
		}
	}

	void _Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Destory(root->_left);
		_Destory(root->_right);
		delete root;
	}

	Node* _Copy(Node* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		Node* copyNode = new Node(root->_key);
		copyNode->_left = _Copy(root->_left);
		copyNode->_right = _Copy(root->_right);

		return copyNode;
	}
public:
	BSTree()
		:_root(nullptr)
	{}
	
	BSTree(const BSTree<K>& t)
	{
		_root = _Copy(t._root);
	}
	BSTree<K>& operator=(BSTree<K> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~BSTree()
	{
		_Destory(_root);
		_root = nullptr;
	}
	//涉及深浅拷贝，需要实现拷贝构造 operator= 等

	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}
	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}
	bool EraseR(const K& key)
	{
		return _EraseR(_root,key);
	}

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}


		}
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;

	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key >key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}

		}

		return NULL;
	}

	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{

					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{

							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else if (parent->_right == cur)
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;

					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{

							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else if (parent->_right == cur)
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else
					{
						Node* minRightParent = cur;
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							minRightParent = minRight;
							minRight = minRight->_left;
						}
						cur->_key = minRight->_key;

						if (minRightParent->_left == minRight)
						{
							minRightParent->_left = minRight->_right;
						}
						else
						{
							minRightParent->_right = minRight->_right;
						}
						delete minRight;

					}
				
				return true;
			}
		}

		return false;
	}


	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);

	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;

	}
private:
	Node* _root;
};