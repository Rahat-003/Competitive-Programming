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
#define case        printf("Case %d:\n",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 1000005
const ll P = 1000000007;

ll sa[mx],ind[mx],lcp[mx],ara[mx];

struct node{
    ll index,r1,r2;
    bool operator < (const node &n) const{
        if(r1!=n.r1)    return r1<n.r1;
        return r2<n.r2;
    }
} ar[mx];
string s;
void suffix_aray(){
    ll n = s.size();
    for(ll i = 0; i<n; i++){
        ar[i].index = i;
        ar[i].r1 = s[i] - 'a';
        ar[i].r2 = (i+1<n?s[i+1]-'a':-1);
    }
    sort(ar,ar+n);

    for(ll k = 4; k<2*n; k*=2){
        ll rank = 0,tmp = ar[0].r1;
        ind[ar[0].index] = 0;
        ar[0].r1 = 0;
        for(ll i = 1; i<n; i++){
            if(ar[i].r1==tmp && ar[i].r2 == ar[i-1].r2){
                tmp = ar[i].r1;
                ar[i].r1 = rank;
            }
            else{
                tmp = ar[i].r1;
                ar[i].r1 = ++rank;
            }
            ind[ar[i].index] = i;
        }

        for(ll i = 0; i<n; i++){
            ll j = ar[i].index + k/2;
            ar[i].r2 = (j<n)?ar[ind[j]].r1:-1;
        }
        sort(ar,ar+n);
    }
    for(ll i = 0; i<n; i++)    sa[i] = ar[i].index;
}

void lcp_kasai(){
    ll n = s.size(),k = 0;
    for(ll i = 0; i<n; i++)    ind[sa[i]] = i;

    for(ll i = 0; i<n; i++,k>0?--k:0){
        if(ind[i]==n-1) continue;
        ll j = sa[ind[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[ind[i]] = k;
    }

}
ll cnt[mx];

void distinct_substring(){
    ll n = s.size(),ans = 1;
//    cnt[0] = 1;
    ll p = n-sa[0],x;
    cnt[1]++;
    cnt[p+1]--;
    for(ll i = 0; i<n-1; i++){
        p = (n-sa[i+1]);    /// Length of i+1 th suffix in suffix array;
        ll z = lcp[i];
        x = p - lcp[i];
        cnt[z+1]+=1;
        cnt[p+1]+=-1;
        ans+=x;
    }
//    cout<<"total "<<ans<<endl;
}

main(){
ll t,tc = 0;
    //read;
ara[0] = 1;
for(ll i = 1; i<mx; i++)    ara[i] = (ara[i-1]*26)%P;
ara[0] = 0;
for(ll i = 1; i<mx; i++)    ara[i] = (ara[i]+ara[i-1])%P;

scanf("%lld",&t);
while(t--){
    memset(cnt,0,sizeof cnt);
    cin>>s;
    suffix_aray();
    lcp_kasai();

    distinct_substring();

    for(ll i = 1; i<=s.size(); i++)    cnt[i] = (cnt[i] + cnt[i-1])%P;
    for(ll i = 1; i<=s.size(); i++)    cnt[i] = (cnt[i] + cnt[i-1])%P;
    int q;
    scanf("%d",&q);
    case;
    while(q--){
        ll d,a,b,ans;
        scanf("%lld%lld",&a,&b);
        d = (cnt[b] - cnt[a-1]+P)%P;
        ans = (ara[b] - ara[a-1] + P)%P;
        ans = (ans-d+P)%P;
        printf("%lld\n",ans);
    }
}

return 0;
}



