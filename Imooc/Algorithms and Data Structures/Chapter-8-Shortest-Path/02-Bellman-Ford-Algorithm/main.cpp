#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "BellmanFord.h"

using namespace std;

// 测试Bellman-Ford算法
int main() {

    string filename = "testG2.txt";		// 不带负权环
    // string filename = "testG_negative_circle.txt";	// 带负权环
    int V = 5;

    SparseGraph<int> g = SparseGraph<int>(V, true);
	// 如果是无向图，只要有一条边带负权，就算是负权环，若不存在负权环，用Dijkstra算法效率更高
	// Dijkstra算法复杂度为O(ElogV), Bellman-Ford算法复杂度为O(EV)
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