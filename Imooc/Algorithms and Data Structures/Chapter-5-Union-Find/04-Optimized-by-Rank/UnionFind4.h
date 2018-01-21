#include <iostream>
#include <cassert>

using namespace std;

// ���İ�Union-Find
// ��������µ��������size���Ż����ܻ�ʹ���ĸ߶����Ӷ����Ǽ��٣�����������rank(���ĸ߶�)���Ż�
namespace UF4 {

	class UnionFind{

	private:
		int* parent; // parent[i]��ʾ��i��Ԫ����ָ��ĸ��ڵ�
		int* rank;   // rank[i]��ʾ��iΪ���ļ�������ʾ�����Ĳ���
		int count;   // ���ݸ���

	public:
		UnionFind(int n){
			count = n;
			parent = new int[n];
			rank = new int[n];

			for(int i=0; i<n; i++){
				parent[i] = i;
				rank[i] = 1;
			}
		}

		~UnionFind(){
			delete[] parent;
			delete[] rank;
		}

		// ���ҹ���, ����Ԫ��p����Ӧ�ļ��ϱ��
		// O(h)���Ӷ�, hΪ���ĸ߶�
		int find(int p){
			assert(p>=0 && p<count);
			// ����ȥ��ѯ�Լ��ĸ��׽ڵ�, ֱ��������ڵ�
			// ���ڵ���ص�: parent[p] == p
			while( p != parent[p])
				p = parent[p];
			return p;
		}

		// �鿴Ԫ��p��Ԫ��q�Ƿ�����һ������
		// O(h)���Ӷ�, hΪ���ĸ߶�
		bool isConnected(int p, int	q){
			return find(p) == find(q);
		}


		// �ϲ�Ԫ��p��Ԫ��q�����ļ���
		// O(h)���Ӷ�, hΪ���ĸ߶�
		void unionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);

			if(pRoot == qRoot)
				return;


			// ��������Ԫ����������Ԫ�ظ�����ͬ�жϺϲ�����
			// ��Ԫ�ظ����ٵļ��Ϻϲ���Ԫ�ظ�����ļ�����
			// ʹ���ĸ߶Ⱦ���С
			if(rank[pRoot] < rank[qRoot]){
				parent[pRoot] = qRoot;
			}
			else if(rank[pRoot] > rank[qRoot]){
				parent[qRoot] = pRoot;
			}
			else{	// rank[pRoot] == rank[qRoot]
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;	// ��ʱ��ά��rank��ֵ
			}

			
		}

	};

}