
#include <cstdio>
#include <unordered_map>
using namespace std;

unordered_map<int,int> mp,np;
#define mx (int)1e4+5
int ar[mx];

void sieve(){
    ar[0] = ar[1] = 1;
    for(int i = 2; i<mx; i+=2)
        ar[i] = 2;

    for(int i = 3; i<mx; i+=2){
        if(!ar[i]){
            for(int j = i; j<mx; j+=i)
                ar[j] = i;
        }
    }
}

void factor(int n, unordered_map<int,int> &v){
    while(n>1){
        int x = ar[n];
        v[x]++;
        n/=x;
    }

}
int m,n;

int funct(){
    int ans = (int)2e7;
    for(auto it:np){
        int x = it.first;
        int y = it.second;
     if(!mp[x]) return 0;
        int z = mp[x]/y;
        ans = min(ans,z);
    }
    return ans;
}

int main(){
    sieve();

int t;
scanf("%d",&t);

for(int tc = 1; tc<=t; tc++){
    scanf("%d %d",&n,&m);
    factor(n,np);
    for(int i = 2; i<=m; i++)
    factor(i,mp);

    int ans = funct();
    if(ans)  printf("Case %d:\n%d\n",tc,ans);
    else    printf("Case %d:\nImpossible to divide\n",tc);

    mp.clear();
    np.clear();

}


return 0;
}
