#include <iostream>
#include "MaxHeap.h"
using namespace std;

// heapSort1, �����е�Ԫ��������ӵ�����, �ٽ�����Ԫ�شӶ�������ȡ����, �����������
// �����Ǵ����ѵĹ���, ���ǴӶ�������ȡ��Ԫ�صĹ���, ʱ�临�ӶȾ�ΪO(nlogn)
// ���������������ʱ�临�Ӷ�ΪO(nlogn)
template<typename T>
void heapSort1(T arr[], int n){

	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for(int i=0; i<n; i++)
		maxheap.insert(arr[i]);

	// ��Ԫ�شӶ���ȡ���������򸳸�ԭ����
	for(int i=n-1; i>=0; i--)
		arr[i] = maxheap.extractMax();


}

// heapSort2, ����heapify��һ�ֽ�����תΪ�ѵķ��������̴�����
// ��ʱ, �����ѵĹ���ʱ�临�Ӷ�ΪO(n), ������Ԫ�����δӶ���ȡ����, ʱ�临�Ӷ�ΪO(nlogn)
// �����������ʱ�临�Ӷ���Ȼ��O(nlogn), ���Ǳ�����heapSort1���ܸ���, ��Ϊ�����ѵ����ܸ���
template<typename T>
void heapSort2(T arr[], int n){

	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for(int i=n-1; i>=0; i--)
		arr[i] = maxheap.extractMax();

}


/** ԭ�ض����� **/

// ԭʼ��shiftDown����ʱindex��0��ʼ������MaxHeap.h���Ǵ�1��ʼ
template<typename T>
void __shiftDown_inplace(T arr[], int n, int k){
	while( 2*k+1 <= n-1 ){
		int j = 2*k + 1;
		if( arr[j+1]>arr[j] && j+1<=n-1)
			j = j + 1;
		if(arr[k] >= arr[j]) 
			break;
		swap(arr[k], arr[j]);
		k = j;
	}

}

// ԭ�ض�����
// �����⿪��һ������, ֱ����ԭ�����Ͻ���ԭ�صĶ�����
// ��ʡ�˿ռ临�Ӷ�
template<typename T>
void heapSortInplace(T arr[], int n){
	for(int i=(n-1)/2; i>=0; i--){
		__shiftDown_inplace(arr, n, i);
	}

	for(int i=n-1; i>0; i--){
		// ������һ��Ԫ�غ����һ��Ԫ��
		// ��ʱ���һ��Ԫ�ؾ��������������Ԫ��
		// ��������
		swap(arr[0], arr[i]);
		__shiftDown_inplace(arr, i, 0);
	}
}