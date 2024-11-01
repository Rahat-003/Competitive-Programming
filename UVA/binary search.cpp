#include <bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>v,int h,int l,int a){
if(l<=h){
        int m=l+(h-l)/2;
    if(v[m]==a)
        return m;
    if(v[m]>a)
        return binarysearch(v,m-1,l,a);
    else
        return binarysearch(v,h,m+1,a);
}
return -1;
}
int main(){
vector<int>v;
int n;
cin>>n;
while(n--){
    int a;
    cin>>a;
    v.push_back(a);
}
sort(v.begin(),v.end());
int x;
cin>>x;
cout<<binarysearch(v,v.size()-1,0,x);

return 0;
}
