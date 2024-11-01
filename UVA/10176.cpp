
#include <iostream>
using namespace std;

typedef long long ll;
//int bal(int n)

ll bal(ll n,ll p,ll m){
    if(p==0)    return 1%m;
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


bool check(string s){
    string str;

    for(int i = 0 ; i<s.size() ; i++){
        int g = s[i] - '0';
        if(g==0 || g==1)    str.push_back(s[i]);
    }

    ll sz = str.size()-1;
    ll pm = 131071;
    ll x = 0;
    for(ll i = 0; i<str.size(); i++){
        ll d = str[i] - '0';
        if(d==0)   continue;

        ll M = bal(2,sz-i,pm);
        x+=M%pm;
    }

    x%=pm;
    return x==0;
}
int main(){

string x,s;

while(getline(cin,x)){
    s.append(x);

    if(x[x.size()-1]=='#'){
    if(check(s))    puts("YES");
    else puts("NO");
        s = "";
    }

}


return 0;
}
