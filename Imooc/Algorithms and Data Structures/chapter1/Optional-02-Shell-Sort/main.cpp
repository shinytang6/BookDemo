#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
using namespace std;

template<typename T>
void shellSort(T arr[], int n){
	int gap = n/2;
	/*int gap = 1;
    while( gap < n/3 )
        gap = 3 * gap + 1;*/
	while(gap > 0){
		for(int i=gap; i<n; i++){
			T e = arr[i];
            int j;
			for(j=i; j>0; j=j-gap)
				if(e<arr[j-gap])
					arr[j] = arr[j-gap];
				else{
					arr[j] = e;
					break;
				}
		}
	
		gap = gap/2;
		//gap= gap/3;
	}
}


int main(){
	
	int n = 100000;

	// 一般性测试
	cout<<"general test"<<" ("<<n<<" numbers)"<<endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);
	int *arr4 = SortTestHelper::copyIntArray(arr1, n);
	int *arr5 = SortTestHelper::copyIntArray(arr1, n);
	int *arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort<int>, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr2, n);
	SortTestHelper::testSort("BubbleSort", bubbleSort<int>, arr3, n);
	SortTestHelper::testSort("BubbleSort_bobo", bubbleSort_bobo<int>, arr4, n);
	SortTestHelper::testSort("BubbleSort2_bobo", bubbleSort2_bobo<int>, arr5, n);
	SortTestHelper::testSort("Shell Sort", shellSort<int>, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;

	cout<<endl;

	// 测试近乎有序数据
	cout<<"nealy ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);
	arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort<int>, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr2, n);
	SortTestHelper::testSort("BubbleSort", bubbleSort<int>, arr3, n);
	SortTestHelper::testSort("BubbleSort_bobo", bubbleSort_bobo<int>, arr4, n);
	SortTestHelper::testSort("BubbleSort2_bobo", bubbleSort2_bobo<int>, arr5, n);
	SortTestHelper::testSort("Shell Sort", shellSort<int>, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;

	cout<<endl;

	// 测试完全有序数据
	cout<<"fully ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,0);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);
	arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort<int>, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr2, n);
	SortTestHelper::testSort("BubbleSort", bubbleSort<int>, arr3, n);
	SortTestHelper::testSort("BubbleSort_bobo", bubbleSort_bobo<int>, arr4, n);
	SortTestHelper::testSort("BubbleSort2_bobo", bubbleSort2_bobo<int>, arr5, n);
	SortTestHelper::testSort("Shell Sort", shellSort<int>, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;

	cout<<endl;

	return 0;

}