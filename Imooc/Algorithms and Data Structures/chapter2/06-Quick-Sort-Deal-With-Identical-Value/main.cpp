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

// ��arr[l...r]���ֽ���partition����
// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __patition2(T arr[], int l, int r){

	// �Ż��������arr[l...r]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
	srand((unsigned)time(NULL));
	swap(arr[l], arr[rand()%(r-l+1)+l]);
	T v = arr[l];
	
	// arr[l+1...i) <=v;  arr(j...r] >= v
	// ��ʼ��ʱҪΪ��
	int i = l+1 ,j = r;
	while(true){
		while(arr[i] < v && i <= r) i++;
		while(arr[j] > v && j >= l+1) j--;
		if(i>j) break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	swap(arr[l],arr[j]);
	return j;
}



template<typename T>
void __quickSort2(T arr[], int l, int r){
	/*if(l>=r)
		return;*/
	// �Ż�: ����С��ģ����, ʹ�ò�������
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

	int p = __patition2(arr, l, r);
	__quickSort2(arr, l, p-1);
	__quickSort2(arr, p+1, r);
}

template<typename T>
void quickSort2(T arr[], int n){
	__quickSort2(arr,0,n-1);
}

int main(){
	
	int n = 1000000;

	// һ���Բ���
	cout<<"general test"<<" ("<<n<<" numbers)"<<endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);


	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort2<int>, arr2, n);


	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	// ���Խ�����������
	// ���������ѡ��궨��Ĳ����, ���ǵĿ�������������ɴ���������������
	// ��Ϊÿ��patition�����Ǽ��Ȳ�ƽ��ķֽ�
	cout<<"nealy ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort2<int>, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	// ������ȫ��������
	cout<<"fully ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,0);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort2<int>, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;


	// ���԰���������ͬԪ�ص�����
	// ����ʱ, ���ں��д�����ͬԪ�ص�����, ���������㷨�ٴ��˻�����O(n^2)������㷨
	cout<<"fully ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateRandomArray(n,0,10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort<int>, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort2<int>, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	return 0;

}