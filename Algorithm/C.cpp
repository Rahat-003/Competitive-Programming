#include <cstdio>
#include <cstdlib>
#include <deque>
#include <memory.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define MX 32000

int ar[1005],p,target;

bool check(int n){
    if(n<-MX  || n>MX)  return 0;
    return 1;
}
int dp[101][2*MX+2];

bool fn(int pos,int tot){
    int &ret = dp[pos][tot];
    if(ret!=-1)     return ret;
    tot-=MX;
    if(pos==p)  return target==tot;

    int fl = 0;
    int x = ar[pos];

    if(check(tot+x))    fl|=fn(pos+1,tot+x+MX);
    if(check(-x+tot))   fl|=fn(pos+1,-x+tot+MX);
    if(pos){
        if(check(tot*x))                fl|=fn(pos+1,tot*x+MX);
        if(abs(tot)%x==0 && check(tot/x))    fl|=fn(pos+1,MX+tot/x);
    }
    dp[pos][tot+MX] = fl;
    return fl;
}

deque<int> v;

bool flag;

void go(int pos,int tot){
    if(flag)                return;

    if(pos==p){
        if(target!=tot-MX) return;
        for(int i = 0; i<v.size(); i++){
            if(i==0 && v[i]==1) printf("-");
            if(i){
                if(v[i]==0)    printf("+");
                if(v[i]==1)    printf("-");
                if(v[i]==2)    printf("*");
                if(v[i]==3)    printf("/");
            }
            printf("%d",ar[i]);
        }
        printf("=%d\n",target);
        flag = 1;
        return;
    }
    if(dp[pos][tot]!=1)     return;
    tot-=MX;

    bool fl = false;

    int x = ar[pos];
    if(check(tot+x)){
        v.push_back(0);
        go(pos+1,tot+x+MX);
        v.pop_back();
    }
    if(check(-x+tot)){
        v.push_back(1);
        go(pos+1,-x+tot+MX);
        v.pop_back();
    }
    if(pos){
        if(check(tot*x)){
            v.push_back(2);
            go(pos+1,tot*x+MX);
            v.pop_back();
        }
        if(abs(tot)%x==0 && check(tot/x)){
            v.push_back(3);
            go(pos+1,MX+tot/x);
            v.pop_back();
        }
    }
}


main(){
int t;
read;
scanf("%d",&t);
while(t--){
    memset(dp,-1,sizeof dp);
    flag = 0;
    scanf("%d",&p);
    for(int i = 0 ; i < p ; i++)        scanf("%d",ar+i);

    scanf("%d",&target);
    int ans = fn(0,MX);

    if(ans) go(0,MX);
    else puts("NO EXPRESSION");
    v.clear();
}

return 0;
}


