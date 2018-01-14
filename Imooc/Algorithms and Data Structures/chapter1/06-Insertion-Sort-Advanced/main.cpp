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
			// �����������ѡ�����򣬿���ǰ��ֹѭ��
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

	// ���Լ�����������飬��������Ч����������
	int *arr = SortTestHelper::generateNearlyOrderedArray(n,100);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Selection Sort", selectionSort<int>, arr, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort<int>, arr2, n);


	// release memory
	delete[] arr;
	delete[] arr2;
	return 0;

}