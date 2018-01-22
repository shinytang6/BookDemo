#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
using namespace std;

// ·����ѯ
template<typename Graph>
class Path{

private:
	Graph &G;	// ͼ������
	bool* visited;   // ��¼dfs�Ĺ����нڵ��Ƿ񱻷���
	int* from;	// ��¼·��, from[i]��ʾ���ҵ�·����i����һ���ڵ�
	int s;	// source(��ʼ��)

	// ͼ��������ȱ���
	void dfs( int v ){
	
		visited[v] = true;

		typename Graph::adjIterator adj(G, v);
		for(int i = adj.begin(); !adj.end(); i = adj.next()){
			if( !visited[i]){
				from[i] = v;
				dfs(i);
			}
		}

	}

public:
	Path( Graph &g, int s):G(g){

		assert( s>=0 && s<G.V() );
		visited = new bool[G.V()];
		from = new int[G.V()];

		for(int i=0; i<G.V(); i++){
			visited[i] = false;
			from[i] = -1;
		}
		this->s = s;

		// Ѱ·�㷨
		dfs(s);
	}

	~Path(){
		delete[] visited;
		delete[] from;
	}

	// ��ѯ��s�㵽w���Ƿ���·��
	bool hasPath(int w){
		assert( w>=0 && w<G.V() );
		return visited(w);
	}

	// ��ѯ��s�㵽w���·��, �����vec��
	void path(int w, vector<int> &vec){
		
		stack<int> s;
		// ͨ��from����������ҵ���s��w��·��, ��ŵ�ջ��
		int p = w;
		while(p!=-1){
			s.push(p);
			p = from[p];
		}

		// ��ջ������ȡ��Ԫ��, ���˳��Ĵ�s��w��·��
		vec.clear();
		while( !s.empty()){
			vec.push_back(s.top());
			s.pop();
		}
	}

	// ��ӡ����s�㵽w���·��
	void showPath(int w){
	
		vector<int> vec;
		path(w, vec);
		for(int i=0; i<vec.size(); i++){
			cout<<vec[i];
			if( i == vec.size() - 1)
				cout<<endl;
			else
				cout<<" ->";
		
		}
	}
};