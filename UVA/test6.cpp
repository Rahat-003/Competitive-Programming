#include <bits/stdc++.h>
using namespace std;
#define MAX 1000003
vector <bool> ar(1000003,true);
void sieve (){
    ar[0] = false;
    ar[1] = false;
    for(int i=4; i<=MAX;i+=2){
        ar[i]=false;
    }
    for(int i=3;i*i<=MAX;i++){
        for(int j=2*i;j<=MAX;j+=i){
            if(ar[j])
                ar[j]=false;
        }
    }
}

int main(){
sieve();

int t;
cin>>t;
while(t--){
    int a,b;
    vector<int> v;
    v.clear();
    cin>>a>>b;int c= 1000,d;
    for(int i=a;i<=b;i++){
        if(ar[i]){
        d=i-c;
        c=i;
        if(d>0) v.push_back(d);
        }
    }
    int cnt;
    for(int i=0;i<v.size();i++){
            cnt=0;
        for(int j=0;j<v.size();j++){
        if(v[i]==v[j]){
            cnt++;
         }
        }
    }


}










return 0;
}
