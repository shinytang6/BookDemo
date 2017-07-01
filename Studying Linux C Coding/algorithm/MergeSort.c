#include <stdio.h>
#define LEN 8
int a[LEN] = {5,2,4,7,1,3,2,6};
int merge(int first,int medium,int last){
    int len1 = medium-first+1;
	int len2 = last-medium;
	int arr1[len1];
	int arr2[len2];
	int i,j;
	for ( i = 0; i<len1 ; i++)
       arr1[i] = a[first+i];
	for ( j = 0; j<len2 ; j++)
	   arr2[j] = a[medium+1+j];
	int k=first;
	int m=0,n=0;
	while(1){
	   if(arr1[m]<arr2[n]){
		  a[k]=arr1[m];
		  m++;
		  k++;
	   }
	   else{
	      a[k]=arr2[n];
     	  n++;
		  k++;
	   }
	   if(m>=len1||n>=len2)
		 break;
	}
    if(m<len1){
		int b;
		for(b=m;b<len1;b++){
		  a[k]=arr1[b];
		  k++;
		}
	}
    else if(n<len2){
		int c;
		for(c=n;c<len2;c++){
			a[k]=arr2[c];
			k++;
		}
	}


}

int sort(int first,int last){
	if(first<last){
	int medium;
	medium = (last+first)/2;
	sort(first,medium);
    sort(medium+1,last);
	merge(first,medium,last);	
	}
}
int main(){
	sort(0,7);
	int k;
	for(k=0;k<LEN;k++){
		printf("%d\n",a[k]);
	}
}
