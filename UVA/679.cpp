#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int sq;

int funct(int node, int ball){
    int left,right;
    left=2*node; right=left+1;
    if(left<sq && right<sq){
        if(ball%2==0) funct(right, ball/2);
        else funct(left, ball/2 +1);
    }
    else return node;
}

int main(){
int t;
cin>>t;

while(t--){
    int a,b;
    cin>>a>>b;
    sq=pow(2,a);
    printf("%d\n",funct(1,b));
}



return 0;
}
