#include <iostream>
using namespace std;

// argument : array & number of array
void selectionSort(int arr[], int n){
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
	int arr[] = {10,5,6,1,4,9,2,8,3,7};
	selectionSort(arr,10);
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}