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


// ��·���������� aa[l...r]
// ��arr[l...r]��Ϊ <v; ==v; >v ������
// ֮��ݹ�� <v; >v �����ּ���������·��������

template<typename T>
void __quickSort3Ways(T arr[], int l, int r){
	/*if(l>=r)
		return;*/
	// �Ż�: ����С��ģ����, ʹ�ò�������
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

	// ��Ϊ��·������Ҫ������������ֵ������ֱ��д������
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
			// i����Ҫ��
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

	// һ���Բ���
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

	// ���Խ�����������
	// ���������ѡ��궨��Ĳ����, ���ǵĿ�������������ɴ���������������
	// ��Ϊÿ��patition�����Ǽ��Ȳ�ƽ��ķֽ�
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

	// ������ȫ��������
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


	// ���԰���������ͬԪ�ص�����
	// ����ʱ, ���ں��д�����ͬԪ�ص�����, ���������㷨�ٴ��˻�����O(n^2)������㷨
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