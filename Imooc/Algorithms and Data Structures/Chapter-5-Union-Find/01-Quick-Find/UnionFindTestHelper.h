#include <iostream>
#include <ctime>
#include "UnionFind1.h"

using namespace std;

namespace UnionFindTestHelper{

	void testUF1(int n){
	
		srand(unsigned(time(NULL)));
		UF1::UnionFind uf = UF1::UnionFind(n);

		time_t startTime = clock();

		// 进行n次操作, 每次随机选择两个元素进行合并操作
		for(int i=0; i<n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf.unionElements(a,b);
		}

		// 再进行n次操作, 每次随机选择两个元素, 查询他们是否同属一个集合
		for(int i=0; i<n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf.isConnected(a,b);
		}
		time_t endTime = clock();

		cout<<"UF1, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
	
	}

}