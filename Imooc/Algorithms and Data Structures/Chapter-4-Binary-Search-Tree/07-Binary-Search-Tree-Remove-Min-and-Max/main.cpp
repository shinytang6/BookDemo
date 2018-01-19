#include <iostream>
#include <vector>
#include "SequenceST.h"
#include "FileOps.h"
#include <queue>
using namespace std;

// Binary Search Tree
template <typename Key, typename Value>
class BST{

private:
	// 二分搜索树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
	struct Node{
		Key key;
		Value value;
		Node *left;
		Node *right;

		Node(Key key, Value value){
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};

	Node *root;		// 根节点
	int count;

public: 
	BST(){
		root = NULL;
		count = 0;
	}
	~BST(){
		destroy(root);
	}

	int size(){
		return count;
	}

	bool isEmpty(){
		return count == 0;
	}

	void insert(Key key, Value value){
	
		root = __insert(root, key, value);
	}

	bool contain(Key key){
	
		return __contain(root,key);
	}

	Value* search(Key key){

		return __search(root,key);
	}

	// 二分搜索树的前序遍历
	void preOrder(){
		__preOrder(root);
	}

    // 二分搜索树的中序遍历
	void inOrder(){
		__inOrder(root);
	}

	// 二分搜索树的后序遍历
	void postOrder(){
		__postOrder(root);
	}

	// 层序遍历
	// 广度优先遍历（前面的前中后序遍历都是深度优先遍历）
	void levelOrder(){
	
		queue<Node*> q;
		q.push(root);
		while( !q.empty() ){
			
			Node *node = q.front();
			q.pop();

			cout<<node->key<<endl;
			if( node->left)
				q.push(node->left);
			if( node->right)
				q.push(node->right);
		
		}
	}


	// 释放以node为根的二分搜索树的所有节点
    // 采用后续遍历的递归算法
	void destroy(Node* node){
		if(node!=NULL){
			destroy(node->left);
			destroy(node->right);

			delete node;
			count --;
		}
	}

	// 寻找最小的键值
	Key minimum(){
		assert(count != 0);
		Node* minNode = __minimum(root);
		return minNode->key;
	}

	// 寻找最大的键值
	Key maximum(){
		assert(count != 0);
		Node* maxNode = __maximum(root);
		return maxNode->key;
	}

	// 从二叉树中删除最小值所在节点
	void removeMin(){
		if(root)
			root = __removeMin(root);
	}

	// 从二叉树中删除最大值所在节点
	void removeMax(){
		if(root)
			root = __removeMax(root);
	}

private:

	// 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二分搜索树的根
	Node* __insert(Node *node, Key key, Value value){
		
		if(node == NULL){
			count ++;
			return new Node(key, value);
		}

		if(key == node->key)
			node->value = value;
		else if(key < node->key)
			node->left = __insert(node->left, key, value);
		else
			node->right = __insert(node->right, key, value);

		return node;
	}

	// 查看以node为根的二分搜索树中是否包含键值为key的节点, 使用递归算法
	bool __contain(Node* node, Key key){
	
		if(node == NULL)
			return false;

		if(key == node->key)
			return true;
		else if(key < node->key)
			return __contain(node->left, key);
		else
			return __contain(node->right, key);
	}

	// 在以node为根的二分搜索树中查找key所对应的value, 递归算法
    // 若value不存在, 则返回NULL
	Value* __search(Node* node, Key key){
		if(node == NULL)
			return NULL;
		if(key == node->key)
			return &(node->value);	// 返回value的地址
		else if(key < node->key)
			return __search(node->left, key);
		else
			return __search(node->right, key);
	
	}

    // 对以node为根的二叉搜索树进行前序遍历, 递归算法
	void __preOrder(Node* node){
	
		if(node != NULL){
			cout<<node->key<<endl;
			__preOrder(node->left);
			__preOrder(node->right);
		}	
	}

    // 对以node为根的二叉搜索树进行中序遍历, 递归算法
	void __inOrder(Node* node){
		
		if(node != NULL){
			__inOrder(node->left);
			cout<<node->key<<endl;
			__inOrder(node->right);
		}	
	}

	// 对以node为根的二叉搜索树进行后序遍历, 递归算法
	void __postOrder(Node* node){
		
		if(node != NULL){
			__postOrder(node->left);
			__postOrder(node->right);
			cout<<node->key<<endl;
		}	
	}

	// 返回以node为根的二分搜索树的最小键值所在的节点
	Node* __minimum(Node* node){
		if(node->left == NULL)
			return node;

		return __minimum(node->left);
	}

	// 返回以node为根的二分搜索树的最大键值所在的节点
	Node* __maximum(Node* node){
		if(node->right == NULL)
			return node;

		return __maximum(node->right);
	}

	// 删除掉以node为根的二分搜索树中的最小节点
    // 返回删除节点后新的二分搜索树的根
	Node* __removeMin(Node* node){
		
		if(node->left == NULL){
			Node* rightNode = node->right;
			delete node;
			count --;
			return rightNode;
		}
	
		node->left = __removeMin(node->left);
		return node;
	}

	// 删除掉以node为根的二分搜索树中的最大节点
    // 返回删除节点后新的二分搜索树的根
	Node* __removeMax(Node* node){
		
		if(node->right == NULL){
			Node* leftNode = node->left;
			delete node;
			count --;
			return leftNode;
		}
	
		node->right = __removeMax(node->right);
		return node;
	}

};


// 测试二分搜索树中的removeMin和removeMax
int main() {

    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();

    // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
    int n = 100;
    int m = 100;
    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%m;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        //cout<<key<<" ";
        bst.insert(key,value);
    }
    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

    // 测试 removeMin
    // 输出的元素应该是从小到大排列的
    cout<<"Test removeMin: "<<endl;
    while( !bst.isEmpty() ){
        cout<<"min: "<<bst.minimum()<<" , ";
        bst.removeMin();
        cout<<"After removeMin, size = "<<bst.size()<<endl;
    }
    cout << endl;


    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%n;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        //cout<<key<<" ";
        bst.insert(key,value);
    }
    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

    // 测试 removeMax
    // 输出的元素应该是从大到小排列的
    cout<<"Test removeMax: "<<endl;
    while( !bst.isEmpty() ){
        cout<<"max: "<<bst.maximum()<<" , ";
        bst.removeMax();
        cout<<"After removeMax, size = "<<bst.size()<<endl;
    }

    return 0;
}