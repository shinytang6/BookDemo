#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"

using namespace std;

// 测试图的联通分量算法
int main(){

	// TestG1.txt
	string filename = "testG1.txt";

	SparseGraph g1( 13, false);
	ReadGraph<SparseGraph> readGraph1( g1, filename);
	Component<SparseGraph> component1(g1);
	cout<<"TestG1.txt, Component Count: "<<component1.count()<<endl;

	cout<<endl;

	// TestG2.txt
    string filename2 = "testG2.txt";
    DenseGraph g2 = DenseGraph(7, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename2);
    Component<DenseGraph> component2(g2);
    cout<<"TestG2.txt, Component Count: "<<component2.count()<<endl;

	return 0;
}