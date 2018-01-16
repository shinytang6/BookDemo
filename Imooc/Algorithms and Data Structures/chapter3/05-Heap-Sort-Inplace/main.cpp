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

// ԭʼ��shiftDown����ʱindex��0��ʼ������Heap.h���Ǵ�1��ʼ
template<typename T>
void __shiftDown(T arr[], int n, int k){
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

// ԭ�ض�����
// �����⿪��һ������, ֱ����ԭ�����Ͻ���ԭ�صĶ�����
// ��ʡ�˿ռ临�Ӷ�
template<typename T>
void heapSort(T arr[], int n){
	for(int i=(n-1)/2; i>=0; i--){
		__shiftDown(arr, n, i);
	}

	for(int i=n-1; i>0; i--){
		// ������һ��Ԫ�غ����һ��Ԫ��
		// ��ʱ���һ��Ԫ�ؾ��������������Ԫ��
		// ��������
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}

// �Ƚ� Merge Sort, ���� Quick Sort �ͱ��ڽ��ܵ����� Heap Sort ������Ч��
// ע��, �⼸�������㷨���� O(nlogn) ����������㷨
int main(){
	
	int n = 1000000;

	// һ���Բ���
	cout<<"general test"<<" ("<<n<<" numbers)"<<endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);
	int *arr4 = SortTestHelper::copyIntArray(arr1, n);
	int *arr5 = SortTestHelper::copyIntArray(arr1, n);
	int *arr6 = SortTestHelper::copyIntArray(arr1, n);


	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);
	SortTestHelper::testSort("Heap Sort", heapSort<int>, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;

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
	arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);
	SortTestHelper::testSort("Heap Sort", heapSort<int>, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;

	cout<<endl;

	// ������ȫ��������
	cout<<"fully ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,0);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);
	arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);
	SortTestHelper::testSort("Heap Sort", heapSort<int>, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;

	cout<<endl;


	// ���԰���������ͬԪ�ص�����
	// ����ʱ, ���ں��д�����ͬԪ�ص�����, ���������㷨�ٴ��˻�����O(n^2)������㷨
	cout<<"many same elements test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateRandomArray(n,0,10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);
	arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1<int>, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2<int>, arr5, n);
	SortTestHelper::testSort("Heap Sort", heapSort<int>, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	cout<<endl;

	return 0;

}