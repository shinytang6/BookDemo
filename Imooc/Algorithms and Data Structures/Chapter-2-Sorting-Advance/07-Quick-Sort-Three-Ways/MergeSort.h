#include <iostream>
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
	/*if(l >= r) 
		return;*/

	// 优化2: 对于小规模数组, 使用插入排序
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);
	// 优化1：判断数组是否已经有序，无序才去归并
	if(arr[mid]>arr[mid+1])
		__merge(arr, l, mid, r);
}


template<typename T>
void mergeSort(T arr[], int n){
	__mergeSort(arr, 0, n-1);

}


// 自底向上归并排序
// 这里是无优化版本
template<typename T>
void mergeSortBottomUp(T arr[], int n){
	for(int sz=1; sz<n; sz=sz+sz)
		// 如果限制条件为i<n, i+sz可能越界，所以要保证i+sz<n，同时后半组归并可能不足sz个元素
		for(int i=0; i+sz<n ; i=i+sz+sz)
			__merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1));
}