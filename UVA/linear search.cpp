#include <iostream>
using namespace std;
int lsearch(int a[], int x,int b)
{
    for(int i=0;i<x;i++){
        if(a[i]== b){
            return i;
        }
    }
}

int main(){

int b,t,y;
cin>>t;
while(t--){
    int a[6];
    for(int i=0;i<6;i++){
        cin>>b;
        a[i]=b;
    }
    int x=sizeof(a)/sizeof(a[0]);
    cin>>y;
    cout<<lsearch(a,x,y)<<endl;
}


return 0;
}
