#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

// Dijkstra�㷨�����·��
template<typename Graph, typename Weight>
class Dijkstra{

private:
	Graph &G;	// ͼ������
	int s;		// ��ʼ��

	Weight *distTo;	// distTo[i]�洢����ʼ��s��i�����·������
	bool *marked;	// �������, ���㷨���й����б�ǽڵ�i�Ƿ񱻷���
	vector<Edge<Weight>*> from; // from[i]��¼���·����, ����i��ı�����һ����
								// ���������ָ��������·��


public:
	// ���캯��, ʹ��Dijkstra�㷨�����·��
	Dijkstra(Graph &graph, int s):G(graph){
		
		this->s = s;

		distTo = new Weight[G.V()];
		marked = new bool[G.V()];
		for(int i=0; i<G.V(); i++){
			distTo[i] = Weight();
			marked[i] = false;
			from.push_back(NULL);
		}

		// ʹ�������Ѽ�¼��ǰ�ҵ��ĵ���ÿ���������̾���
		IndexMinHeap<Weight> ipg(G.V());

		distTo[s] = Weight();
		marked[s] = true;
		ipq.insert(s, distTo[s] );
		while( !ipq.isEmpty()){
			int v = ipq.extractMinIndex(); 

			// distTo[v]����s��v����̾���
            marked[v] = true;

            // ��v���������ڽڵ���и���
			// �����㷨
			// �ɳڲ���
            typename Graph::adjIterator adj(G, v);
            for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() ){
				int w = e->other(v);
				// �����s�㵽w������·����û���ҵ�
				if( !marked[w] ){
					// ���w����ǰû�з��ʹ�,
                    // ���߷��ʹ�, ����ͨ����ǰ��v�㵽w��������, ����и���
					if( from[w] == NULL || distTo[v] + e->wt() < distTo[w]){
						distTo[w] = distTo[v] + e->wt();
						from[w] = e;
						if( ipq.contain(w) )
                            ipq.change(w, distTo[w] );
                        else
                            ipq.insert(w, distTo[w] );
					}
				
				}

			}
		}

	}

	~Dijkstra(){
		delete[] distTo;
		delete[] marked;
	}

	// ���ش�s�㵽w������·������
	Weight shortestPathTo( int w){
		return distTo[w];
	}

	// �жϴ�s�㵽w���Ƿ���ͨ
	bool hasPathTo( int w){
		return marked[w];
	}

	 // Ѱ�Ҵ�s��w�����·��, ������·�������ıߴ����vec��
    void shortestPath( int w, vector<Edge<Weight>> &vec ){

        assert( w >= 0 && w < G.V() );
        assert( hasPathTo(w) );

        // ͨ��from����������ҵ���s��w��·��, ��ŵ�ջ��
        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while( e->v() != this->s ){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);

        // ��ջ������ȡ��Ԫ��, ���˳��Ĵ�s��w��·��
        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
    }

    // ��ӡ����s�㵽w���·��
    void showPath(int w){

        assert( w >= 0 && w < G.V() );
        assert( hasPathTo(w) );

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i].v()<<" -> ";
            if( i == vec.size()-1 )
                cout<<vec[i].w()<<endl;
        }
    }


};