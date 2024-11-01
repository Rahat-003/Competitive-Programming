#include <iostream>
using namespace std;

int a[900][900];
int ncr(int n,int r){
    if(n==r || r==0) return 1;
    if(r==1) return n;
    if(a[n][r]!=0) return a[n][r];
    else {
        a[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
        return a[n][r];
    }




}

int main(){
int n,r;
while(cin>>n>>r){


    cout<<ncr(n,r)<<endl;
}


return 0;
}
