#include <bits/stdc++.h>
using namespace std;


int main(){

freopen("332.txt","r",stdin);
int a,  z=1;
float f;

while(cin>>a){
    if(a==-1)   break;
    string s;
    cin>>f;
    stringstream ss;
    ss<<f;
    s=ss.str();
    float m=1.0,n=1.0;
    int x=s.size()-2;
    for(int i=0;i<a-1;i++)
        m*=10.0;
    for(int i=0;i<x;i++)
        n*=10.0;
    float mm,nn;
    nn=f*n;
    mm=f*m;
    int k=(int)nn;
    int l=(int)(floor(mm));
    int p=k-l;
    int q=n-m;
//    cout<<p/__gcd(p,q)<<" "<<q/__gcd(p,q)<<endl;
    printf("Case %d: %d/%d\n",z++,p/__gcd(p,q),q/__gcd(p,q));
    s.clear();
}


return 0;}
