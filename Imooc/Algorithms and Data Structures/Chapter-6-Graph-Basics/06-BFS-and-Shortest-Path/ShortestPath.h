#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

// Ѱ����Ȩͼ�����·��
template<typename Graph>
class ShortestPath{

private:
	Graph &G;	// ͼ������
	bool* visited;   // ��¼dfs�Ĺ����нڵ��Ƿ񱻷���
	int* from;	// ��¼·��, from[i]��ʾ���ҵ�·����i����һ���ڵ�
	int* ord;	// ��¼·���нڵ�Ĵ���ord[i]��ʾi�ڵ���·���еĴ���
	int s;	// source(��ʼ��)

public:
	ShortestPath( Graph &g, int s):G(g){

		assert( s>=0 && s<G.V() );
		visited = new bool[G.V()];
		from = new int[G.V()];
		ord = new int[G.V()];

		for(int i=0; i<G.V(); i++){
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}
		this->s = s;

		queue<int> q;

		// ����ͼ���·���㷨, ��s��ʼ������ȱ�������ͼ
		q.push(s);
		visited[s] = true;
		ord[s] = 0;
		while( !q.empty() ){
			int v = q.front();
			q.pop();

			typename Graph::adjIterator adj(G, v);
			for(int i = adj.begin(); !adj.end(); i = adj.next()){
				if( !visited[i]){
					q.push(i);
					visited[i] = true;
					from[i] = v;
					ord[i] = ord[v] + 1; 
				}
			}

		}
	}

	~ShortestPath(){
		delete[] visited;
		delete[] from;
		delete[] ord;
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

	// �鿴��s�㵽w������·������
	int length(int w){
		assert( w>=0 && w<G.V() );
		return ord[w];
	}
};