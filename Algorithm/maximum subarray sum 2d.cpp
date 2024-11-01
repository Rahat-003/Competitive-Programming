/******
    maximum sum 2d array. Complexity n^44
******/
#include                <bits/stdc++.h>
#define ff              first
#define ss              second
#define pb(x)           push_back(x)
#define dbg(a)          cout<< #a <<" --> "<<(a)<<endl;
#define read            freopen("tst.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> PP;

#define mx 102
int ar[mx][mx];

int fn(int a,int b,int c,int d){
    return ar[c][d] - ar[a-1][d] - ar[c][b-1] + ar[a-1][b-1];
}

main(){
//read;
int n;
cin>>n;
for(int i = 1; i<=n; i++)
for(int j = 1; j<=n; j++){
    int x;
    scanf("%d",&x);
    ar[i][j] = x;
    ar[i][j]+=ar[i-1][j];
    ar[i][j]+=ar[i][j-1];
    ar[i][j]-=ar[i-1][j-1];
}
int ans = -INT_MAX;

for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
        for(int k = i; k<=n; k++){
            for(int l = j; l<=n; l++)
                ans = max(ans,fn(i,j,k,l));
        }
    }
}
cout<<ans<<endl;

return 0;
}

