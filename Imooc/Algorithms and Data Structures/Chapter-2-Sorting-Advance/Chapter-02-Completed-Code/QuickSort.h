#include <iostream>
using namespace std;

/* QuickSort1 */

// ��arr[l...r]���ֽ���partition����
// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __patition(T arr[], int l, int r){

	// �Ż��������arr[l...r]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
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
	// �Ż�: ����С��ģ����, ʹ�ò�������
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


