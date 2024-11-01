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
#define mx 300000002
#define MX 577350269

ll dx[] = {0,-1,-2,-1,1,2,1};
ll dy[] = {0,2,0,-2,-2,0,2};

ll id[] = {6,0,6,1,2,3,4},range[7];

ll st[10];

ll sum(ll t){
    return 3*(t+1)*t;
}

main(){
int t,tc = 0;

ll n;
cin>>n;
if(n==0){
    puts("0 0");
    return 0;
}
ll x =0 ;

ll l = 1,r = MX,m,i;
while(l<=r){
    m = l+r>>1;
    x = sum(m);
    if(x>=n) r = m-1,i = m;
    else l = m+1;
}
x = sum(i-1);
ll rem = n-sum(i-1);
st[1] = 1+3*((i-1)*(i-1)+i-1);
st[2] = x+i;
st[6] = 3*i*i+2*i;
for(ll j = 3; j<=5; j++)    st[j] = st[j-1]+i;

//cout<<i<<endl;
//for(int j =0 ; j<=5; j++)   cout<<st[j+1]<<" ";cout<<endl;

for(ll j = 1; j<=6; j++){
    if(n==st[j]){
//        cout<<j<<" ";
        if(j==1){
            ll x2 = 2*i-1,y2 = 2;
            cout<<x2<<" "<<2<<endl;
        }
        else cout<<i*dx[id[j]]<<" "<<i*dy[id[j]]<<endl;
        return 0;
    }
}
/*
if(sum(i)==n){
    cout<<i*2<<" "<<0<<endl;
    return 0;
}
*/
range[1] = i-1;
for(ll j = 2; j<=5; j++){
    range[j] = i;
}
range[6] = i+1;
range[0] = 1;

for(ll j = 0; j<=6; j++){
    if(rem<=range[j]){
        ll x = i*dx[id[j]],y = i*dy[id[j]];
        if(j==1)    x = 2*i-1,y = 2;
        x+=rem*dx[j];y+=rem*dy[j];
        cout<<x<<" "<<y<<endl;
        return 0;
    }
    rem-=range[j];
}


return 0;
}

