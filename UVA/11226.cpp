
#include <cstdio>
#include <vector>
#define Mx (int)5e5+3
#define mx 710
using namespace std;

bool ar[mx];
vector<int> prime;

int num[Mx], mark[Mx];
int Cnt[Mx];

void sieve(){
    prime.push_back(2);
    for(int i = 3; i*i<=mx; i+=2){
        if(!ar[i]){
            for(int j = i*i; j<mx; j+=2*i)
                ar[j] = true;
        }
    }
    for(int i = 3; i<mx; i+=2)
        if(!ar[i])  prime.push_back(i);
}

void sumOf(int n){
    int x = n;
    if(mark[n]) return;
    int ans = 0, id =1;
    for(auto i:prime){
        mark[i] = i;
        if(i>n) break;
        while(n%i==0){
            id*=i;
            ans+=i;
            n/=i;
            mark[id] = ans;

            if(mark[n]){
                ans+=mark[n];
                n = 1;
            }

        }
    }

    if(n>1) {
    id*=n;
    ans+=n;
    mark[n] = n;
    mark[id] = ans;
    }
    mark[x] = ans;

}

void func(){
    for(int i = 2; i<Mx; i++){
        if(mark[i]==i){
            Cnt[i] = 1;
            continue;
        }
        int id = i;
        int t = 0;
        int p = mark[i];
        while(mark[id]!=id){
            id = mark[id];
            t++;

            if(Cnt[id]){
            t+=Cnt[id];
            break;
            }
        }
        Cnt[i] = t;
    }
}

int main(){

sieve();

for(int i = Mx-2; i>=2; i--){
    sumOf(i);
}
func();

int t;
scanf("%d",&t);

for(int I = 1; I<=t; I++){
    int p,q;
    scanf("%d %d",&p,&q);
    if(p>q) swap(p,q);

    int ans = -1;
    for(int i = p;i<=q; i++){
        ans = max(ans,Cnt[i]);
    }
    printf("Case #%d:\n%d\n",I,ans);
}


return 0;
}
