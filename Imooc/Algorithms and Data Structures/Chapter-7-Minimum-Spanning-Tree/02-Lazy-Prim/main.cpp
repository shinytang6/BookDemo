#include <iostream>
#include <iomanip>
#include "SparseGraph.h"
//#include "DenseGraph.h"
#include "ReadGraph.h"
#include "LazyPrimMST.h"
using namespace std;

// ������Ȩͼ���·���㷨
int main(){


    string filename = "testG3.txt";
    int V = 8;

    SparseGraph<double> g = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph(g, filename);

    // Test Lazy Prim MST
	// ����vs��ԭ��������лᱨ��
    cout<<"Test Lazy Prim MST:"<<endl;
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
    vector<Edge<double>> mst = lazyPrimMST.mstEdges();
    for( int i = 0 ; i < mst.size() ; i ++ )
        cout<<mst[i]<<endl;
    cout<<"The MST weight is: "<<lazyPrimMST.result()<<endl;

    cout<<endl;

  
	return 0;
}