#pragma once
//#include<vector>
#include<map>
#include<string>
#include<queue>
#include"UnnionFindSet.h"
#include<functional>
#include<set>


namespace matrix
{
	template<class V, class W, W  MAX_W = INT_MAX, bool Direction = false>
	class Graph
	{
		typedef Graph<V, W, MAX_W, Direction> self;
	public:
		Graph() = default;
		Graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}
			_matrix.resize(n);
			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				_matrix[i].resize(n, MAX_W);
			}

		}

		size_t GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);
			if (it != _indexMap.end())
			{
				return it->second;
			}
			else
			{
				throw invalid_argument("顶点不存在");
				return -1;
			}
		}
		void _AddEdge(size_t srci, size_t dsti, const W& w)
		{

			_matrix[srci][dsti] = w;
			if (Direction == false)
			{
				//
				_matrix[dsti][srci] = w;

			}


		}
		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			_AddEdge(srci, dsti, w);


		}

		void Print()
		{
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				//cout << i << " ";
				printf("%4d ", i);
			}
			cout << endl;
			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				cout << i << ' ';
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					//cout << _matrix[i][j] << " ";
					if (_matrix[i][j] == INT_MAX)
					{
						//cout << "* ";
						printf("%4c ", '*');
					}
					else
					{
						//cout << _matrix[i][j] << " ";
						printf("%4d ", _matrix[i][j]);
					}
				}
				cout << endl;
			}
			cout << endl;

		}

		/*void BFS(const V& src)
		{
			size_t srci = GetVertexIndex(src);
			queue<int> q;
			vector<boll> visited(_vertexs.size(), false);
			q.push(srci);
			visited[srci] = true;

			while(!q.empty())
			{
				int front = q.front();
				q.pop();
				cout << front <<":" << _vertexs[front] << endl;

				for (size_t i = 0; i < _vertexs.size(); ++i)
				{
					if (_matrix[front][i] != MAX_W)
					{
						if (visited[i] == false)
						{
							q.push(i);
							visited[i] = true;

						}
					}
				}

			}
			cout << endl;

		}*/
		void BFS(const V& src)
		{
			size_t srci = GetVertexIndex(src);
			queue<int> q;
			vector<bool> visited(_vertexs.size(), false);
			q.push(srci);
			visited[srci] = true;
			int levelSize = 1;

			while (!q.empty())
			{
				for (int i = 0; i < levelSize; ++i)
				{
					int front = q.front();
					q.pop();
					cout << front << ":" << _vertexs[front] << " ";

					for (size_t i = 0; i < _vertexs.size(); ++i)
					{
						if (_matrix[front][i] != MAX_W)
						{
							if (visited[i] == false)
							{
								q.push(i);
								visited[i] = true;

							}
						}
					}
				}
				cout << endl;
				levelSize = q.size();


			}
			cout << endl;

		}


		void _DFS(size_t srci, vector<bool>& visited)
		{
			cout << srci << ":" << _vertexs[srci] << endl;
			visited[srci] = true;
			//找一个相邻的顶点，深度访问
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				if (_matrix[srci][i] != MAX_W && visited[i] == false)
				{
					_DFS(i, visited);
				}
			}

		}

		void DFS(const V& src)
		{
			size_t srci = GetVertexIndex(src);
			vector<bool> visited(_vertexs.size(), false);
			_DFS(srci, visited);


		}

		struct Edge
		{
			size_t _srci;
			size_t _dsti;
			W _w;

			Edge(size_t srci, size_t dsti, const W& w)
				:_srci(srci)
				, _dsti(dsti)
				, _w(w)
			{}

			bool operator>(const Edge& e) const
			{
				return _w > e._w;
			}
		};

		W Kruskal(self& minTree)
		{
			size_t n = _vertexs.size();

			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				minTree._matrix[i].resize(n, MAX_W);

			}

			priority_queue<Edge, vector<Edge>, greater<Edge>> minque;
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					if (i < j && _matrix[i][j] != MAX_W)
					{
						minque.push(Edge(i, j, _matrix[i][j]));
					}
				}
			}

			//选出n-1条边
			int size = 0;
			W totalW = W();
			UnionFindSet ufs(n);
			while (!minque.empty())
			{
				Edge min = minque.top();
				minque.pop();

				if (!ufs.InSet(min._srci, min._dsti))
				{
					cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] <<
						":" << _matrix[min._srci][min._dsti] << "->" << min._w << endl;
					minTree._AddEdge(min._srci, min._dsti, min._w);
					ufs.Union(min._srci, min._dsti);
					++size;
					totalW += min._w;
				}
				else
				{
					cout << "构成环 了";
					cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] <<
						":" << _matrix[min._srci][min._dsti] << "->" << min._w << endl;
				}

			}
			if (size == n - 1)
			{
				return totalW;
			}
			else
			{
				return W();
			}

		}

		W Prim(self& minTree, const W& src)
		{
			size_t srci = GetVertexIndex(src);
			//初始化最小生成树
			size_t n = _vertexs.size();
			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				minTree._matrix[i].resize(n, MAX_W);
			}
			//
			//set<int> X;
			//set<int> Y;
			//X.insert(srci);
			//for (size_t i = 0; i < n; ++i)
			//{
			//	if (i != srci)
			//	{
			//		Y.insert(i);
			//	}
			//}
			vector<bool> X(n, false);
			vector<bool> Y(n, true);
			X[srci] = true;
			Y[srci] = false;
			//入所有当前节点连接的边
			priority_queue<Edge, vector<Edge>, greater<Edge>> minq;
			for (size_t i = 0; i < n; ++i)
			{
				if (_matrix[srci][i] != MAX_W)
				{
					//入边
					minq.push(Edge(srci, i, _matrix[srci][i]));
				}
			}


			size_t size = 0;
			W totalw = W();
			while (!minq.empty())
			{
				Edge min = minq.top();
				minq.pop();
				if (X[min._dsti])
				{
					cout << "构成环：";
				}
				else
				{
					minTree._AddEdge(min._srci, min._dsti, min._w);
					X[min._dsti] = true;
					Y[min._dsti] = false;
					++size;
					totalw += min._w;
					if (size == n - 1)
						break;
					for (size_t i = 0; i < n; ++i)
					{
						if (_matrix[min._dsti][i] != MAX_W && Y[i])
						{
							//入边
							minq.push(Edge(srci, i, _matrix[min._dsti][i]));
						}
					}
				}


			}
			if (size == n - 1)
			{
				return totalw;
			}
			else
			{
				return W();
			}

		}

		void PrintShortPath(const V& src, const vector<W>& dist, const vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			for (size_t i = 0; i < n; ++i)
			{
				if (i != srci)
				{
					vector<int> path;
					size_t parenti = i;
					while (pPath[parenti] != srci)
					{
						path.push_back(parenti);
						parenti = pPath[parenti];

					}
					path.push_back(srci);
					reverse(path.begin(), path.end());
					for (auto index : path)
					{
						cout << _vertexs[index] << "->";

					}
					cout << endl;
				}
			}
		}

		void Dijkstra(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);

			dist[srci] = 0;
			pPath[srci] = srci;
			vector<bool> S(n, false);//已经确定的顶点
			for (size_t j = 0; j < n; ++j)
			{
				//选顶点，更新
				int u = 0;
				W min = MAX_W;
				for (size_t i = 0; i < n; ++i)
				{
					if (S[i] == false && dist[i] < min)
					{
						u = i;
						min = dist[i];
					}
				}
				S[u] = true;
				//松弛更新 srci->u   u-> * 
				for (size_t v = 0; v < n; ++v)
				{
					if (_matrix[u][v] != MAX_W
						&& dist[u] + _matrix[u][v] < dist[v])
					{
						dist[v] = dist[u] + _matrix[u][v] < dist[v];
						pPath[v] = u;
					}
				}


			}


		}

	private:
		vector<V> _vertexs; //顶点
		map<V, int> _indexMap;//顶点映射下标
		vector<vector<W>> _matrix; //邻接矩阵

	};

	void TestGraphMinTree()
	{
		const char* str = "abcdefghi";
		Graph<char, int> g(str, strlen(str));
		g.AddEdge('a', 'b', 4);
		g.AddEdge('a', 'h', 8);
		//g.AddEdge('a', 'h', 9);
		g.AddEdge('b', 'c', 8);
		g.AddEdge('b', 'h', 11);
		g.AddEdge('c', 'i', 2);
		g.AddEdge('c', 'f', 4);
		g.AddEdge('c', 'd', 7);
		g.AddEdge('d', 'f', 14);
		g.AddEdge('d', 'e', 9);
		g.AddEdge('e', 'f', 10);
		g.AddEdge('f', 'g', 2);
		g.AddEdge('g', 'h', 1);
		g.AddEdge('g', 'i', 6);
		g.AddEdge('h', 'i', 7);
		Graph<char, int> kminTree;
		cout << "Kruskal:" << g.Kruskal(kminTree) << endl;
		kminTree.Print();
		Graph<char, int> pminTree;
		cout << "Prim:" << g.Prim(pminTree, 'a') << endl;
		pminTree.Print();
	}
	void TestGraphDBFS()
	{
		string a[] = { "张三", "李四", "王五", "赵六", "周七" };
		Graph<string, int> g1(a, sizeof(a) / sizeof(string));
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.AddEdge("王五", "周七", 30);
		g1.Print();
		g1.BFS("张三");
		g1.DFS("张三");
	}
	void TestGraphDijkstra()
	{
		const char* str = "syztx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 10);
		g.AddEdge('s', 'y', 5);
		g.AddEdge('y', 't', 3);
		g.AddEdge('y', 'x', 9);
		g.AddEdge('y', 'z', 2);
		g.AddEdge('z', 's', 7);
		g.AddEdge('z', 'x', 6);
		g.AddEdge('t', 'y', 2);
		g.AddEdge('t', 'x', 1);
		g.AddEdge('x', 'z', 4);
		vector<int> dist;
		vector<int> parentPath;
		g.Dijkstra('s', dist, parentPath);
		g.PrintShortPath('s', dist, parentPath);
	}


}





namespace link_table
{
	template<class W>
	struct Edge
	{
		int _dsti;
		//int _srci;
		W _w;
		Edge<W>* _next;

		Edge( int dsti , const W& w)
			:_dsti(dsti)
			,_w(w)
			,_next(nullptr)
		{}
	};

	template<class V, class W, W  MAX_W = INT_MAX, bool Direction = false>
	class Graph
	{
		typedef Edge<W> Edge;
	public:
		Graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}
			_tables.resize(n,nullptr);
		}

		size_t GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);
			if (it != _indexMap.end())
			{
				return it->second;
			}
			else
			{
				throw invalid_argument("顶点不存在");
				return -1;
			}
		}

		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			Edge* eg = new Edge(dsti,w);
			eg->_next = _tables[srci];
			_tables[srci] = eg;
			
			if (Direction == false)
			{
				Edge* eg = new Edge(srci, w);
				eg->_next = _tables[dsti];
				_tables[dsti] = eg;
			}

		}

		void Print()
		{
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			for (size_t i = 0; i < _tables.size(); i++)
			{
				cout << _vertexs[i] << "[" << i << "]->";
				Edge* cur = _tables[i];
				while (cur)
				{
					cout << _vertexs[cur->_dsti] << "[" << cur->_dsti <<"]" << cur->_w << "->";
					cur = cur->_next;
								
				}
				cout<<" nullptr" << endl;
			}

		}

	private:
		vector<V> _vertexs; //顶点
		map<V, int> _indexMap;//顶点映射下标
		vector<Edge*> _tables; //邻接矩阵

	};
	void TestGraph1()
	{
		Graph<char, int, true> g("0123", 4);
		g.AddEdge('0', '1', 1);
		g.AddEdge('0', '3', 4);
		g.AddEdge('1', '3', 2);
		g.AddEdge('1', '2', 9);
		g.AddEdge('2', '3', 8);
		g.AddEdge('2', '1', 5);
		g.AddEdge('2', '0', 3);
		g.AddEdge('3', '2', 6);
		g.Print();


	
		string a[] = { "张三", "李四", "王五", "赵六" };
		Graph<string, int> g1(a, 4);
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);

		g1.Print();
	}
}
