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


};


// 测试二分搜索树的前中后序遍历
int main() {

    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();

    // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
    int N = 10;
    int M = 100;
    for( int i = 0 ; i < N ; i ++ ){
        int key = rand()%M;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        cout<<key<<" ";
        bst.insert(key,value);
    }
    cout<<endl;

    // 测试二分搜索树的size()
    cout<<"size: "<<bst.size()<<endl<<endl;

    // 测试二分搜索树的前序遍历 preOrder
    cout<<"preOrder: "<<endl;
    bst.preOrder();
    cout<<endl;

    // 测试二分搜索树的中序遍历 inOrder
    cout<<"inOrder: "<<endl;
    bst.inOrder();
    cout<<endl;

    // 测试二分搜索树的后序遍历 postOrder
    cout<<"postOrder: "<<endl;
    bst.postOrder();
    cout<<endl;

	// 测试二分搜索树的层序遍历 levelOrder
    cout<<"levelOrder: "<<endl;
    bst.levelOrder();
    cout<<endl;

    return 0;
}