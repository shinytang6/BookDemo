#include <iostream>
#include <iomanip>
#include "SparseGraph.h"
//#include "DenseGraph.h"
#include "ReadGraph.h"
using namespace std;

// 测试无权图最短路径算法
int main(){


    string filename = "testG3.txt";
    int V = 8;
	cout<<fixed<<setprecision(2);

	// 不知道为什么不能两个一起运行，单独运行都可以

	// Test Weighted Dense Graph
	/*DenseGraph<double> g1 = DenseGraph<double>(V, false);
	ReadGraph<DenseGraph<double>,double> readGraph1(g1, filename);
	g1.show();
	cout<<endl;*/

	// Test Weighted Sparse Graph
	SparseGraph<double> g2 = SparseGraph<double>(V, false);
	ReadGraph<SparseGraph<double>,double> readGraph2(g2, filename);
	g2.show();
	cout<<endl;
  
	return 0;
}