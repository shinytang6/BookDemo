#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
using namespace std;

// 自底向上归并排序
// 这里是无优化版本
template<typename T>
void mergeSortBottomUp(T arr[], int n){
	for(int sz=1; sz<n; sz=sz+sz)
		// 如果限制条件为i<n, i+sz可能越界，所以要保证i+sz<n，同时后半组归并可能不足sz个元素
		for(int i=0; i+sz<n ; i=i+sz+sz)
			__merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1));
}

int main(){
	
	int n = 100000;

	// 一般性测试
	cout<<"general test"<<" ("<<n<<" numbers)"<<endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);


	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSortBottomUp<int>, arr2, n);


	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	// 测试近乎有序数据
	cout<<"nealy ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSortBottomUp<int>, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	// 测试完全有序数据
	cout<<"fully ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,0);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSortBottomUp<int>, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	return 0;

}