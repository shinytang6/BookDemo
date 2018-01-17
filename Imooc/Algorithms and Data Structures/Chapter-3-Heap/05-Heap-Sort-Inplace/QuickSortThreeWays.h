#include <iostream>
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