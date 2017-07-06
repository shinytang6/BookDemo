#include <stdio.h>
#define LEN 8
int a[LEN] = {1,2,2,2,5,6,8,9};
int binarysearch(int number){
	int first = 0;
	int last = 7;
	while(first<last){  
	int medium = (first+last)/2;
		if(a[medium]>number)
	       last=medium-1;
		else if(a[medium]<number)
		   first=medium+1;
	    else
		   return medium;
	}
}
int main(){
	int place = binarysearch(1);
	printf("%d\n",place);
}
