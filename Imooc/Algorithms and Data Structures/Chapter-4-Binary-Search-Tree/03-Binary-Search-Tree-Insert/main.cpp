#include <iostream>
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
		// TODO
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
};


int main(){
	return 0;
}