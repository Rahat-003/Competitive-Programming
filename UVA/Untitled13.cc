#include                <bits/stdc++.h>
#define ff              first
#define ss              second
#define pb(x)           emplace_back(x)
#define dbg(a)          cout<< #a <<" --> "<<(a)<<endl;
#define read            freopen("tst.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> PP;

#define mx 5001
int dp[501][mx];

int sum,mod,ans;

int fn(int p,int s){
    if(s>sum)   return mx;
    if(s==sum){
        if(p==0)    return 0;
        return mx;
    }
    int &ans = dp[p][s];
    if(ans!=-1) return ans;
    ans = mx;
    int st = 0;
    if(p==0 && s==0)    st = 1;
    for(int i = 9; i>=st; i--){
        ans = min(ans,1+fn((p*10+i)%mod,s+i));
    }

    return ans;
}

int dp2[5001][501];

int go(int pos,int m){
    if(pos==ans)    return m==0;

    int &ans = dp2[pos][m];

    if(ans!=-1) return ans;

    ans = 0;
    int st = (pos==m && m==0);

    for(int i = 9; i>=st; i--){
        int S = st;
        if(i)   S = 1;
        ans|=go(pos+1,(m*10+i)%mod);
    }
    return ans;
}

string s;

void check(){
    string x;
    for(int i = 0; i<s.size(); i++)
        if(s[i]!='0' || x.size())   x.push_back(s[i]);
    s = x;
}

void build(int pos,int m,int x = 0){
    if(x+(ans-pos+1)*9<sum) return;

    if(pos==ans){
        if(m==0 && x==sum){
            cout<<s<<endl;
            check();
//            exit(0);
        }
        return;
    }
    if(dp2[pos][m]!=1)   return;
    int st = (pos==0 && m==0);
    for(int i = 9; i>=st; i--){
//        int S = st;
//        if(i)   S = 1;
        s.push_back(i+'0');
        build(pos+1,(m*10+i)%mod,x+i);
        s.pop_back();
    }

}


main(){
//read;

cin>>mod>>sum;
memset(dp,-1,sizeof dp);
ans = fn(0,0);
//cout<<ans<<endl;

if(ans==mx){
    cout<<-1;
    return 0;
}

memset(dp2,-1,sizeof dp2);
go(0,0);
build(0,0);
//*/


return 0;
}

