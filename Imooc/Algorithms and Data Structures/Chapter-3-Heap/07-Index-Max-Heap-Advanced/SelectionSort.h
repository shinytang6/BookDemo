#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T arr[], int n){
	for(int i=0; i<n; i++){
		// find minimum value between [i,n)
		int minIndex = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[minIndex])
				minIndex = j;
		}

		swap(arr[i],arr[minIndex]);
	}
}
