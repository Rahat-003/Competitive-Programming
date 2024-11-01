/**
    Given N elements and some queries.
    For each query given 3 integers l,r,k. 1<=l<=r<=N. 1<=k<=N
    For each query output no. of integer in [l,r] which is less than k
**/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 100005

int N,ar[mx],cnt[mx];

struct node{
    int x;

    node *L,*R;

    node(int z = 0,node *p = NULL, node *q = NULL):x(z),L(p),R(q){}

    void build(int l = 0,int r = N){
        if(l==r){
            node *z = new node();
            return;
        }
        int m = l+r>>1;
        L = new node();
        R = new node();
        L->build(l,m);
        R->build(m+1,r);
        x = L->x+R->x;
    }

    node *update(int ql,int l = 0, int r = N){
        if(r<ql || ql<l)    return this;
        if(ql==l && l==r){
            node *z = new node(cnt[ql]+1);
            return z;
        }
        node *ret = new node();
        int m = l+r>>1;
        ret->L = L->update(ql,l,m);
        ret->R = R->update(ql,m+1,r);
        ret->x = ret->L->x+ret->R->x;
        return ret;
    }

    int query(int ql,int qr,int l = 0,int r = N){
        if(r<ql || qr<l)    return 0;
        if(ql<=l && r<=qr)  return x;
        int m = l+r>>1;
        return L->query(ql,qr,l,m)+R->query(ql,qr,m+1,r);
    }

}  *root[mx];

int fn(int id,int k){
    return root[id]->query(0,k);
}

main(){
int t,tc = 0;

scanf("%d",&N);

root[0] = new node;
root[0]->build();

for(int i = 1; i<=N; i++)   cin>>ar[i];

for(int i = 1; i<=N; i++){
    int x = ar[i];
    root[i] = root[i-1]->update(x);
    cnt[x]++;
}



int l,r,k;
/// Queries

while(cin>>l>>r>>k){
    int ans = fn(r,k-1)-fn(l-1,k-1);
    cout<<ans<<endl;

}

return 0;
}

