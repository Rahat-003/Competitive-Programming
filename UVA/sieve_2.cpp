#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

bool v[MAX];
void sieve(){
    v[0]=false;
    v[1]=false;
    for(int i=2;i<=MAX;i++){
        v[i]=true;
    }
    for(int i=2;i*i<MAX;i++){
        for(int j=2*i;j<=MAX;j+=i){
            if(v[j]==true){
                v[j]=false;
            }
        }
    }
}


int main(){
int n,m;
sieve();
while(cin>>n){
        int c=0;
    for(int i=0;i<=n;i++){

        if(v[i]){
            cout<<i<<" ";   c++;
        }
    }
    cout<<endl<<c<<endl;
}

return 0;
}
