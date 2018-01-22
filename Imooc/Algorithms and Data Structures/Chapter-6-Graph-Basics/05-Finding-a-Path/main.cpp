#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
using namespace std;

// 测试图的联通分量算法
int main(){


	// TestG2.txt
    string filename2 = "testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph2(g, filename2);
    g.show();
	cout<<endl;

	Path<SparseGraph> dfs(g,0);
	cout<<"DFS : ";
	dfs.showPath(6);
  
	return 0;
}