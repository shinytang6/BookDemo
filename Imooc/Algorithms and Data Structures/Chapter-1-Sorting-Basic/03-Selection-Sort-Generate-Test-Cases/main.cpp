#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
using namespace std;

// using template 
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

int main(){
	
	int n = 1000;
	int *arr = SortTestHelper::generateRandomArray(n,0,n);
	selectionSort(arr , n);
	SortTestHelper::printArray(arr, n);

	// release memory
	delete[] arr;
	return 0;

}