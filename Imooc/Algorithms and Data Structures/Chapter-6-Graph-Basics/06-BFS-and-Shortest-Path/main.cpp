#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"
using namespace std;

// ������Ȩͼ���·���㷨
int main(){


    string filename2 = "testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph2(g, filename2);
    g.show();
	cout<<endl;


	// �Ƚ�ʹ��������ȱ����͹�����ȱ������·���Ĳ�ͬ
    // ������ȱ�����õ�����Ȩͼ�����·��
	Path<SparseGraph> dfs(g,0);
	cout<<"DFS : ";
	dfs.showPath(6);

	ShortestPath<SparseGraph> bfs(g,0);
	cout<<"BFS : ";
	bfs.showPath(6);
  
	return 0;
}