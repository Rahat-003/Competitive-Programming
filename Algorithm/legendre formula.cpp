#include <bits/stdc++.h>
using namespace std;
multiset <int> v;
void pf(int n){

    while(n%2==0){
        v.insert(2);
        n/=2;
    }
    for(int i=3;i<=n;i+=2){
        while(n%i==0){
            v.insert(i);
            n/=i;
        }
    }
    if(n>2) v.insert(n);

}

int main(){
int n,p;
while(cin>>n>>p){
for(int i=2;i<=n;i++){
    pf(i);
}
int c=0;
for(auto it=v.begin();it!=v.end();++it){
    if(*it==p) c++;
}
cout<<c<<endl;
v.clear();
}
return 0;
}
