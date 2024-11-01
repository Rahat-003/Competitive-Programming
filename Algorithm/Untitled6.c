#include<stdio.h>
int main(){
int sum=0;
printf("odd numers from 1 to 1000: \n");
for (int i=1;i<=1000;i++){
    if(i%2!=0){
        sum=sum+i;
    }
}


printf("%d",sum);









return 0;
}
