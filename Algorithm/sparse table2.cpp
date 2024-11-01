/*****
    Sparse Table:
        build time:  nlogn
        query: O(1) { returns minimum/maximum value in [l,r] }
        cannot update
*****/

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
#define mx 200002
int table[mx][20],n;

int ar[] = {4,3,1,2,5,6,7,4,3,2,6,9,1,0,7,8,4,6};
//          0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7

void build(){
    for(int i = 0; i<=log2(n); i++){
        for(int j = 0; j<n; j++){
            if(i==0){
                table[j][i] = j;
                continue;
            }
            int x = j+(1<<(i-1));
            if(x>=n)    break;
            int i1 = table[j][i-1],i2 = table[x][i-1];
            table[j][i] = (ar[i1]<=ar[i2]?i1:i2);
        }
    }
}
int query(int l,int r){
    int len = r-l+1,k = log2(len);
    return min(ar[table[l][k]],ar[table[r+1-(1<<k)][k]]);
}

main(){
int t,tc = 0;

n = sizeof ar/4;
build();
int l,r;
while(cin>>l>>r)    cout<<query(l,r)<<endl;


return 0;
}

