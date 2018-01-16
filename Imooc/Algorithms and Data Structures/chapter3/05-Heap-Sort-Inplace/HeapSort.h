#include <iostream>
#include "Heap.h"
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