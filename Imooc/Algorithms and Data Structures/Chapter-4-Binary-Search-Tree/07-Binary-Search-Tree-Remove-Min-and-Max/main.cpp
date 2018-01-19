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

	// Ѱ����С�ļ�ֵ
	Key minimum(){
		assert(count != 0);
		Node* minNode = __minimum(root);
		return minNode->key;
	}

	// Ѱ�����ļ�ֵ
	Key maximum(){
		assert(count != 0);
		Node* maxNode = __maximum(root);
		return maxNode->key;
	}

	// �Ӷ�������ɾ����Сֵ���ڽڵ�
	void removeMin(){
		if(root)
			root = __removeMin(root);
	}

	// �Ӷ�������ɾ�����ֵ���ڽڵ�
	void removeMax(){
		if(root)
			root = __removeMax(root);
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

	// ������nodeΪ���Ķ�������������С��ֵ���ڵĽڵ�
	Node* __minimum(Node* node){
		if(node->left == NULL)
			return node;

		return __minimum(node->left);
	}

	// ������nodeΪ���Ķ���������������ֵ���ڵĽڵ�
	Node* __maximum(Node* node){
		if(node->right == NULL)
			return node;

		return __maximum(node->right);
	}

	// ɾ������nodeΪ���Ķ����������е���С�ڵ�
    // ����ɾ���ڵ���µĶ����������ĸ�
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

	// ɾ������nodeΪ���Ķ����������е����ڵ�
    // ����ɾ���ڵ���µĶ����������ĸ�
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


// ���Զ����������е�removeMin��removeMax
int main() {

    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();

    // ȡn��ȡֵ��Χ��[0...m)����������Ž�������������
    int n = 100;
    int m = 100;
    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%m;
        // Ϊ�˺������Է���,����valueֵȡ��keyֵһ��
        int value = key;
        //cout<<key<<" ";
        bst.insert(key,value);
    }
    // ע��, ����������ɵ��������ظ�, ����bst�е����������������С��n��

    // ���� removeMin
    // �����Ԫ��Ӧ���Ǵ�С�������е�
    cout<<"Test removeMin: "<<endl;
    while( !bst.isEmpty() ){
        cout<<"min: "<<bst.minimum()<<" , ";
        bst.removeMin();
        cout<<"After removeMin, size = "<<bst.size()<<endl;
    }
    cout << endl;


    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%n;
        // Ϊ�˺������Է���,����valueֵȡ��keyֵһ��
        int value = key;
        //cout<<key<<" ";
        bst.insert(key,value);
    }
    // ע��, ����������ɵ��������ظ�, ����bst�е����������������С��n��

    // ���� removeMax
    // �����Ԫ��Ӧ���ǴӴ�С���е�
    cout<<"Test removeMax: "<<endl;
    while( !bst.isEmpty() ){
        cout<<"max: "<<bst.maximum()<<" , ";
        bst.removeMax();
        cout<<"After removeMax, size = "<<bst.size()<<endl;
    }

    return 0;
}