#include <iostream>
using namespace std;

template<typename Item>
class MaxHeap{
	
private:
	Item* data;
	int count;

public:
	// 因为这里的最大堆从1开始编号，所以要空出数组0处的位置
	MaxHeap(int capacity){
		data = new Item[capacity + 1];
		count = 0;
	}

	~MaxHeap(){
		delete[] data;
	}

	// 返回堆中的元素个数
	int size(){
		return count;
	}

	// 判断堆中是否为空
	int isEmpty(){
		return count == 0;
	}
};
int main() {

	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout<<maxheap.size()<<endl;
	return 0;
}