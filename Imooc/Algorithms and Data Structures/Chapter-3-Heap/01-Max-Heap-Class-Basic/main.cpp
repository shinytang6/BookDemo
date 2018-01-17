#include <iostream>
using namespace std;

template<typename Item>
class MaxHeap{
	
private:
	Item* data;
	int count;

public:
	// ��Ϊ��������Ѵ�1��ʼ��ţ�����Ҫ�ճ�����0����λ��
	MaxHeap(int capacity){
		data = new Item[capacity + 1];
		count = 0;
	}

	~MaxHeap(){
		delete[] data;
	}

	// ���ض��е�Ԫ�ظ���
	int size(){
		return count;
	}

	// �ж϶����Ƿ�Ϊ��
	int isEmpty(){
		return count == 0;
	}
};
int main() {

	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout<<maxheap.size()<<endl;
	return 0;
}