#include <iostream>
#include <cassert>

using namespace std;

// 路径压缩 Path Compression
// 前面几版优化都是针对union这个操作的，其实find操作也可以优化
// 在向上查找父节点的同时可将节点向上挪，从而压缩树的高度
// 第五版Union-Find
namespace UF5 {

	class UnionFind{

	private:
		// rank[i]表示以i为根的集合所表示的树的层数
		// 在后续的代码中, 我们并不会维护rank的语意, 也就是rank的值在路径压缩的过程中, 有可能不在是树的层数值
		// 这也是我们的rank不叫height或者depth的原因, 他只是作为比较的一个标准
		int* rank; 
		int* parent; // parent[i]表示第i个元素所指向的父节点  
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

			// path compression 1
			while( p != parent[p]){
				// 路径压缩，将p的父亲节点指向其父亲的父亲节点，并从它父亲的父亲节点进行下一次循环
				parent[p] = parent[parent[p]];
				p = parent[p];
			}
			return p;


			// path compression 2(递归算法)
			// 理论上最后生成的树高度为2，比path compression 1更优
			/*if(p != parent[p])
				parent[p] = find( parent[p]);
			return parent[p];*/
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