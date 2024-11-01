#include <bits/stdc++.h>
#include <vector>
using namespace std;
int binsearch(vector<int> v,int l,int h, int x){
    if(l<=h){
       int m=(l+h)/2;
        if(x==v[m]){
        return m;
        }
        if(x>v[m]){
        return binsearch(v,m+1,h,x);
        }
        else return binsearch(v,l,m-1,x);
    }
return -1;
}

int main(){
int a,x;
cin>>a;
vector<int> v;
while(a--){
        int b;cin>>b;
    v.push_back(b);
}
sort(v.begin(),v.end());cin>>x;
cout<<binsearch(v,0,v.size()-1,x);
return 0;
}
