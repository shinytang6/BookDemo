#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"
using namespace std;

template<typename T>
void insertionSort(T arr[], int n){
	for(int i=1; i<n; i++){
		T e = arr[i];
		int j;
		for(j=i; j>0; j--)
			// 插入排序相对选择排序，可提前终止循环
			if( arr[j-1] > e)
				arr[j] = arr[j-1];
			else{
				arr[j] = e;
				break;
			}
	}
}

int main(){
	
	int n = 100000;
	//int *arr = SortTestHelper::generateRandomArray(n,0,n);

	// 测试几乎有序的数组，插入排序效率明显提升
	int *arr = SortTestHelper::generateNearlyOrderedArray(n,100);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Selection Sort", selectionSort<int>, arr, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr2, n);


	// release memory
	delete[] arr;
	delete[] arr2;
	return 0;

}