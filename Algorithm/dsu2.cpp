/**********
    News Distribution
    https://codeforces.com/contest/1167/problem/C
*********/
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
#define mx 500003
int ar[mx],cnt[mx];

int F(int a){
    if(ar[a]!=a)    ar[a] = F(ar[a]);
    return ar[a];
}

void merge(int a,int b){
    int x = F(a),y = F(b);
    if(x!=y){
        ar[y] = x;
    }
}


main(){
int t,tc = 0;

int n,m;
scanf("%d%d",&n,&m);

for(int i = 1; i<=n; i++)   ar[i] = i;

for(int i = 0; i<m; i++){
    int p;  scanf("%d",&p);
    int a,b;
    if(p)   scanf("%d",&a);
    for(int j = 1; j<p; j++){
        scanf("%d",&b);
        merge(a,b);
    }
}

for(int i = 1; i<=n; i++)  cout<<ar[i]<<" ";
cout<<endl;

for(int i = 1; i<=n; i++)   ar[i] = F(ar[i]);

for(int i = 1; i<=n; i++)   cout<<ar[i]<<" ";   cout<<endl;

for(int i = 1; i<=n; i++)   cnt[ar[i]]++;

//for(int i = 1; i<=n; i++)   cout<<cnt[ar[i]]<<" ";    cout<<endl;


return 0;
}

