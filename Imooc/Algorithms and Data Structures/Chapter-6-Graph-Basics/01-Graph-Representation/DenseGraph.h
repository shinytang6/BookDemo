#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// ����ͼ - �ڽӾ���
class DenseGraph{

private:
	int n, m;  // �ڵ�ͱ���
	bool directed;	// �Ƿ�Ϊ����ͼ
	vector<vector<bool>> g;	 // ͼ�ľ�������(��ά����������)

public:
	DenseGraph(int n, bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;

		// g��ʼ��Ϊn*n�Ĳ�������, ÿһ��g[i][j]��Ϊfalse, ��ʾû���κͱ�
		// g = vector<vector<bool>>(n, vector<bool>(n, false));

		for( int i =0; i<n ; i++)
			g.push_back(vector<bool>(n, false));
	}

	~DenseGraph(){
	
	}

	// ���ؽڵ����
	int V(){
		return n;
	}
	// ���رߵĸ���
	int E(){
		return m;
	}

	// ��ͼ�����һ����
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

	// ��֤ͼ���Ƿ��д�v��w�ı�
	bool hasEdge( int v, int w){
		assert( v>=0 && v<n);
		assert( w>=0 && w<n);
		return g[v][w];
	}
};