#include <iostream>
using namespace std;

template<typename T>
void shellSort(T arr[], int n){
	int gap = n/2;
	/*int gap = 1;
    while( gap < n/3 )
        gap = 3 * gap + 1;*/
	while(gap > 0){
		for(int i=gap; i<n; i++){
			T e = arr[i];
            int j;
			for(j=i; j>0; j=j-gap)
				if(e<arr[j-gap])
					arr[j] = arr[j-gap];
				else{
					arr[j] = e;
					break;
				}
		}
	
		gap = gap/2;
		//gap= gap/3;
	}
}