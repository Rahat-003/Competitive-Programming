/*
    segment tree
    output a max value and the occurrence of max value in range [ql,qr]
    update an element of the array to a new value
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
#define mx 12
#define MAXN mx
typedef pair<int,int> pp;
pp tree[mx*4],lazy[mx];
int ar[] = {1,1,3,4,4,5,5,2,1,2};

pp combine(pp a,pp b){
    if(a.first>b.first) return a;//.first;
    if(b.first>a.first) return b;
    return pp(a.first,a.second+b.second);
}
void build(int n = 0,int l = 0,int r = sizeof ar/4-1){
    if(l==r){
        tree[n] = {ar[l],1};
        return;
    }
    int L = 2*n+1,R = L+1,m = (l+r)/2;
    build(L,l,m);
    build(R,m+1,r);
    tree[n] = combine(tree[L],tree[R]);
}
int cnt = 0;
pp query(int ql,int qr,int n = 0,int l = 0,int r = sizeof ar/4-1){
    if(r<ql || qr<l)    return {-INT_MAX,0};
    if(ql<=l && r<=qr)  return tree[n];
//    cnt++;
    int L = 2*n+1,R = L+1,m = (l+r)/2;
    return combine(query(ql,qr,L,l,m),query(ql,qr,R,m+1,r));
}

void update(int id,int val,int n = 0,int l = 0,int r = sizeof ar/4-1){
    if(r<id || id<l)    return;
    if(id==l && l==r){
        tree[n] = {val,1};
        return;
    }
    int L = n*2+1,R = L+1,m = (l+r)/2;
    update(id,val,L,l,m);
    update(id,val,R,m+1,r);
    tree[n] = combine(tree[L],tree[R]);
}


int main(){
int t,tc = 0;
/// int ar[] = {1,1,3,4,4,5,5,2,1,2};
build();

update(0,6);
pp x = query(0,9);
cout<<x.first<<" "<<x.second<<endl;
//cout<<cnt<<endl;

return 0;
}

