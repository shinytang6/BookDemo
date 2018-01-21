#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稠密图 - 邻接矩阵
class DenseGraph{

private:
	int n, m;  // 节点和边数
	bool directed;	// 是否为有向图
	vector<vector<bool>> g;	 // 图的具体数据(二维布尔型向量)

public:
	DenseGraph(int n, bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;

		// g初始化为n*n的布尔矩阵, 每一个g[i][j]均为false, 表示没有任和边
		// g = vector<vector<bool>>(n, vector<bool>(n, false));

		for( int i =0; i<n ; i++)
			g.push_back(vector<bool>(n, false));
	}

	~DenseGraph(){
	
	}

	// 返回节点个数
	int V(){
		return n;
	}
	// 返回边的个数
	int E(){
		return m;
	}

	// 向图中添加一条边
	void addEdge(int v, int w){
		assert( v>=0 && v<n);
		assert( w>=0 && w<n);

		if(hasEdge(v, w))
			return;

		g[v][w] = true;
		if( !directed )
			g[w][v] = true;

		m++;
	}

	// 验证图中是否有从v到w的边
	bool hasEdge( int v, int w){
		assert( v>=0 && v<n);
		assert( w>=0 && w<n);
		return g[v][w];
	}
};