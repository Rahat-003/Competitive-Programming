#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 10001
bool arr[mx];
vector<int> prime = {2};

void sieve(){
    for(int i = 3; i*i<=mx; i+=2)   if(!arr[i])  for(int j = i*i; j<mx; j+=2*i)  arr[j] = true;
    for(int i = 3; i<mx; i+=2)  if(!arr[i])  prime.push_back(i);
}
vector<int> v,D;
int k;


int ar[100];

void go(int pos,int n){
    if(pos==v.size()){
        D.push_back(n);
        return;
    }
    int x = 1;
    for(int i = 0; i<ar[pos]; i++){
        x*=v[pos];
        go(pos+1,n*x);
    }
    go(pos+1,n);
}

void fn(int n){
    int id = 0;
    for(int i = 0; i<prime.size(); i++){
        int p = prime[i];
        if(p*p>n)   break;
        if(n%p==0){
            int cnt = 0;
            v.push_back(p);
            while(n%p==0){
                cnt++;
                n/=p;
            }
            ar[id++] = cnt;
        }
    }
    if(n>1){
        ar[id] = 1;
        v.push_back(n);
    }
}

main(){
int t,tc = 0;
sieve();

while(1==scanf("%d",&k)){
    memset(ar,0,sizeof ar);
    fn(k*k);
    go(0,1);
    sort(D.begin(),D.end());
    int sz = D.size()-1;
    printf("%d\n",1+D.size()/2);
    for(int i = 0; i<=D.size()/2; i++){
        int y = D[i]+k,x = D[sz-i]+k;
        printf("1/%d = 1/%d + 1/%d\n",k,x,y);
    }

    v.clear();
    D.clear();
}

return 0;
}
