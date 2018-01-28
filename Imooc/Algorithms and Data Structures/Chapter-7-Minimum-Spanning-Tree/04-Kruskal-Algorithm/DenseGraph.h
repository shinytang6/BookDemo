#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

// ����ͼ - �ڽӾ���
template <typename Weight>
class DenseGraph{

private:
	int n, m;  // �ڵ�ͱ���
	bool directed;	// �Ƿ�Ϊ����ͼ
	vector<vector<Edge<Weight> *>> g;	 // ͼ�ľ�������(��ά����������)

public:
	DenseGraph(int n, bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;

		// g��ʼ��Ϊn*n�ľ���, ÿһ��g[i][j]ָ��һ���ߵ���Ϣ, ��ʼ��ΪNULL
		for( int i =0; i<n ; i++)
			g.push_back(vector<Edge<Weight> *>(n, NULL));
	}

	~DenseGraph(){
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if( g[i][j] != NULL)
					delete g[i][j];
		
	}

	// ���ؽڵ����
	int V(){
		return n;
	}
	// ���رߵĸ���
	int E(){
		return m;
	}

	// ��ͼ�����һ����, ȨֵΪweight
	void addEdge(int v, int w, Weight weight){
		assert( v>=0 && v<n);
		assert( w>=0 && w<n);

		// �����v��w�Ѿ��б�, ɾ��������
		if(hasEdge(v, w)){
			delete g[v][w];
			if( !directed )
				delete g[w][v];
			m --;
		}

		g[v][w] = new Edge<Weight>(v, w, weight);
		if( !directed )
			g[w][v] = new Edge<Weight>(w, v, weight);

		m++;
	}

	// ��֤ͼ���Ƿ��д�v��w�ı�
	bool hasEdge( int v, int w){
		assert( v>=0 && v<n);
		assert( w>=0 && w<n);
		return g[v][w] != NULL;
	}

	// ��ʾͼ����Ϣ
	void show(){
		
		for(int i=0; i<n; i++){
			cout<<"vertex "<<i<<":\t";
			for(int j=0; j<g[i].size(); j++)
				if( g[i][j])
					cout<<g[i][j]->wt()<<"\t";
				else
					cout<<"NULL"<<"\t";
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

		 Edge<Weight>* begin(){
			
			// ������-1��ʼ, ��Ϊÿ�α�������Ҫ����һ��next()
			index = -1;
			return next();
		}

		// ����ͼG���붥��v�����ӵ���һ������
		 Edge<Weight>* next(){

			// �ӵ�ǰindex��ʼ�������, ֱ���ҵ�һ��g[v][index]Ϊtrue
			for( index += 1; index <G.g[v].size(); index++)
				if(G.g[v][index])
					return G.g[v][index];
			return NULL;
		}

		// �鿴�Ƿ��Ѿ���������ͼG���붥��v�����ӵ����ж���
		bool end(){
			return index >= G.g[v].size();
			// return index >= G.V();
		}

	};
};