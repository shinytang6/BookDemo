#include <iostream>
#include <string>
#include "Student.h"
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
	// int array
	int arr1[] = {10,5,6,1,4,9,2,8,3,7};
	selectionSort(arr1,10);
	for(int i=0; i<10; i++){
		cout<<arr1[i]<<" ";
	}
	cout<<endl;

	// float array
	float arr2[] = {4.4,3.3,2.2,1.1};
	selectionSort(arr2,4);
	for(int i=0; i<4; i++){
		cout<<arr2[i]<<" ";
	}
	cout<<endl;

	// string array
	string arr3[] = {"D","C","B","A"};
	selectionSort(arr3,4);
	for(int i=0; i<4; i++){
		cout<<arr3[i]<<" ";
	}
	cout<<endl;

	// self-define struct array
	Student arr4[4] = { {"D",90} , {"C",100} , {"B",95} , {"A",95} };
    selectionSort(arr4,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<arr4[i];
    cout<<endl;
}