#include <iostream>
#include <cassert>

using namespace std;

// ·��ѹ�� Path Compression
// ǰ�漸���Ż��������union��������ģ���ʵfind����Ҳ�����Ż�
// �����ϲ��Ҹ��ڵ��ͬʱ�ɽ��ڵ�����Ų���Ӷ�ѹ�����ĸ߶�
// �����Union-Find
namespace UF5 {

	class UnionFind{

	private:
		// rank[i]��ʾ��iΪ���ļ�������ʾ�����Ĳ���
		// �ں����Ĵ�����, ���ǲ�����ά��rank������, Ҳ����rank��ֵ��·��ѹ���Ĺ�����, �п��ܲ��������Ĳ���ֵ
		// ��Ҳ�����ǵ�rank����height����depth��ԭ��, ��ֻ����Ϊ�Ƚϵ�һ����׼
		int* rank; 
		int* parent; // parent[i]��ʾ��i��Ԫ����ָ��ĸ��ڵ�  
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

			// path compression 1
			while( p != parent[p]){
				// ·��ѹ������p�ĸ��׽ڵ�ָ���丸�׵ĸ��׽ڵ㣬���������׵ĸ��׽ڵ������һ��ѭ��
				parent[p] = parent[parent[p]];
				p = parent[p];
			}
			return p;


			// path compression 2(�ݹ��㷨)
			// ������������ɵ����߶�Ϊ2����path compression 1����
			/*if(p != parent[p])
				parent[p] = find( parent[p]);
			return parent[p];*/
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