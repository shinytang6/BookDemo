#include <iostream>
using namespace std;

// Binary Search Tree
template <typename Key, typename Value>
class BST{

private:
	// �����������еĽڵ�Ϊ˽�еĽṹ��, ��粻��Ҫ�˽�����������ڵ�ľ���ʵ��
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

	Node *root;		// ���ڵ�
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

	// ����nodeΪ���Ķ�����������, ����ڵ�(key, value), ʹ�õݹ��㷨
    // ���ز����½ڵ��Ķ����������ĸ�
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