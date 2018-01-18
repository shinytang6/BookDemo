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

	// ������������ǰ�����
	void preOrder(){
		__preOrder(root);
	}

    // �������������������
	void inOrder(){
		__inOrder(root);
	}

	// �����������ĺ������
	void postOrder(){
		__postOrder(root);
	}

	// �������
	// ������ȱ�����ǰ���ǰ�к����������������ȱ�����
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


	// �ͷ���nodeΪ���Ķ��������������нڵ�
    // ���ú��������ĵݹ��㷨
	void destroy(Node* node){
		if(node!=NULL){
			destroy(node->left);
			destroy(node->right);

			delete node;
			count --;
		}
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

	// �鿴��nodeΪ���Ķ������������Ƿ������ֵΪkey�Ľڵ�, ʹ�õݹ��㷨
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

	// ����nodeΪ���Ķ����������в���key����Ӧ��value, �ݹ��㷨
    // ��value������, �򷵻�NULL
	Value* __search(Node* node, Key key){
		if(node == NULL)
			return NULL;
		if(key == node->key)
			return &(node->value);	// ����value�ĵ�ַ
		else if(key < node->key)
			return __search(node->left, key);
		else
			return __search(node->right, key);
	
	}

    // ����nodeΪ���Ķ�������������ǰ�����, �ݹ��㷨
	void __preOrder(Node* node){
	
		if(node != NULL){
			cout<<node->key<<endl;
			__preOrder(node->left);
			__preOrder(node->right);
		}	
	}

    // ����nodeΪ���Ķ��������������������, �ݹ��㷨
	void __inOrder(Node* node){
		
		if(node != NULL){
			__inOrder(node->left);
			cout<<node->key<<endl;
			__inOrder(node->right);
		}	
	}

	// ����nodeΪ���Ķ������������к������, �ݹ��㷨
	void __postOrder(Node* node){
		
		if(node != NULL){
			__postOrder(node->left);
			__postOrder(node->right);
			cout<<node->key<<endl;
		}	
	}


};


// ���Զ�����������ǰ�к������
int main() {

    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();

    // ȡn��ȡֵ��Χ��[0...m)����������Ž�������������
    int N = 10;
    int M = 100;
    for( int i = 0 ; i < N ; i ++ ){
        int key = rand()%M;
        // Ϊ�˺������Է���,����valueֵȡ��keyֵһ��
        int value = key;
        cout<<key<<" ";
        bst.insert(key,value);
    }
    cout<<endl;

    // ���Զ�����������size()
    cout<<"size: "<<bst.size()<<endl<<endl;

    // ���Զ�����������ǰ����� preOrder
    cout<<"preOrder: "<<endl;
    bst.preOrder();
    cout<<endl;

    // ���Զ������������������ inOrder
    cout<<"inOrder: "<<endl;
    bst.inOrder();
    cout<<endl;

    // ���Զ����������ĺ������ postOrder
    cout<<"postOrder: "<<endl;
    bst.postOrder();
    cout<<endl;

	// ���Զ����������Ĳ������ levelOrder
    cout<<"levelOrder: "<<endl;
    bst.levelOrder();
    cout<<endl;

    return 0;
}