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
#define mx 103

int t1[mx+5],t2[mx+6];

void add(int ar[],int i,int val){
    for(;i<mx;i+=i&-i)  ar[i]+=val;
}

void update(int l,int r,int val){
    add(t1,l,val);
    add(t1,r+1,-val);
    add(t2,l,(l-1)*val);
    add(t2,r+1,-r*val);
}

int prefix_sum(int ar[],int i){
    int tot = 0;
    for(;i;i-=i&-i) tot+=ar[i];
    return tot;
}

int sum(int i){
    return prefix_sum(t1,i)*i - prefix_sum(t2,i);
}

int query(int l,int r){
    return sum(r)-sum(l-1);
}

int main(){

int t,tc = 0;

int fl,l,r,val;

while(cin>>fl){
        cin>>l>>r;
    if(fl==0){
        cin>>val;
        update(l,r,val);
        continue;
    }
    cout<<query(l,r)<<endl;
}


return 0;
}
