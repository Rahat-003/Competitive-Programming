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

vector<int> ar = {45, 34, 4, 12, 5, 2} ;
vector<int> u,v;

void sub(int l,int r,int sum,vector<int> &V){
    if(l==r){
        V.push_back(sum);
    return;
    }
    sub(l+1,r,sum+ar[l],V);
    sub(l+1,r,sum,V);
}

int ff(int sum){
    int ans = 0;
    for(int i:u){
//        if(sum-i<0) continue;
        int id = lower_bound(v.begin(),v.end(),sum-i) - v.begin(), p = v[id];

        if(id && p!=sum-i)    p = v[id-1];
        if(p+i==sum)    return sum;
        if(p+i<=sum){
//         cout<<v[id]+i<<endl;
                ans = max(ans,p+i);
        }
    }

    return ans;
}
int main(){
int t,tc = 0;
sub(0,ar.size()/2,0,u);
sub(ar.size()/2,ar.size(),0,v);
sort(v.begin(),v.end());

int n;
//for(auto i:v)   cout<<i<<" ";
cout<<endl;
while(cin>>n){
    cout<<ff(n)<<endl;
}



return 0;
}

