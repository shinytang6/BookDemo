#include <iostream>
using namespace std;

// ��·���������� aa[l...r]
// ��arr[l...r]��Ϊ <v; ==v; >v ������
// ֮��ݹ�� <v; >v �����ּ���������·��������

template<typename T>
void __quickSort3Ways(T arr[], int l, int r){
	/*if(l>=r)
		return;*/
	// �Ż�: ����С��ģ����, ʹ�ò�������
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

	// ��Ϊ��·������Ҫ������������ֵ������ֱ��д������
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
			// i����Ҫ��
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