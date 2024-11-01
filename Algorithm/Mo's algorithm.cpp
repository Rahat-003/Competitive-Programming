/***********************************

    Mo's Algorithm
    Finding distinct element from [l,r]
    LightOj 1188-Fast Queries

    Optimization:
    Blocks are numbered from 1 to N/sqrt(N)

    if two queries are in same block
        for odd block, sort in ascending order of r
        for even block,sort in descending order of r

    Similar Problem: https://codeforces.com/contest/86/problem/D
        (optimization must)

************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:\n",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 100001
typedef pair<int,int> pp;

int block;
struct node{
    int l,r,id;
    bool operator < (const node &N) const{
        int b1 = 1+l/block,   b2 = 1+N.l/block; /// blocks are numbered from 1
        if(b1!=b2)  return b1<b2;

        if(b1&1)    return r<N.r;
        return r>N.r;
    }
};

vector<node> v;
vector<pp> query;
int ar[mx],cnt[mx];

int _add(int id){
    cnt[ar[id]]++;
    return (cnt[ar[id]]==1?1:0);
}
int _remove(int id){
    cnt[ar[id]]--;
    return (cnt[ar[id]]==0?-1:0);
}

void fn(){
    int AR = 0,AL = 0,ans = 1;
    cnt[ar[0]]++;
    for(int i = 0; i<v.size(); i++){
        int l = v[i].l,r = v[i].r, id = v[i].id;

        while(true){
            if(AL==l && AR==r)      break;
            if(AL>l){
                AL--;
                ans+=_add(AL);
            }
            if(AL<l){
                ans+=_remove(AL);
                AL++;
            }
            if(AR<r){
                AR++;
                ans+=_add(AR);
            }
            if(AR>r){
                ans+=_remove(AR);
                AR--;
            }

        }
        query.push_back(pp(id,ans));
    }
    sort(query.begin(),query.end());

}

int main(){
//   read;

int t,tc = 0;

scanf("%d",&t);

while(t--){
    memset(cnt,0,sizeof ar);
    int n,e;
    scanf("%d",&n);
    block = sqrt(n);
    scanf("%d",&e);
    for(int i = 0; i<n; i++)    scanf("%d",&ar[i]);
    for(int i = 0; i<e; i++){
        int l,r;
        scanf("%d%d",&l,&r);
        --l,--r;
        v.push_back({l,r,i});
    }
    sort(v.begin(),v.end());
    case;
    fn();
    for(int i = 0; i<query.size(); i++)
        printf("%d\n",query[i].second);
    query.clear();
    v.clear();
}


return 0;
}
