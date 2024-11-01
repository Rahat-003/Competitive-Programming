#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

vector<int> val,wt;
int K[35][1005];

int knap(int w,int i){
    if(!i || !w)    return 0;
    if(K[w][i]!=-1)    return K[w][i];
    if(wt[i-1]>w)   return knap(w,i-1);
    int p1 = val[i-1]+knap(w-wt[i-1],i-1);
    int p2 = knap(w,i-1);
    K[w][i]=max(p1,p2);
    return max(p1,p2);


int main(){
//    read;

int t,tc = 0;

scanf("%d",&t);
while(t--){
    int n;  scanf("%d",&n);
    memset(K,-1,sizeof K);
    for(int i = 0; i<n; i++){
        int a,b;    scanf("%d %d",&a,&b);
        val.push_back(a);
        wt.push_back(b);
    }
    scanf("%d",&n);
    int ans = 0;
    while(n--){
        int w;  scanf("%d",&w);
        ans+=knap(w,val.size());
    }
    printf("%d\n",ans);
    val.clear();
    wt.clear();
}


return 0;
}

