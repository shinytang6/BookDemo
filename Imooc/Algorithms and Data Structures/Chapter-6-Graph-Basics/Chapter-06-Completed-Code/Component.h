#include <iostream>
#include <cassert>
using namespace std;

// ����Ȩͼ����ͨ����
template<typename Graph>
class Component{

private:
	Graph &G;	// ͼ������
	bool* visited;   // ��¼dfs�Ĺ����нڵ��Ƿ񱻷���
	int* id;  // ÿ���ڵ�����Ӧ����ͨ�������
	int ccount;   // ��¼��ͨ��������

	// ͼ��������ȱ���
	void dfs( int v ){
	
		visited[v] = true;
		id[v] = ccount;
		typename Graph::adjIterator adj(G, v);
		for(int i = adj.begin(); !adj.end(); i = adj.next())
			if( !visited[i])
				dfs(i);

	}

public:
	Component( Graph &g ):G(g){

		visited = new bool[G.V()];
		id = new int[G.V()];
		ccount = 0;
		for(int i=0; i<G.V(); i++){
			visited[i] = false;
			id[i] = -1;
		}
	
		// ��ͼ����ͨ����
		for(int i=0; i<G.V(); i++){
			if( !visited[i]){
				dfs(i);
				ccount++;
			}
		}
	}

	~Component(){
		delete[] visited;
		delete[] id;
	}

	// ����ͼ����ͨ��������
	int count(){
		return ccount;
	}

	// ��ѯ��v�͵�w�Ƿ���ͨ
	bool isConnected(int v, int w){
		assert( v>=0 && v<G.v());
		assert( w>=0 && w<G.v());
		return id[v] == id[w];
	}
};