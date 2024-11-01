
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mx 1500
#define Mx (int)2e6+1

bool ar[mx];
vector<int> prime;

struct node{
    int a,b;
    node(int p = 0,int q = 0){
        a = p;
        b = q;
    }

    bool operator < (const node &n1){
        if(b!=n1.b) return b<n1.b;
        return a<n1.a;
    }
};

node num[Mx];

void sieve(){
    prime.push_back(2);
    ar[0] = ar[1] = 1;
    for(int i = 4; i<mx; i+=2)
        ar[i] = 1;
    for(int i = 3; i*i<=mx; i+=2){
        if(!ar[i]){
            for(int j = i*i; j<mx; j+=2*i)
                ar[j] = 1;
        }
    }
    for(int i = 3; i<mx; i+=2){
        if(!ar[i])
            prime.push_back(i);
    }
}

int factor(int n){
    int ans = 0;
    for(auto i:prime){
        if(i>n) break;
        while(n%i==0){
            n/=i;
            ans++;
        }
    }
    if(n>1) ans++;
    return ans;
}


int main(){
    freopen("tst.txt","r",stdin);
sieve();

int n;

for(int i = 0; i<Mx; i++){
    num[i].a = i;
    num[i].b = factor(i);
}

sort(num,num+Mx);
int tc = 0;

while(scanf("%d",&n)==1){
        if(!n)  break;
    int ans = num[n].a;
    printf("Case %d: %d\n",++tc,ans);
}


return 0;
}


