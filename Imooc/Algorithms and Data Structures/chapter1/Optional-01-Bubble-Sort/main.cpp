#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
using namespace std;

template<typename T>
void bubbleSort(T arr[], int n){
	for(int i=0; i<n; i++){
		// 每次都把最大的元素放最后
		for(int j=0; j<n-1; j++){
			if(arr[j] > arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
}


int main(){
	
	int n = 10000;

	// 一般性测试
	cout<<"general test"<<endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort<int>, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr2, n);
	SortTestHelper::testSort("BubbleSort", bubbleSort<int>, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	cout<<endl;

	// 测试近乎有序数据
	cout<<"nealy ordered data test"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort<int>, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr2, n);
	SortTestHelper::testSort("BubbleSort", bubbleSort<int>, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	cout<<endl;

	// 测试完全有序数据
	cout<<"ordered data test"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,0);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort<int>, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr2, n);
	SortTestHelper::testSort("BubbleSort", bubbleSort<int>, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	cout<<endl;





	return 0;

}