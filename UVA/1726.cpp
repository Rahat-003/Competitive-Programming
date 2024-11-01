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

vector<int> u,v;


main(){
int t,tc = 0;
scanf("%d",&t);

while(t--){
    u.clear();
    v.clear();
    int n;
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        int a,b;    char c;
        scanf("%d%d",&a,&b);
        cin>>c;
        if(b==0 && c=='i')  u.push_back(a);
        if(b==1 && c=='c')  v.push_back(a);
    }
    sort(u.begin(),u.end());
    sort(v.begin(),v.end());

    ll ans = 0;
    for(int i = 0; i<u.size(); i++){
        int a = u[i];
        ll x,y;
        if(v[v.size()-1]<=a)    continue;
        x = upper_bound(v.begin(),v.end(),a)-v.begin();

        y = v.size();
        ans+=y-x;
    }
    printf("%lld\n",ans);
}



return 0;
}
