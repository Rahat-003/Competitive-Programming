#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 1003
typedef pair<int,int> pp;
int a,b;
pp A[mx],B[mx];
map<string,int> mp;
vector <int> va[mx],vb[mx];
int dp[mx][mx];

int fn(int p,int q){
    if(p==a || q==b)    return 0;

    int &ans = dp[p][q];
    if(ans!=-1) return ans;
    ans = 0;
    int id1,id2;

    int clr = A[p].first;


    for(int j = lower_bound(vb[clr].begin(),vb[clr].end(),q)-vb[clr].begin(); j<vb[clr].size(); j++ )
            ans = max(ans,A[p].second+B[vb[clr][j]].second+fn(p+1,vb[clr][j]+1 ));
    ans = max(ans,fn(p+1,q));

    return ans;
}

int go(int p,int q,int rem){
    if(rem==0)    return 0;
    if(dp[p][q]!=rem)   return 1e7;


    int ans = 1e7;

    ans = min(ans,go(p+1,q,rem));
    int clr = A[p].first;
    for(int j = lower_bound(vb[clr].begin(),vb[clr].end(),q)-vb[clr].begin(); j<vb[clr].size(); j++ )
            ans = min(ans,1+go(p+1,vb[clr][j]+1,rem-A[p].second-B[vb[clr][j]].second ));


    return ans;
}

main(){

//   read;

int t,tc = 0;
scanf("%d",&t);

while(t--){
    scanf("%d",&a);
    memset(dp,-1,sizeof dp);
    int id = 0;

    for(int i = 0; i<a; i++){
        string p,q; int r;
        cin>>p>>q;
        scanf("%d",&r);
        if(mp[q]==0)    mp[q]=++id;
        A[i]=pp(mp[q],r);
        va[mp[q]].push_back(i);
    }

    scanf("%d",&b);
    for(int i = 0; i<b; i++){
        string p,q; int r;
        cin>>p>>q;
        scanf("%d",&r);
        if(mp[q]==0)    mp[q]=++id;
        B[i]=pp(mp[q],r);
        vb[mp[q]].push_back(i);
    }


    int ans = fn(0,0),ans2 = 0;
    ans2 = go(0,0,ans);
    printf("%d %d\n",ans,ans2);

    for(int i = 0; i<mx; i++){
        va[i].clear();
        vb[i].clear();
    }
    mp.clear();
}



return 0;
}

