#include <iostream>
using namespace std;

/* QuickSort1 */

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


/* QuickSort2 */

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __patition2(T arr[], int l, int r){

	// 优化：随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
	srand((unsigned)time(NULL));
	swap(arr[l], arr[rand()%(r-l+1)+l]);
	T v = arr[l];
	
	// arr[l+1...i) <=v;  arr(j...r] >= v
	// 初始化时要为空
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
	// 优化: 对于小规模数组, 使用插入排序
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