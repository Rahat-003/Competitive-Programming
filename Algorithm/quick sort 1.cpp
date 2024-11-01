#include <iostream>
using namespace std;
void s(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int part(int ar[],int l,int h){
    int pivot=ar[h];
    int m=l-1;
    for(int i=0;i<h;i++){
        if(ar[i]<=pivot){
            m++;
            s(&ar[m],&ar[i]);
        }
    }
    s(&ar[h],&ar[m+1]);
    return m+1;
}
void qs(int ar[],int l,int h){
    if(l<h){
        int pi=part(ar,l,h);
        qs(ar,l,pi-1);
        qs(ar,pi+1,h);
    }
}
int main(){
int n,bal;cin>>n;int ar[n];for(int i=0;i<n;i++){cin>>bal;ar[i]=bal;}
qs(ar,0,n-1);
for(int j=0;j<n;j++){cout<<ar[j]<<" ";}
return 0;
}
