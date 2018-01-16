#include <iostream>
using namespace std;

// My bubble sort
template<typename T>
void bubbleSort(T arr[], int n){
	for(int i=0; i<n; i++){
		// ÿ�ζ�������Ԫ�ط����
		for(int j=0; j<n-1; j++){
			if(arr[j] > arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
}

// bobo's bubble sort
// ������д�ģ��Ͳ���ÿ�ζ�ѭ��n^2���ˣ�һ����������˳�ѭ��
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

		// �Ż�
		// �ɼ�һ��n--,��Ϊÿһ��Bubble Sort��������Ԫ�ط���������λ��
		// ������һ�����򣬿ɲ�������Ԫ��
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
				// ��¼���һ�εĽ���λ��,�ڴ�֮���Ԫ������һ��ɨ���о�������
				new_n = i;
				swap(arr[i-1], arr[i]);
			}
		}
		n = new_n;
	}while(n>1);
}