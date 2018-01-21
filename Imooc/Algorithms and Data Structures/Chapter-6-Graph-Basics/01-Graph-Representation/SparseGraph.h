#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// ϡ��ͼ - �ڽӱ�
class SparseGraph{

private:
	int n, m;	// �ڵ����ͱ���
	bool directed;	// �Ƿ�Ϊ����ͼ
	vector<vector<int>> g;	// ͼ�ľ�������

public:
	SparseGraph(int n, bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;

		// g��ʼ��Ϊn���յ�vector, ��ʾÿһ��g[i]��Ϊ��, ��û���κͱ�
        // g = vector<vector<int>>(n, vector<int>());

		for(int i=0; i<n; i++)
			g.push_back( vector<int>());
	}

	~SparseGraph(){}

	// ���ؽڵ����
	int V(){
		return n;
	}

	// ���رߵĸ���
	int E(){
		return m;
	}

	// ��ͼ�����һ����
	// ����û�м�ƽ�бߵ��жϣ���ΪhasEdge��ʱ�临�Ӷ�ΪO(n)���ɱ��ϸߣ���ͨ��������ڽӱ�������ƽ�б�
	void addEdge(int v, int w){

		assert( v>=0 && v<n);
		assert( w>=0 && w<n);
	
		g[v].push_back(w);
		// �����˶��Ի��ߵ��ж�
		if( v!=w && !directed)
			g[w].push_back(v);

		m++;
	}

	// ��֤ͼ���Ƿ��д�v��w�ı�
	bool hasEdge(int v, int w){
		assert( v>=0 && v<n);
		assert( w>=0 && w<n);

		for(int i=0; i<g[v].size(); i++)
			if(g[v][i] == w)
				return true;
		return false;
	}
};