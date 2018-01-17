#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
using namespace std;

template<typename T>
void __merge(T arr[], int l, int mid, int r){
	int* aux = new T[r-l+1];

	for(int i=l;i<=r;i++)
		aux[i-l] = arr[i];

	int i=l, j=mid+1;
	for(int k=l; k<=r;k++){
		if(i>mid){
			arr[k] = aux[j-l];j++;
		}
		else if(j>r){
			arr[k] = aux[i-l];i++;
		}
		else if(aux[i-l] < aux[j-l] ){
			arr[k] = aux[i-l];
			i++;
		} 
		else {
			arr[k] = aux[j-l];
			j++;
		} 
	
	}
	delete[] aux;
	
}


template<typename T>
void __mergeSort(T arr[], int l, int r){
	if(l >= r) 
		return;

	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);
	__merge(arr, l, mid, r);
}


template<typename T>
void mergeSort(T arr[], int n){
	__mergeSort(arr, 0, n-1);

}

int main(){
	
	int n = 10000;

	// 一般性测试
	cout<<"general test"<<" ("<<n<<" numbers)"<<endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);


	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr2, n);


	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	// 测试近乎有序数据
	cout<<"nealy ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	// 测试完全有序数据
	cout<<"fully ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,0);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	return 0;

}