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

// �Ե����Ϲ鲢����
// ���������Ż��汾
template<typename T>
void mergeSortBottomUp(T arr[], int n){
	for(int sz=1; sz<n; sz=sz+sz)
		// �����������Ϊi<n, i+sz����Խ�磬����Ҫ��֤i+sz<n��ͬʱ�����鲢���ܲ���sz��Ԫ��
		for(int i=0; i+sz<n ; i=i+sz+sz)
			__merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1));
}

int main(){
	
	int n = 100000;

	// һ���Բ���
	cout<<"general test"<<" ("<<n<<" numbers)"<<endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);


	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSortBottomUp<int>, arr2, n);


	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	// ���Խ�����������
	cout<<"nealy ordered data test"<<" ("<<n<<" numbers)"<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSortBottomUp<int>, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	// ������ȫ��������
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