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
#include "Heap.h"
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


int main(){
	
	int n = 1000000;

	// 一般性测试
	cout<<"general test"<<" ("<<n<<" numbers)"<<endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);
	int *arr4 = SortTestHelper::copyIntArray(arr1, n);
	int *arr5 = SortTestHelper::copyIntArray(arr1, n);


	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;

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

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;

	cout<<endl;

	// 测试完全有序数据
	cout<<"fully ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,0);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;

	cout<<endl;


	// 测试包含大量相同元素的数组
	// 但此时, 对于含有大量相同元素的数组, 快速排序算法再次退化成了O(n^2)级别的算法
	cout<<"many same elements test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateRandomArray(n,0,10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;

	cout<<endl;

	return 0;

}