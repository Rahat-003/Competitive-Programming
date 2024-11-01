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
for(int i=0;i<ar.size();i++){
    if(ar[i])
        cout<<i<<" ";
}


return 0;
}
