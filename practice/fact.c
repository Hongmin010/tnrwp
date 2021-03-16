#include <stdio.h>
int main(void){
int N,a,num=0;
scanf("%d",&N);
for(int i=1;i<N+1;i++){
  a=i;
  if(a%5==0){
  a=a/5;
  num++;
    if(a%5==0){
      a=a/5;
      num++;
        if(a%5==0){
          num++;
        }
    }

  }
}
printf("%d",num);
return 0;
}