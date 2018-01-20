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

		Node(Node* node){
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
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

	// �Ӷ�������ɾ����ֵΪkey�Ľڵ�
	void remove(Key key){
		root = __remove(root,key);
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

	// ɾ������nodeΪ���Ķ����������м�ֵΪkey�Ľڵ�
	// ����ɾ���ڵ���µĶ����������ĸ�
	Node* __remove(Node* node, Key key){
		
		if( node == NULL)
			return NULL;
		if (key < node->key){
			node->left = __remove(node->left, key);
			return node;
		}
		else if(key > node->key){
			node->right = __remove(node->right, key);
			return node;
		}
		else{  // key == node->key
			
			if(node->left == NULL){
				Node* rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			}

			if(node->right == NULL){
				Node* leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}
			// node���Һ��Ӷ���Ϊ��
			else{
				Node* successor = new Node(__minimum(node->right));
				count++;

				successor->right = __removeMin(node->right);
				successor->left = node->left;
				delete node;
				count --;

				return successor;
			}
		
		}
	
	}

};



void shuffle( int arr[], int n ){

    srand( time(NULL) );
    for( int i = n-1 ; i >= 0 ; i -- ){
        int x = rand()%(i+1);
        swap( arr[i] , arr[x] );
    }
}
// ���� remove
int main() {

    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();

    // ȡn��ȡֵ��Χ��[0...n)����������Ž�������������
    int n = 10000;
    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%n;
        // Ϊ�˺������Է���,����valueֵȡ��keyֵһ��
        int value = key;
        bst.insert(key,value);
    }
    // ע��, ����������ɵ��������ظ�, ����bst�е����������������С��n��

    // order�����д��[0...n)������Ԫ��
    int* order = new int[n];
    for( int i = 0 ; i < n ; i ++ )
        order[i] = i;
    // ����order�����˳��
    shuffle( order , n );

    // ����ɾ��[0...n)��Χ�������Ԫ��
    for( int i = 0 ; i < n ; i ++ )
        if( bst.contain( order[i] )){
            bst.remove( order[i] );
            cout<<"After remove "<<order[i]<<" size = "<<bst.size()<<endl;
        }

    // ������������������Ӧ��Ϊ��
    cout << bst.size() << endl;

	delete[] order;
    return 0;
}