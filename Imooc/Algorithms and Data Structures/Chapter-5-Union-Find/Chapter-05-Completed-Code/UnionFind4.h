#include <iostream>
#include <cassert>

using namespace std;

// 第四版Union-Find
// 极端情况下第三版基于size的优化可能会使树的高度增加而不是减少，所以这版基于rank(树的高度)来优化
namespace UF4 {

	class UnionFind{

	private:
		int* parent; // parent[i]表示第i个元素所指向的父节点
		int* rank;   // rank[i]表示以i为根的集合所表示的树的层数
		int count;   // 数据个数

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

		// 查找过程, 查找元素p所对应的集合编号
		// O(h)复杂度, h为树的高度
		int find(int p){
			assert(p>=0 && p<count);
			// 不断去查询自己的父亲节点, 直到到达根节点
			// 根节点的特点: parent[p] == p
			while( p != parent[p])
				p = parent[p];
			return p;
		}

		// 查看元素p和元素q是否所属一个集合
		// O(h)复杂度, h为树的高度
		bool isConnected(int p, int	q){
			return find(p) == find(q);
		}


		// 合并元素p和元素q所属的集合
		// O(h)复杂度, h为树的高度
		void unionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);

			if(pRoot == qRoot)
				return;


			// 根据两个元素所在树的元素个数不同判断合并方向
			// 将元素个数少的集合合并到元素个数多的集合上
			// 使树的高度尽量小
			if(rank[pRoot] < rank[qRoot]){
				parent[pRoot] = qRoot;
			}
			else if(rank[pRoot] > rank[qRoot]){
				parent[qRoot] = pRoot;
			}
			else{	// rank[pRoot] == rank[qRoot]
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;	// 此时，维护rank的值
			}

			
		}

	};

}