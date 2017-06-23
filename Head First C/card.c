#include <stdio.h>
#include <stdlib.h>
int main(){
char card_name[3];
puts("please enter name:");
scanf("%2s",card_name);
int val=0;
if(card_name[0]=='K')
  val=10;
else 
  val=11;
printf("The number is:%i\n",val);
return ;

}
