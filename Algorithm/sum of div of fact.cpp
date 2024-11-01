#include <bits/stdc++.h>
using namespace std;

set<int> s;
int fact(int n){
int temp;
if(n<=1)
    return 1;
temp= n*fact(n-1);
return temp;
}
void pf(int n){
    if(n==1)
        s.insert(1);
    for(int i=1;i<=n/2;i++){
        if(n%i==0){
           s.insert(i);
           s.insert(n/i);
        }
    }
}
int main(){
    int n;
while(cin>>n){
    pf(fact(n));
int    ans=0;
    for(auto it=s.begin();it!=s.end();++it){
        ans+=*it;
    }
    cout<<ans<<endl;
s.clear();
}return 0;
}
