#include <bits/stdc++.h>
using namespace std;
int main(){
vector <int> v;
int n;
cin>>n;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    v.push_back(a);
}
int c;cin>>c;
for(int i=0;i<c;i++){
    int d;cin>>d;
    int f,e;
    e=v[lower_bound(v.begin(),v.end(),d)-v.begin()-1];
    f=v[upper_bound(v.begin(),v.end(),d)-v.begin()];
    if(binary_search(v.begin(),v.end(),e)){
        cout<<e<<" ";
    }
    else cout<<"X"<<" ";
    if(binary_search(v.begin(),v.end(),f)){
        cout<<f<<endl;;
    }
    else cout<<"X "<<endl;
}



return 0;
}
