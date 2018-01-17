#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "MergeSortBU.h"
#include "QuickSort2.h"
#include "QuickSortThreeWays.h"
#include "HeapSort.h"
using namespace std;

template<typename Item>
class IndexMaxHeap{
	
private:
	Item* data;  // 最大索引堆中的数据
	int* indexes; // 最大索引堆中的索引
	int count;
	int capacity;

	// 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
	void shiftUp(int k){
		while( k>1 && data[indexes[k/2]] < data[indexes[k]]){
			swap( indexes[k/2], indexes[k]);
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
			k = j;
		}
	
	}

public:
	
	// 构造函数, 构造一个空的索引堆, 可容纳capacity个元素
	IndexMaxHeap(int capacity){
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		this->count = 0;
		this->capacity = capacity;
	}


	~IndexMaxHeap(){
		delete[] data;
		delete[] indexes;
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

		count++;
		shiftUp( count );
	}

	// 从最大索引堆中取出堆顶元素, 即索引堆中所存储的最大数据
	Item extractMax(){

		assert(count > 0);

		Item ret = data[indexes[1]];

		swap( indexes[count], indexes[1]);
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
		count--;
		shiftDown(1);

		return ret;
	}

	Item getItem(int i){
		return data[i+1];
	}

	// change操作最差时间复杂度是O(n)+O(logn) = O(n)
	// 该操作可优化
	void change(int i, Item newItem){
		
		i++;
		data[i] = newItem;

		// 需要找到j,满足indexes[j]=i, j表示data[i]在堆中的位置
		// 然后尝试向上挪一下 shiftUp(j),再shiftDown(j);
		for(int j=1; j<=count; j++){
			if(indexes[j] == i){
				shiftUp(j);
				shiftDown(j);
				return;
			}
		}
	}


};


// 使用最大索引堆进行堆排序, 来验证我们的最大索引堆的正确性
// 最大索引堆的主要作用不是用于排序, 我们在这里使用排序只是为了验证我们的最大索引堆实现的正确性
// 在后续的图论中, 无论是最小生成树算法, 还是最短路径算法, 我们都需要使用索引堆进行优化:)
template<typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n){

    IndexMaxHeap<T> indexMaxHeap = IndexMaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        indexMaxHeap.insert( i , arr[i] );

    for( int i = n-1 ; i >= 0 ; i -- )
        arr[i] = indexMaxHeap.extractMax();
}



// 比较 Merge Sort, 三种 Quick Sort 和本节介绍的三种 Heap Sort 的性能效率
// 注意, 这几种排序算法都是 O(nlogn) 级别的排序算法
int main(){
	
	int n = 1000000;

	// 一般性测试
	cout<<"general test"<<" ("<<n<<" numbers)"<<endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);
	int *arr4 = SortTestHelper::copyIntArray(arr1, n);
	int *arr5 = SortTestHelper::copyIntArray(arr1, n);
	int *arr6 = SortTestHelper::copyIntArray(arr1, n);
	int *arr7 = SortTestHelper::copyIntArray(arr1, n);


	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);
	SortTestHelper::testSort("Heap Sort Inplace", heapSortInplace<int>, arr6, n);
	SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap<int>, arr7, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;

	cout<<endl;

	// 测试近乎有序数据
	// 加入了随机选择标定点的步骤后, 我们的快速排序可以轻松处理近乎有序的数组
	// 因为每次patition不再是极度不平衡的分解
	cout<<"nealy ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);
	arr6 = SortTestHelper::copyIntArray(arr1, n);
	arr7 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);
	SortTestHelper::testSort("Heap Sort Inplace", heapSortInplace<int>, arr6, n);
	SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap<int>, arr7, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;

	cout<<endl;

	// 测试完全有序数据
	cout<<"fully ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,0);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);
	arr6 = SortTestHelper::copyIntArray(arr1, n);
	arr7 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);
	SortTestHelper::testSort("Heap Sort Inplace", heapSortInplace<int>, arr6, n);
	SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap<int>, arr7, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;

	cout<<endl;


	// 测试包含大量相同元素的数组
	// 但此时, 对于含有大量相同元素的数组, 快速排序算法再次退化成了O(n^2)级别的算法
	cout<<"many same elements test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateRandomArray(n,0,10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);
	arr6 = SortTestHelper::copyIntArray(arr1, n);
	arr7 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);
	SortTestHelper::testSort("Heap Sort Inplace", heapSortInplace<int>, arr6, n);
	SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap<int>, arr7, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;

	cout<<endl;

	return 0;

}



