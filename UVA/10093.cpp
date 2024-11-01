#include <iostream>
#include <unordered_map>
using namespace std;

string base = "0123456789";
unordered_map<char,int> mp;

typedef long long ll;

void f(){
    for(int i = 0; i<26; i++)
        base.push_back('A' + i);
    for(int i = 0; i<26; i++)
        base.push_back('a' + i);
    for(int i = 0; i<base.size(); i++)
        mp[base[i]] = i+1;
}

ll check(string s){
    ll a = -1;
    for(int i = 0; i<s.size(); i++){
        a = max( a, (ll) mp[ s[i] ] );
    }
    return a;
}
ll bal(ll n,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return n%m;
    if(p%2==0){
        ll x = p/2;
        ll ans = bal(n,x,m);
        return (ans*ans)%m;
    }
    else{
        ll x = p-1;
        ll ans = bal(n,x,m);
        return ((n%m)*ans)%m;
    }

}

bool toDec(string s,ll sys){
    ll sz = s.size()-1;
    ll ans = 0;
    ll md = sys-1;
    for(ll i = 0; i<s.size(); i++){
        ll d = mp[s[i]]-1;
        if(d==0)    continue;
        ans+= d*( bal(sys,sz-i,md) );
        ans%=md;
    }
    ans%=md;
    return ans==0;
}

string make(string s){
    string t;
    for(int i = 0; i<s.size(); i++){
        int d = s[i];
        if( (d>=48 && d<=57) || (d>=65 && d<=90) || (d>=97 && d<=122) )
            t.push_back(d);
    }
    return t;
}

int main(){

f();
string a;

while(cin>>a){
        a = make(a);
    ll Min = check(a);
    ll sys;
    if(Min<2)   Min = 2;

    bool fl = false;
    for(ll i = Min; i<=62; i++){
        bool D = toDec(a,i);
        if(D){
            fl = true;
            printf("%lld\n",i);
            break;
        }
    }
    if(!fl) puts("such number is impossible!");

}




return 0;
}
