#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

vector<bool> v(MAX,true);
void sieve(){
v[0]=v[1]=false;
int a=2;
while(a<MAX){
    a+=2;
    v[a]=false;
}
for(int i=3;i*i<=MAX;i++){
    for(int j=i*i;j<MAX;j+=i){
        if(v[j]){
            v[j]=false;
        }
    }
}
}

int main(){
int n;
cin>>n;
sieve();
for(int i=1;i<=n;i++){
    if(v[i]) cout<<i<<" ";
}

return 0;
}
