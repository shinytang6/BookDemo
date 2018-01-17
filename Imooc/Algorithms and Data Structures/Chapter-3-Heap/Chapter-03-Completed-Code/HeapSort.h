#include <iostream>
#include "MaxHeap.h"
using namespace std;

// heapSort1, 将所有的元素依次添加到堆中, 再将所有元素从堆中依次取出来, 即完成了排序
// 无论是创建堆的过程, 还是从堆中依次取出元素的过程, 时间复杂度均为O(nlogn)
// 整个堆排序的整体时间复杂度为O(nlogn)
template<typename T>
void heapSort1(T arr[], int n){

	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for(int i=0; i<n; i++)
		maxheap.insert(arr[i]);

	// 将元素从堆中取出来并反向赋给原数组
	for(int i=n-1; i>=0; i--)
		arr[i] = maxheap.extractMax();


}

// heapSort2, 借助heapify（一种将数组转为堆的方法）过程创建堆
// 此时, 创建堆的过程时间复杂度为O(n), 将所有元素依次从堆中取出来, 时间复杂度为O(nlogn)
// 堆排序的总体时间复杂度依然是O(nlogn), 但是比上述heapSort1性能更优, 因为创建堆的性能更优
template<typename T>
void heapSort2(T arr[], int n){

	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for(int i=n-1; i>=0; i--)
		arr[i] = maxheap.extractMax();

}


/** 原地堆排序 **/

// 原始的shiftDown，此时index从0开始，不像MaxHeap.h中是从1开始
template<typename T>
void __shiftDown_inplace(T arr[], int n, int k){
	while( 2*k+1 <= n-1 ){
		int j = 2*k + 1;
		if( arr[j+1]>arr[j] && j+1<=n-1)
			j = j + 1;
		if(arr[k] >= arr[j]) 
			break;
		swap(arr[k], arr[j]);
		k = j;
	}

}

// 原地堆排序
// 不额外开辟一个最大堆, 直接在原数组上进行原地的堆排序
// 节省了空间复杂度
template<typename T>
void heapSortInplace(T arr[], int n){
	for(int i=(n-1)/2; i>=0; i--){
		__shiftDown_inplace(arr, n, i);
	}

	for(int i=n-1; i>0; i--){
		// 交换第一个元素和最后一个元素
		// 此时最后一个元素就是排完序后最大的元素
		// 依次类推
		swap(arr[0], arr[i]);
		__shiftDown_inplace(arr, i, 0);
	}
}