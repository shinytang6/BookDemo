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
};


int main(){
	return 0;
}