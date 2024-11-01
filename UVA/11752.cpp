#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 65536
vector<bool> prime(MAX,true);

void sieve(){

    prime[0]=false;
    prime[1]=false;
    for(int i=4;i<MAX;i+=2){
        prime[i] = false;
    }
    for(int i = 3; i*i<MAX;i++){
        if(prime[i]){
            for(int j=2*i;j<MAX;j+=i){
               prime[j]=false;
            }
        }
    }


}
unsigned ll pow(ll a, ll b){
    unsigned ll ans=1;
    for(ll i = 0;i<b;i++){
        ans*=a;
    }
    return ans;
}
int main(){
    freopen("tst.txt","w",stdout);
sieve();

unsigned ll n,a;

vector <ll> power;
for(int i =3 ;i<64;i++){
    if(prime[i]==false)
        power.push_back(i);
}
set<unsigned ll> super;
super.insert(1);
for(ll i=2; i<MAX;i++){
    for(ll j=0;j<power.size();j++){
        n = pow(i,power[j]);
        if(n>0){
            super.insert(n);
        }
    }
}

for(auto it = super.begin(); it!=super.end(); ++it)
  //  if(*it>0)
        cout<<*it<<endl;


return 0;
}
