#include <bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;


for(int i=0;i<t;i++){
    int b=0,n;
    char c;
    while(1){
        scanf("%d",&n);
        scanf("%c",&c);
        if(n>b) b=n;
        if(c!=' ') break;
    }
    printf("Case %d: %d\n",i+1,b);
}



return 0;
}

