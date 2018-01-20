#include <iostream>
#include <ctime>
#include "UnionFind1.h"

using namespace std;

namespace UnionFindTestHelper{

	void testUF1(int n){
	
		srand(unsigned(time(NULL)));
		UF1::UnionFind uf = UF1::UnionFind(n);

		time_t startTime = clock();

		// ����n�β���, ÿ�����ѡ������Ԫ�ؽ��кϲ�����
		for(int i=0; i<n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf.unionElements(a,b);
		}

		// �ٽ���n�β���, ÿ�����ѡ������Ԫ��, ��ѯ�����Ƿ�ͬ��һ������
		for(int i=0; i<n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf.isConnected(a,b);
		}
		time_t endTime = clock();

		cout<<"UF1, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
	
	}

}