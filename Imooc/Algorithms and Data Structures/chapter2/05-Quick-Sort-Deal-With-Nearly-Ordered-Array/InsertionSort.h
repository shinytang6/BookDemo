#include <iostream>
using namespace std;

template<typename T>
void insertionSort(T arr[], int n){
	for(int i=1; i<n; i++){
		// �Ը�ֵ����ԭ���Ľ���������������Ч�ʣ���Ϊһ��swap�������θ�ֵ
		T e = arr[i];
		int j;
		for(j=i; j>0; j--)
			if( arr[j-1] > e)
				arr[j] = arr[j-1];
			else{
				arr[j] = e;
				break;
			}
	}
}



template<typename T>
void insertionSort(T arr[], int l, int r){
	for(int i=l+1; i<=r; i++){

	 T e = arr[i];
        int j;
        for (j = i; j > l ; j--)
			if(arr[j-1] > e)
				 arr[j] = arr[j-1];
			else{
				arr[j] = e;
				break;
			}
    
	}
}