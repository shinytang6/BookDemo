#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "MinHeap.h"

using namespace std;

// ʹ��LazyPrim�㷨��ͼ����С������
template<typename Graph, typename Weight>
class LazyPrimMST{

private:
	Graph &G;	// ͼ������
	MinHeap<Edge<Weight>> pq;	// ��С��, �㷨�������ݽṹ
	bool* marked;	// �������, ���㷨���й����б�ǽڵ�i�Ƿ񱻷���
	vector<Edge<Weight>> mst;	// ��С�����������������б�
	Weight mstWeight;	// ��С��������Ȩֵ

	//  ���ʽڵ�v
	void visit(int v){
	
		assert( !marked[v]);
		marked[v] = true;

		// ���ͽڵ�v�����ӵ�����δ���ʵı߷�����С����
		typename Graph::adjIterator adj(G, v);
		for(Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()){
			if( !marked[e->other(v)])
				pq.insert(*e);
		
		}
	}

public:
	LazyPrimMST(Graph &graph):G(graph), pq(MinHeap<Edge<Weight>>(graph.E())){
		marked = new bool[G.V()];
		for(int i=0; i<G.V(); i++)
			marked[i] = false;
		mst.clear();

		// Lazy Prim
		visit(0);
		while( !pq.isEmpty()){
			// ʹ����С���ҳ��Ѿ����ʵı���Ȩֵ��С�ı�
			Edge<Weight> e = pq.extractMin();
			// ��������ߵ����˶��Ѿ����ʹ���, ���ӵ�������
			if( marked[e.v()] == marked[e.w()] )
				continue;
			// ����, ��������Ӧ�ô�������С��������
			mst.push_back(e);

			// ���ʺ����������ӵĻ�û�б����ʹ��Ľڵ�
			if( !marked[e.v()] )
				visit(e.v());
			else
				visit(e.w());
		}

		// ������С��������Ȩֵ
		mstWeight = mst[0].wt();
		for(int i =1; i<mst.size(); i++)
			mstWeight += mst[i].wt();

	}

	~LazyPrimMST(){
		delete[] marked;
	}

	// ������С�����������б�
	vector<Edge<Weight>> mstEdges(){
		return mst;
	}

	// ������С�����������б�
	Weight result(){
		return mstWeight;
	}
};