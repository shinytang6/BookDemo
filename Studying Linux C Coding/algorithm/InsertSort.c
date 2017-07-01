#include <stdio.h>
#define MAX 5
int a[MAX]={10,5,6,4,2};
void InsertSort(){
int i,j;
int key;
for(i=0;i<MAX;i++){
  key =a[i];
  j = i-1;
  while (j>=0 && a[j]>key){
     a[j+1]=a[j];
     j--;
   }
   a[j+1] = key;
}
  printf("%d,%d,%d,%d,%d\n",a[0],a[1],a[2],a[3],a[4]);
}
int main(){
  InsertSort();
}
