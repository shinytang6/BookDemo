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
using namespace std;


// 三路快速排序处理 aa[l...r]
// 将arr[l...r]分为 <v; ==v; >v 三部分
// 之后递归对 <v; >v 两部分继续进行三路快速排序

template<typename T>
void __quickSort3Ways(T arr[], int l, int r){
	/*if(l>=r)
		return;*/
	// 优化: 对于小规模数组, 使用插入排序
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

	// 因为三路排序需要返回两个索引值，所以直接写在这里
	// patition
	srand((unsigned)time(NULL));
	swap(arr[l], arr[rand()%(r-l+1)+l]);
	T v = arr[l];

	int lt = l;  // arr[l+1...lt] < v
	int gt = r+1;   // arr[gt...r] > v
	int i = l+1;  // arr[lt+1...i) == v
	while(i < gt){
		if(arr[i] < v){
			swap(arr[i], arr[lt+1]);
			lt++;
			i++;
		} 
		else if(arr[i] > v){
			swap(arr[i], arr[gt-1]);
			gt--;
			// i不需要动
		}
		else{
			i++;
		}
	}
	swap(arr[l], arr[lt]);

	__quickSort3Ways(arr, l, lt-1);
	__quickSort3Ways(arr, gt, r);
}

template<typename T>
void quickSort3Ways(T arr[], int n){
	__quickSort3Ways(arr,0,n-1);
}

int main(){
	
	int n = 1000000;

	// 一般性测试
	cout<<"general test"<<" ("<<n<<" numbers)"<<endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);


	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);


	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout<<endl;

	// 测试近乎有序数据
	// 加入了随机选择标定点的步骤后, 我们的快速排序可以轻松处理近乎有序的数组
	// 因为每次patition不再是极度不平衡的分解
	cout<<"nealy ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout<<endl;

	// 测试完全有序数据
	cout<<"fully ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,0);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout<<endl;


	// 测试包含大量相同元素的数组
	// 但此时, 对于含有大量相同元素的数组, 快速排序算法再次退化成了O(n^2)级别的算法
	cout<<"many same elements test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateRandomArray(n,0,10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort2<int>, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways<int>, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout<<endl;

	return 0;

}