#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

// ϡ��ͼ - �ڽӱ�
template <typename Weight>
class SparseGraph{

private:
	int n, m;	// �ڵ����ͱ���
	bool directed;	// �Ƿ�Ϊ����ͼ
	vector<vector<Edge<Weight> *>> g;	// ͼ�ľ�������

public:
	SparseGraph(int n, bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;

		// g��ʼ��Ϊn���յ�vector, ��ʾÿһ��g[i]��Ϊ��, ��û���κα�
		for(int i=0; i<n; i++)
			g.push_back( vector<Edge<Weight> *>() );
	}

	~SparseGraph(){
		for(int i=0; i<n; i++)
			for(int j=0; j<g[i].size(); j++)
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
	
		g[v].push_back(new Edge<Weight>(v,w,weight));
		// �����˶��Ի��ߵ��ж�
		if( v!=w && !directed)
			g[w].push_back(new Edge<Weight>(w,v,weight));

		m++;
	}

	// ��֤ͼ���Ƿ��д�v��w�ı�
	bool hasEdge(int v, int w){
		assert( v>=0 && v<n);
		assert( w>=0 && w<n);

		for(int i=0; i<g[v].size(); i++)
			if(g[v][i]->other(v) == w)
				return true;
		return false;
	}

	// ��ʾͼ����Ϣ
	void show(){
		
		for(int i=0; i<n; i++){
			cout<<"vertex "<<i<<":\t";
			for(int j=0; j<g[i].size(); j++)
				cout<<"( to:"<<g[i][j]->w()<<",wt:"<<g[i][j]->wt()<<")\t";
			cout<<endl;
		}
	}


	// �ڱߵ�����, ����һ��ͼ��һ������
	// ���������ͼ�к�����������������ж���
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

		// ����ͼG���붥��v�����ӵĵ�һ������
		Edge<Weight>* begin(){
			index = 0;
			if(G.g[v].size())
				return G.g[v][index];
			return NULL;
		}

		// ����ͼG���붥��v�����ӵ���һ������
		Edge<Weight>* next(){
			index++;
			if( index < G.g[v].size())
				return G.g[v][index];
			return NULL;
		}

		// �鿴�Ƿ��Ѿ���������ͼG���붥��v�����ӵ����ж���
		bool end(){
			return index >= G.g[v].size();
		}

	};

};