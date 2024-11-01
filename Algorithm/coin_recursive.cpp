#include <bits/stdc++.h>
using namespace std;

vector<int> v = {1,3,4};

int ar[1002];
int br[1002];

int coin(int k){
    if(!k)  return k;

    for(auto i:v)
        if(k==i){
        br[k] = k;
         return 1;
        }

    if(ar[k]!=-1)   return ar[k];

    int mx = 2e9;

    for(int i = 0 ; i<v.size(); i++){
        int x = v[i];

    if(k-x>=0){
        int cnt = 1 + coin(k-x);
        if(cnt<mx){
            mx = cnt;
            br[k] = x;
        }

    }

    }

    ar[k] = mx;

    return mx;
}

int main(){

memset(ar,-1,sizeof ar);

ar[0] = 0;

int a;

while(cin>>a){

    cout<<coin(a)<<endl;
    for(int i = a;br[i]; i-=br[i] )
    cout<<br[i]<<" ";
    puts("");

}

return 0;
}
