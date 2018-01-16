#include <iostream>
using namespace std;


// 自底向上归并排序
// 这里是无优化版本
template<typename T>
void mergeSortBottomUp(T arr[], int n){
	for(int sz=1; sz<n; sz=sz+sz)
		// 如果限制条件为i<n, i+sz可能越界，所以要保证i+sz<n，同时后半组归并可能不足sz个元素
		for(int i=0; i+sz<n ; i=i+sz+sz)
			__merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1));
}