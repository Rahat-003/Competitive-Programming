#include <cstdio>
#include <vector>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
typedef long long ll;
using namespace std;

#define mx (int)1e6+2
vector<int> D[mx],v;
bool vis[mx];
int cnt = 0;
void make(){
    for(int i = 2; i<mx; i++){
        for(int j = i; j<mx; j+=i)
            D[j].push_back(i);
    }
}

int ar[mx];

int f(int a){
    if(ar[a]!=a)   ar[a] = f(ar[a]);
    return ar[a];
}

int main(){

int t,tc = 0;
make();
scanf("%d",&t);
while(t--){
    int e;  scanf("%d",&e);
    cnt = 0;
    for(int i = 0; i<mx; i++){
    vis[i] = false;
    ar[i] = i;
    }

    for(int i = 0; i<e; i++){
        int a;  scanf("%d",&a);
    if(a!=1) v.push_back(a);
    else {
        cnt++;  continue;
    }
        for(auto j:D[a]){
            int pi = f(a);
            int pj = f(j);
            if(pi!=pj)  ar[pj] = pi;
        }
//        if(ar[a]!=a)    ar[a] = f(ar[a]);
    }

    for(auto i:v)
    if(i==ar[i] && i!=1 && !vis[i]){
     cnt++;
     vis[i] = true;
    }

    case;   printf(" %d\n",cnt);
    v.clear();
}


return 0;
}


