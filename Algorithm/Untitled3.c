#include <stdio.h>


float func(int n,float ar[]){
    float sum = 0, avg;
    for(int i = 0; i<n; i++){
        sum+=ar[i];
    }
    avg = (float)sum/n;
    return avg;
}



void main(){

    int n;
    scanf("%d",&n);

    float ar[n];

    for(int i = 0; i<n; i++){
        scanf("%f",&ar[i]);
    }

    float avg = func(n,ar);

    printf("%f\n", avg);
}
