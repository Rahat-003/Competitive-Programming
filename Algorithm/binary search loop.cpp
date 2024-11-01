#include <bits/stdc++.h>
using namespace std;

int ar[1000];

void bin(int x,int n){

    int l = 0,h = n-1;
    while(l<=h){
        int m = (l+h)/2;
        cout<<l<<" "<<h<<" "<<m<<endl;
        if(ar[m]==x){
            cout<<m<<endl;
            return;
        }
        if( (l==h || h-l==1) && ar[m]!=x){
            puts("Not found");
            return;
        }
        if(ar[m]>x) h = m-1;
        else l = m+1;
    cout<<"b";
    }

}

int main(){

int n;
while(cin>>n){

    for(int i = 0;i<n; i++)
        cin>>ar[i];

    sort(ar,ar+n);
    int x;
    cin>>x;

    bin(x,n);
}

return 0;
}
