#include <iostream>
//#include <algorithm>
#include <string>
using namespace std;

template<typename T>
void selectionSort (T arr[], int n) {
	for(int i=0; i<n; i++){
		int minIndex = i;
		for(int j=i+1; j<n; j++)
			if(arr[j]<arr[minIndex])
				minIndex = j;
		
		swap(arr[minIndex],arr[i]);
	}
}

int main(){
	int a[10] = {10,9,8,7,6,5,4,3,1,2};
	selectionSort(a,10);
	for(int i=0; i<10; i++)
		cout<<a[i]<<" ";
	cout<<endl;

	float b[4] = {4.4,3.3,2.2,1.1};
	selectionSort(b,4);
	for(int i=0; i<4; i++)
		cout<<b[i]<<" ";
	cout<<endl;

	string c[4] = {"D","C","B","A"};
	selectionSort(c,4);
	for(int i=0; i<4; i++)
		cout<<c[i]<<" ";
	cout<<endl;
	return 0;
}
