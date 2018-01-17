#include <iostream>
using namespace std;

// Advanced版本加了reverse反向索引表，使得change函数效率更高
template<typename Item>
class IndexMaxHeap{
	
private:
	Item* data;  // 最大索引堆中的数据
	int* indexes; // 最大索引堆中的索引
	int* reverse;  // 最大索引堆中的反向索引表, reverse[i] = x 表示索引i在x的位置
	int count;
	int capacity;

	// 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
	void shiftUp(int k){
		while( k>1 && data[indexes[k/2]] < data[indexes[k]]){
			swap( indexes[k/2], indexes[k]);

			// 这里indexes[k]和indexes[k/2]已经颠倒
			reverse[indexes[k]] = k;
			reverse[indexes[k/2]] = k/2;
			k = k/2;
		}
	}

	// 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
	void shiftDown(int k){
		// 判断节点是否有左孩子
		while( 2*k <= count){
			
			int j = 2 * k;
			if( j+1 <= count && data[indexes[j+1]] > data[indexes[j]])
				j++;
			// data[j] 是 data[2*k]和data[2*k+1]中的最大值

			if(data[indexes[k]] >= data[indexes[j]])
				break;
			swap(indexes[k], indexes[j]);
			reverse[indexes[k]] = k;
			reverse[indexes[j]] = j;
			k = j;
		}
	
	}

public:
	
	// 构造函数, 构造一个空的索引堆, 可容纳capacity个元素
	IndexMaxHeap(int capacity){
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		reverse = new int[capacity + 1];
		// 0表示不存在该i
		for(int i=0; i<=capacity; i++)
			reverse[i] = 0;

		this->count = 0;
		this->capacity = capacity;
	}


	~IndexMaxHeap(){
		delete[] data;
		delete[] indexes;
		delete[] reverse;
	}

	// 返回堆中的元素个数
	int size(){
		return count;
	}

	// 判断堆中是否为空
	int isEmpty(){
		return count == 0;
	}

	// 向最大索引堆中插入一个新元素item
	// 且指定索引
	// 传入的i对用户而言，是从0开始索引的
	void insert(int i, Item item){

		assert( count+1 <= capacity);
		assert( i+1 <= capacity && i+1 >= 1);

		i++;
		data[i] = item;
		indexes[count+1] = i;
		reverse[i] = count + 1;

		count++;
		shiftUp( count );
	}

	// 从最大索引堆中取出堆顶元素, 即索引堆中所存储的最大数据
	Item extractMax(){

		assert(count > 0);

		Item ret = data[indexes[1]];

		swap( indexes[count], indexes[1]);
		reverse[indexes[1]] = 1;
		// 0表示不存在，因为后面count--表示删除数组最后一个元素
		reverse[indexes[count]] = 0;
		count--;
		shiftDown(1);

		return ret;
	}

	// 从最大索引堆中取出堆顶元素的索引
	Item extractMaxIndex(){

		assert(count > 0);

		// 给用户返回的，故要减1
		int ret = indexes[1] - 1;

		swap( indexes[count], indexes[1]);
		reverse[indexes[1]] = 1;
		// 0表示不存在，因为后面count--表示删除数组最后一个元素
		reverse[indexes[count]] = 0;
		count--;
		shiftDown(1);

		return ret;
	}

	Item getItem(int i){
		assert(contain(i));
		return data[i+1];
	}

    // 看索引i所在的位置是否存在元素
	bool contain(int i){
		assert( i+1>=1 && i+1<=capacity);
		return reverse[i+1] != 0;
	
	}

	void change(int i, Item newItem){
		
		assert(contain(i));
		i++;
		data[i] = newItem;

		//// 需要找到j,满足indexes[j]=i, j表示data[i]在堆中的位置
		//// 然后尝试向上挪一下 shiftUp(j),再shiftDown(j);
		//for(int j=1; j<=count; j++){
		//	if(indexes[j] == i){
		//		shiftUp(j);
		//		shiftDown(j);
		//		return;
		//	}
		//}

		// 此时change操作时间复杂度为O(logn)
		// 有了 reverse 之后,
        // 我们可以非常简单的通过reverse直接定位索引i在indexes中的位置,而不用遍历一遍数组
		int j = reverse[i];
		shiftUp(j);
		shiftDown(j);
	}

};