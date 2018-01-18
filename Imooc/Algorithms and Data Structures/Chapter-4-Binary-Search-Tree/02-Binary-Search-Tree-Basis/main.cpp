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
};


int main(){
	return 0;
}