/**
    Given N distinct elements and some query.
    For each query given l,r,k. 1<=l<=r<=N, 1<=k<=r-l+1
    For each query what is the k'th number when elements in range [l,r] is sorted in increasing order
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

int ar[mx],ara[mx],A[mx];

struct node{
    node *L,*R;
    int x;
    node(int a = 0,node *b = NULL,node *c  = NULL):x(a),L(b),R(c){}

    void build(int l,int r){
        if(l==r)    return;
        int m = l+r>>1;
//        cout<<l<<" "<<r<<" "<<m<<endl;
        L = new node();
        R = new node();

        L->build(l,m);
        R->build(m+1,r);
    }

    node *update(int ql,int qr,int l,int r){
        if(r<ql || qr<l)    return this;
        if(ql<=l && r<=qr){
            node *z = new node(1);
            return z;
        }
        int m = l+r>>1;
        node *ret = new node();
        ret->L = L->update(ql,qr,l,m);
        ret->R = R->update(ql,qr,m+1,r);
        ret->x = ret->L->x + ret->R->x;
        return ret;
    }

} *root[mx];

int query(node *a,node *b,int l,int r,int val){
    if(l==r)    return l;
    int m = l+r>>1;
    int cnt = a->L->x - b->L->x;
    if(cnt>=val)  return query(a->L,b->L,l,m,val);
    return query(a->R,b->R,m+1,r,val-cnt);
}

/*
*/

int main(){
int n;
scanf("%d",&n);
int q;  scanf("%d",&q);

for(int i = 1; i<=n; i++){
    scanf("%d",ar+i);
    A[i] = ar[i];
}

sort(A,A+n+1);
int id = unique(A,A+n+1)-A;

for(int i = 1; i<=n; i++){
    int x = ar[i];
    ar[i] = lower_bound(A,A+id,x) - A;
    ara[ar[i]] = x;
}

root[0] = new node;
root[0]->build(0,n);
for(int i = 1; i<=n; i++){
    root[i] = root[i-1]->update(ar[i],ar[i],0,n);
}

for(int i = 0; i<q; i++){
    int l,r,k;
    scanf("%d%d%d",&l,&r,&k);
    int id = query(root[r],root[l-1],0,n,k);
    printf("%d\n",ara[id]);
}


return 0;
}
