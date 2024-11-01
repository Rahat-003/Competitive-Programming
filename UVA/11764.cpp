#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
int a[51];
int n;
int b=0;

while(t--){
        cin>>n;
       for(int i=0;i<n;i++){
        cin>>a[i];
       }
       int high=0;
       int low=0;
    for(int i=1;i<n;i++){
       if(a[i]>a[i-1]){
         high++;
        }
        if(a[i]<a[i-1])
            low++;
    }
    printf("Case %d: %d %d\n",++b,high,low);



    }





return 0;
}
