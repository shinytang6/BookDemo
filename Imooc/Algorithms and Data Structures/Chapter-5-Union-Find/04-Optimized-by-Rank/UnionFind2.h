#include <iostream>
#include <cassert>

using namespace std;

// ��һ��Quick-Find���鼯�Ĳ�����unionElementsʱ�临�ӶȽϸ�
// �ڶ���Union-Find
namespace UF2 {

	class UnionFind{

	private:
		// �ڶ���Union-Find, ʹ��һ�����鹹��һ��ָ�򸸽ڵ����
		// parent[i]��ʾ��i��Ԫ����ָ��ĸ��ڵ�
		int* parent;   
		int count;   // ���ݸ���

	public:
		UnionFind(int n){
			count = n;
			parent = new int[n];
			// ��ʼ��, ÿһ��parent[i]ָ���Լ�, ��ʾÿһ��Ԫ���Լ��Գ�һ������
			for(int i=0; i<n; i++)
				parent[i] = i;
		}

		~UnionFind(){
			delete[] parent;
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

			// ����Ҳ����
			parent[pRoot] = qRoot;
	
		}

	};

}