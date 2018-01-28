#include <iostream>
#include <iomanip>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Dijkstra.h"
using namespace std;

// �������ǵ�Dijkstra���·���㷨
int main(){


    string filename = "testG3.txt";
    int V = 8;

    SparseGraph<int> g = SparseGraph<int>(V, true);
    // Dijkstra���·���㷨ͬ������������ͼ
    //SparseGraph<int> g = SparseGraph<int>(V, false);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout<<"Test Dijkstra:"<<endl<<endl;
    Dijkstra<SparseGraph<int>, int> dij(g,0);
    for( int i = 0 ; i < V ; i ++ ){
        if(dij.hasPathTo(i)){
            cout<<"Shortest Path to "<<i<<" : "<<dij.shortestPathTo(i)<<endl;
            dij.showPath(i);
        }
        else
            cout<<"No Path to "<<i<<endl;

        cout<<"----------"<<endl;
    }
  
	return 0;
}