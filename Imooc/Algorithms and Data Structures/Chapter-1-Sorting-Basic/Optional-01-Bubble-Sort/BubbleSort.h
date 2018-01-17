#include <iostream>
using namespace std;

// My bubble sort
template<typename T>
void bubbleSort(T arr[], int n){
	for(int i=0; i<n; i++){
		// 每次都把最大的元素放最后
		for(int j=0; j<n-1; j++){
			if(arr[j] > arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
}

// bobo's bubble sort
// 比起我写的，就不用每次都循环n^2次了，一旦排序完就退出循环
template<typename T>
void bubbleSort_bobo(T arr[], int n){
	bool swapped;
	do{
		swapped = false;
		for(int i=1; i<n; i++){
			if(arr[i-1]>arr[i]){
				swapped = true;
				swap(arr[i-1], arr[i]);
			}
		}

		// 优化
		// 可加一条n--,因为每一次Bubble Sort都将最大的元素放在了最后的位置
		// 所以下一次排序，可不看最后的元素
		 n--;

	}while(swapped);
}

// bobo's optimized bubble sort
template<typename T>
void bubbleSort2_bobo(T arr[], int n){
	int new_n;
	do{
		new_n = 0;
		for(int i=1; i<n; i++){
			if(arr[i-1]>arr[i]){
				// 记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
				new_n = i;
				swap(arr[i-1], arr[i]);
			}
		}
		n = new_n;
	}while(n>1);
}