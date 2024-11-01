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
//#include "data.h"
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

#ifndef mx
#define mx 100005
#endif

int ar[mx];

struct node{
    int val;
    node *L,*R;
    node(int c = 0,node *x = NULL,node *y = NULL):val(c),L(x),R(y){}

    void build(int l,int r){
        if(l==r){
            val = ar[l];
//            node *p = new node(ar[l]);
            return;
        }

        L = new node();
        R = new node();
        int m = l+r>>1;
        L->build(l,m);
        R->build(m+1,r);
        this->val = L->val+R->val;
    }

    node *update(int ql,int qr,int x,int l,int r){
        if(r<ql || qr<l)    return this;
        if(ql<=l && r<=qr){
            this->val+=x;
            return this;
        }
        node *ret = new node(val);
        int m = l+r>>1;
        ret->L = L->update(ql,qr,x,l,m);
        ret->R = R->update(ql,qr,x,m+1,r);
        ret->val = ret->L->val+ret->R->val;
        return ret;
    }

    int query(int ql,int qr,int l,int r){
        if(r<ql || qr<l)    return 0;

        if(ql<=l && r<=qr){
//            cout<<l<<" "<<r<<" "<<this->val<<endl;
//            cout<<this<<endl;
            return val;
        }

        int m = l+r>>1;
        return L->query(ql,qr,l,m)+R->query(ql,qr,m+1,r);
    }

} *root[mx];


int main(){


int n;

scanf("%d",&n);

for(int i = 0; i<n; i++)    scanf("%d",&ar[i]);

root[0] = new node();
root[0]->build(0,n-1);
int a,b,fl,l,r,val,k;

while(cin>>fl){
    int id;
    if(fl==1){
        k++;
        cin>>id>>l>>val;
        l--;
        root[k] = root[id]->update(l,l,val,0,n-1);
        continue;
    }
    cin>>k>>l>>r;
    l--,--r;
    int ans = root[k]->query(l,l,0,n-1);
    cout<<ans<<endl;
}

/*

int q,k = 0;

scanf("%d",&q);

while(q--){
    int a,b,c,d,l,r;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a==1){
        k++;
        l = r = --c;
        root[b] = root[0]->update(l,r,d,0,n-1);
        continue;
    }
    l = c,d = r;
    l--;--r;
    int ans = root[b]->query(c-1,d-1,0,n-1);
    cout<<ans<<endl;
}
*/

return 0;
}
