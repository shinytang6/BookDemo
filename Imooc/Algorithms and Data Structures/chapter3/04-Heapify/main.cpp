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


// heapSort1, �����е�Ԫ��������ӵ�����, �ٽ�����Ԫ�شӶ�������ȡ����, �����������
// �����Ǵ����ѵĹ���, ���ǴӶ�������ȡ��Ԫ�صĹ���, ʱ�临�ӶȾ�ΪO(nlogn)
// ���������������ʱ�临�Ӷ�ΪO(nlogn)
template<typename T>
void heapSort1(T arr[], int n){

	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for(int i=0; i<n; i++)
		maxheap.insert(arr[i]);

	// ��Ԫ�شӶ���ȡ���������򸳸�ԭ����
	for(int i=n-1; i>=0; i--)
		arr[i] = maxheap.extractMax();

}

// heapSort2, ����heapify��һ�ֽ�����תΪ�ѵķ��������̴�����
// ��ʱ, �����ѵĹ���ʱ�临�Ӷ�ΪO(n), ������Ԫ�����δӶ���ȡ����, ʱ�临�Ӷ�ΪO(nlogn)
// �����������ʱ�临�Ӷ���Ȼ��O(nlogn), ���Ǳ�����heapSort1���ܸ���, ��Ϊ�����ѵ����ܸ���
template<typename T>
void heapSort2(T arr[], int n){

	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for(int i=n-1; i>=0; i--)
		arr[i] = maxheap.extractMax();

}


int main(){
	
	int n = 1000000;

	// һ���Բ���
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

	// ���Խ�����������
	// ���������ѡ��궨��Ĳ����, ���ǵĿ�������������ɴ���������������
	// ��Ϊÿ��patition�����Ǽ��Ȳ�ƽ��ķֽ�
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

	// ������ȫ��������
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


	// ���԰���������ͬԪ�ص�����
	// ����ʱ, ���ں��д�����ͬԪ�ص�����, ���������㷨�ٴ��˻�����O(n^2)������㷨
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