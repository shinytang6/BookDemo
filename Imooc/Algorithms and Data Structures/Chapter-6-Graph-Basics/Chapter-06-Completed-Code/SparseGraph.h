#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稀疏图 - 邻接表
class SparseGraph{

private:
	int n, m;	// 节点数和边数
	bool directed;	// 是否为有向图
	vector<vector<int>> g;	// 图的具体数据

public:
	SparseGraph(int n, bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;

		// g初始化为n个空的vector, 表示每一个g[i]都为空, 即没有任和边
        // g = vector<vector<int>>(n, vector<int>());

		for(int i=0; i<n; i++)
			g.push_back( vector<int>());
	}

	~SparseGraph(){}

	// 返回节点个数
	int V(){
		return n;
	}

	// 返回边的个数
	int E(){
		return m;
	}

	// 向图中添加一个边
	// 这里没有加平行边的判断，因为hasEdge的时间复杂度为O(n)，成本较高，故通常情况下邻接表允许有平行边
	void addEdge(int v, int w){

		assert( v>=0 && v<n);
		assert( w>=0 && w<n);
	
		g[v].push_back(w);
		// 增加了对自环边的判断
		if( v!=w && !directed)
			g[w].push_back(v);

		m++;
	}

	// 验证图中是否有从v到w的边
	bool hasEdge(int v, int w){
		assert( v>=0 && v<n);
		assert( w>=0 && w<n);

		for(int i=0; i<g[v].size(); i++)
			if(g[v][i] == w)
				return true;
		return false;
	}

	void show(){
		
		for(int i=0; i<n; i++){
			cout<<"vertex "<<i<<":\t";
			for(int j=0; j<g[i].size(); j++)
				cout<<g[i][j]<<"\t";
			cout<<endl;
		}
	}


	// 邻边迭代器, 传入一个图和一个顶点
	// 迭代在这个图中和这个顶点相连的所有顶点
	class adjIterator{
	private:
		SparseGraph &G;
		int v;
		int index;
	public:
		adjIterator(SparseGraph &graph, int v):G(graph){
			this->v = v;	
			this->index = 0;
		}

		// 返回图G中与顶点v相连接的第一个顶点
		int begin(){
			index = 0;
			if(G.g[v].size())
				return G.g[v][index];
			return -1;
		}

		// 返回图G中与顶点v相连接的下一个顶点
		int next(){
			index++;
			if( index < G.g[v].size())
				return G.g[v][index];
			return -1;
		}

		// 查看是否已经迭代完了图G中与顶点v相连接的所有顶点
		bool end(){
			return index >= G.g[v].size();
		}

	};

};