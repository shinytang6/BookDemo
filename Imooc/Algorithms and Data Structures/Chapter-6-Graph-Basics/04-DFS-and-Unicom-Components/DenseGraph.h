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


	void show(){
		
		for(int i=0; i<n; i++){
			cout<<"vertex "<<i<<":\t";
			for(int j=0; j<g[i].size(); j++)
				cout<<g[i][j]<<"\t";
			cout<<endl;
		}
	}

	// �ڱߵ�����, ����һ��ͼ��һ������
	// ���������ͼ�к�����������������ж���
	class adjIterator{
	private:
		DenseGraph &G;   // ͼG������
		int v;
		int index;

	public:
		adjIterator(DenseGraph &graph, int v):G(graph){
			this->v = v;	
			this->index = -1;	// ������-1��ʼ, ��Ϊÿ�α�������Ҫ����һ��next()
		}

		int begin(){
			
			// ������-1��ʼ, ��Ϊÿ�α�������Ҫ����һ��next()
			index = -1;
			return next();
		}

		// ����ͼG���붥��v�����ӵ���һ������
		int next(){

			// �ӵ�ǰindex��ʼ�������, ֱ���ҵ�һ��g[v][index]Ϊtrue
			for( index += 1; index <G.g[v].size(); index++)
				if(G.g[v][index])
					return index;
			return -1;
		}

		// �鿴�Ƿ��Ѿ���������ͼG���붥��v�����ӵ����ж���
		bool end(){
			return index >= G.g[v].size();
			// return index >= G.V();
		}

	};
};