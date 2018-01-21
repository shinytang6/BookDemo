#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
using namespace std;

int main(){

	int N = 20;
	int M = 100;

	srand( unsigned(time(NULL)));

	// Sparse Graph
	SparseGraph g1(N, false);
	//SparseGraph g1 = SparseGraph(N, false);

	// O(E)(因为有平行边，取决于边数而不是点数)
	for(int i = 0; i < M; i++){
		int a = rand()%N;
		int b = rand()%N;
		g1.addEdge(a,b);
	}

	for(int v=0; v<N; v++){
		cout<<v<<" : ";
		SparseGraph::adjIterator adj( g1, v);
		for( int w = adj.begin(); !adj.end(); w=adj.next())
			cout<<w<<" ";
		cout<<endl;
	}

	cout<<endl;



	// Dense Graph
	DenseGraph g2(N, false);
	//DenseGraph g2 = DenseGraph(N, false);

	// O(V^2)
	for(int i = 0; i < M; i++){
		int a = rand()%N;
		int b = rand()%N;
		g2.addEdge(a,b);
	}

	for(int v=0; v<N; v++){
		cout<<v<<" : ";
		DenseGraph::adjIterator adj( g2, v);
		for( int w = adj.begin(); !adj.end(); w=adj.next())
			cout<<w<<" ";
		cout<<endl;
	}

	cout<<endl;
	return 0;
}