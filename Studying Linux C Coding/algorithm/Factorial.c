#include <stdio.h>
int factorial(int n){
 if(n==0)
   return 1;
 else
 {
   int recurse=factorial(n-1);
   int result=n*recurse;
   return result;
 
 }
}

int main(){
  int num = 5;
  int result = factorial(num);
  printf("result is %d\n",result);
}



