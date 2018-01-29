#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

// ʹ��BellmanFord�㷨�����·��
template<typename Graph, typename Weight>
class BellmanFord{

private:
	Graph &G;	// ͼ������
	int s;		// ��ʼ��

	Weight *distTo;	// distTo[i]�洢����ʼ��s��i�����·������
	vector<Edge<Weight>*> from; // from[i]��¼���·����, ����i��ı�����һ����
								// ���������ָ��������·��
	bool hasNegativeCycle;		// ���ͼ���Ƿ��и�Ȩ��

	// �ж�ͼ���Ƿ��и�Ȩ��
	bool detectNegativeCycle(){
		for( int i = 0 ; i < G.V() ; i ++ ){
                typename Graph::adjIterator adj(G,i);
                for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() )
                    if( !from[w->w()] || distTo[e->v()] + e->wt() < distTo[e->w()] ){
                       return true;
                    }
            }
		return false;
	}

public:
	// ���캯��, ʹ��BellmanFord�㷨�����·��
	BellmanFord(Graph &graph, int s):G(graph){
		
		this->s = s;

		distTo = new Weight[G.V()];
		// ��ʼ�����еĽڵ�s�����ɴ�, ��from��������ʾ
		for(int i=0; i<G.V(); i++){
			from.push_back(NULL);
		}

		// Bellman-Ford
		// int��double�ͳ�ʼ��Ϊ0
		distTo[s] = Weight();

		// ����V-1��ѭ��, ÿһ��ѭ���������㵽�������е�, ���ʹ��pass���ɵ������̾���
		for( int pass = 1 ; pass < G.V() ; pass ++ ){

            // ÿ��ѭ���ж����еı߽���һ���ɳڲ���
            // �������бߵķ�ʽ���ȱ������еĶ���, Ȼ����������ж������ڵ����б�
            for( int i = 0 ; i < G.V() ; i ++ ){
                // ʹ������ʵ�ֵ��ڱߵ��������������ж������ڵ����б�
                typename Graph::adjIterator adj(G,i);
                for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() )
                    // ����ÿһ���������ж�e->v()�ɴ�
                    // ֮�����e->w()��ǰû�е������ ��Ȼ���ǿ��Ը���distTo[e->w()]
                    // ����e->w()��ǰ��Ȼ�����, ����ͨ�����e���ǿ��Ի��һ�����̵ľ���, �����Խ���һ���ɳڲ���, ����Ҳ���Ը���distTo[e->w()]
                    if( !from[w->w()] || distTo[e->v()] + e->wt() < distTo[e->w()] ){
                        distTo[e->w()] = distTo[e->v()] + e->wt();
                        from[e->w()] = e;
                    }
            }
        }

		hasNegativeCycle = detectNegativeCycle();

	}

	~BellmanFord(){
		delete[] distTo;
	}

	// ����ͼ���Ƿ��и�Ȩ��
	bool negativeCycle(){
		return hasNegativeCycle;
	}

	// ���ش�s�㵽w������·������
	Weight shortestPathTo( int w){
		assert( w>=0 && w<G.V());
		assert( !hasNegativeCycle);
		return distTo[w];
	}

	// �жϴ�s�㵽w���Ƿ���ͨ
	bool hasPathTo( int w){
		assert( w>=0 && w<G.V());
		return marked[w];
	}

	 // Ѱ�Ҵ�s��w�����·��, ������·�������ıߴ����vec��
    void shortestPath( int w, vector<Edge<Weight>> &vec ){

        assert( w>=0 && w<G.V());
		assert( !hasNegativeCycle);

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

        assert( w>=0 && w<G.V());
		assert( !hasNegativeCycle);

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i].v()<<" -> ";
            if( i == vec.size()-1 )
                cout<<vec[i].w()<<endl;
        }
    }


};