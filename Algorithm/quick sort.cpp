#include <iostream>
using namespace std;

void swp(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int part(int ar[],int l,int h){
    int pivot=ar[h];
    int m=l-1;

    for(int i=l;i<h;i++){
        if(ar[i]<=pivot){
           m++;
           swp(&ar[m],&ar[i]);
        }
    }
    swp(&ar[m+1],&ar[h]);
    return m+1;
}
void qs(int ar[],int l, int h){
    if(l<h){
    int pi= part(ar,l,h);
    qs(ar,l,pi-1);
    qs(ar,pi+1,h);
    }
}
int main(){

int n;
cin>>n;int ar[n];
for(int i=0;i<n;i++){
    cin>>ar[i];
}
qs(ar,0,n-1);

for(int i=0;i<n;i++){
    cout<<ar[i]<<" ";
}
return 0;
}
