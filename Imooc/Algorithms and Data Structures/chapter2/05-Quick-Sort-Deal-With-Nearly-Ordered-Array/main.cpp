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

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __patition(T arr[], int l, int r){

	// 优化：随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
	srand((unsigned)time(NULL));
	swap(arr[l], arr[rand()%(r-l+1)+l]);

	T v = arr[l];
	int j = l;
	for(int i=l+1; i<=r; i++){
		if(arr[i] < v){
			swap(arr[j+1], arr[i]);
			j++;
		}
	
	}
	swap(arr[l], arr[j]);
	return j;
}



template<typename T>
void __quickSort(T arr[], int l, int r){
	/*if(l>=r)
		return;*/
	// 优化: 对于小规模数组, 使用插入排序
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

	int p = __patition(arr, l, r);
	__quickSort(arr, l, p-1);
	__quickSort(arr, p+1, r);
}

template<typename T>
void quickSort(T arr[], int n){
	__quickSort(arr,0,n-1);
}

int main(){
	
	int n = 1000000;

	// 一般性测试
	cout<<"general test"<<" ("<<n<<" numbers)"<<endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);


	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort<int>, arr2, n);


	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	// 测试近乎有序数据
	// 加入了随机选择标定点的步骤后, 我们的快速排序可以轻松处理近乎有序的数组
	// 因为每次patition不再是极度不平衡的分解
	cout<<"nealy ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort<int>, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	// 测试完全有序数据
	cout<<"fully ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,0);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort<int>, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;


	// 测试包含大量相同元素的数组
	// 但此时, 对于含有大量相同元素的数组, 快速排序算法再次退化成了O(n^2)级别的算法
	cout<<"fully ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateRandomArray(n,0,10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort<int>, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	return 0;

}