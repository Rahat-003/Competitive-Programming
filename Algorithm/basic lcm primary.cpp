#include <bits/stdc++.h>
using namespace std;
multiset<int> ms;

void bal(int x){
while(x%2==0){
    ms.insert(2);
    x/=2;
//    cout<<2<<" ";
}
for(int i=3;i*i<=x;i+=2){
    while(x%i==0){
        ms.insert(i);
   //     cout<<i<<" ";
        x/=i;
    }
}
if(x>2){ms.insert(x);
//cout<<x<<" ";
}
}

int main(){
multiset<int>s1 ;
multiset<int>s2;
int a,b;
cin>>a>>b;
bal(a);
swap(s1,ms);
bal(b);
swap(s2,ms);int ans=1;
for(auto it=s1.begin();it!=s1.end();++it){
    ans*=(*it);
    if(s2.find(*it)!=s2.end()){
        s2.erase(s2.find(*it));
    }
}
    for(auto it=s2.begin();it!=s2.end();++it){
        ans*=(*it);
    }
    cout<<ans;






return 0;
}
