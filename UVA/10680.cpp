
#include <bits/stdc++.h>
using namespace std;
#define mx (int)1e6+3
bool ar[mx];
vector<int> prime;
typedef long long ll;
void sieve(){

    prime.push_back(2);

    for(int i = 3; i*i<=mx; i+=2){
        if(!ar[i]){
            for(int j = i*i; j<mx; j+=2*i)
                ar[j] = 1;
        }
    }
    for(int i = 3; i<mx; i+=2)
        if(!ar[i])
            prime.push_back(i);

    swap(prime[1],prime[2]);
}

int last(int n){
    int c2 = 0, c5 = 0;
    int ans = 1;

    for(int i = 2; i<=n; i*=2)  c2++;

    for(int i = 5; i<=n; i*=5)  c5++;

    for(int i = 0; i<c2-c5; i++)
        ans = (ans*2)%10;

    for(int i = 2; i<prime.size(); i++){
        int  p = prime[i];
        if(p>n) break;
        for(ll j = p ; j<=n; j*=p)
            ans = (ans*p)%10;
    }
    return ans;
}

int main(){
//    freopen("t.txt","r",stdin);
int n;

sieve();
//cout<<prime.size();


while(cin>>n){
    if(!n)  break;

    int ans = last(n);
    cout<<ans<<endl;
}


return 0;
}
