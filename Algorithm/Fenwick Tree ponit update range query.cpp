/***********************
    Fenwick tree point update, range query
***********************/

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
#define mx 100001

int tree[mx+5];

void update(int i,int val){
    for(;i<mx;i+=i&-i)  tree[i]+=val;
}
int prefix_sum(int i){
    int sum = 0;
    for(;i;i-=i&-i) sum+=tree[i];
    return sum;
}
int query(int a,int b){
    return prefix_sum(b)-prefix_sum(a-1);
}

main(){

int t,tc = 0;

int fl,l,r,val;
while(cin>>fl){
    if(fl==0){
        cin>>l>>val;
        update(l,val);
        continue;
    }
    cin>>l>>r;
    cout<<query(l,r)<<endl;

}


return 0;
}
