/******
    upper left and lower right  query. Row and Column are numbered from 1;
*/
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

ll ar[42][42],R[42][42];
ll r,c;

ll query(ll a,ll b,ll c,ll d){
    ll ans = R[c][d] - R[a-1][d] - R[c][b-1] + R[a-1][b-1];
    return ans;
}

int main(){
int t,tc = 0;
scanf("%lld%lld",&r,&c);

for(ll i = 1; i<=r; i++){
    string s;
//    cin>>s;
//    for(ll j = 1; j<=s.size(); j++){
      for(ll j = 1; j<=c; j++){
      /*
        if(s[j-1]=='0')   ar[i][j] = 0;
        else ar[i][j] = 1;
    */
        cin>>ar[i][j];
    }
}

for(ll i = 1; i<=r; i++){
    for(ll j = 1; j<=c; j++ ){
        R[i][j] = R[i][j-1]+ar[i][j];
    }
}
for(ll i = 1; i<=c; i++){
    for(ll j = 1; j<=r; j++){
        R[j][i]+=R[j-1][i];
    }
}
cout<<endl;
for(ll i = 1; i<=r; i++){
    for(ll j = 1; j<=c; j++)
        cout<<R[i][j]<<" ";
    cout<<endl;
}
ll a,b,c,d;
puts("");
while(cin>>a>>b>>c>>d){
    cout<<query(a,b,c,d)<<endl;
}


return 0;
}
