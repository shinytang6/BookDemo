#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "BellmanFord.h"

using namespace std;

// ����Bellman-Ford�㷨
int main() {

    string filename = "testG2.txt";		// ������Ȩ��
    // string filename = "testG_negative_circle.txt";	// ����Ȩ��
    int V = 5;

    SparseGraph<int> g = SparseGraph<int>(V, true);
	// ���������ͼ��ֻҪ��һ���ߴ���Ȩ�������Ǹ�Ȩ�����������ڸ�Ȩ������Dijkstra�㷨Ч�ʸ���
	// Dijkstra�㷨���Ӷ�ΪO(ElogV), Bellman-Ford�㷨���Ӷ�ΪO(EV)
	// SparseGraph<int> g = SparseGraph<int>(V, false);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout<<"Test Bellman-Ford:"<<endl<<endl;

    int s = 0;
    BellmanFord<SparseGraph<int>, int> bellmanFord(g, s);
    if( bellmanFord.negativeCycle() )
        cout<<"The graph contain negative cycle!"<<endl;
    else
        for( int i = 0 ; i < V ; i ++ ) {
            if(i == s)
                continue;

            if (bellmanFord.hasPathTo(i)) {
                cout << "Shortest Path to " << i << " : " << bellmanFord.shortestPathTo(i) << endl;
                bellmanFord.showPath(i);
            }
            else
                cout << "No Path to " << i << endl;

            cout << "----------" << endl;
        }

    return 0;
}