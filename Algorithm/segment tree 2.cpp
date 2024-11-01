/*
    segment tree lazy propagation-> summation from [l,r]
    update function adds 1 to all elements from [l,r]
*/
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
#define mx 1003
int ar[] = {1,3,6,9,14};
int tree[mx],lazy[mx];

void make(int l = 0,int r = 4,int n = 0){
    if(l==r){
        tree[n] = ar[l];
        return;
    }
    int L = 2*n+1,R = L+1, m = (l+r)/2;
    make(l,m,L);
    make(m+1,r,R);
    tree[n] = tree[L] + tree[R];
}

void update(int ql,int qr,int n = 0,int l = 0,int r = 4){
    int L = 2*n+1,R = L+1, m = (l+r)/2;
    if(lazy[n]){
        tree[n]+=(r-l+1);
        if(l!=r){
            lazy[L]+=lazy[n];
            lazy[R]+=lazy[n];
        }
        lazy[n] = 0;
    }
    if(ql<=l && r<=qr){
        tree[n]+=(r-l+1);
        if(l!=r){
            lazy[L]++;
            lazy[R]++;
        }
        return;
    }
    if(l>qr || r<ql)    return;
    update(ql,qr,L,l,m);
    update(ql,qr,R,m+1,r);
    tree[n] = tree[L] + tree[R];
}

int query(int ql,int qr,int n = 0,int l = 0,int r = 4){
    int L = 2*n+1,R = L+1, m = (l+r)/2;
    if(lazy[n]){
        tree[n]+=(r-l+1);
        if(l!=r){
            lazy[L]+=lazy[n];
            lazy[R]+=lazy[n];
        }
        lazy[n] = 0;
    }
    if(l>qr || r<ql)    return 0;
    if(ql<=l && r<=qr)  return tree[n];
    int x,y ;
    x = query(ql,qr,L,l,m);
    y = query(ql,qr,R,m+1,r);
    return x+y;
}

int main(){
int t,tc = 0;

make();
//cout<<tree[0];
update(0,4);
cout<<query(0,4);

return 0;
}

