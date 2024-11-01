#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

ll cal(string s){
    ll ans = 0;
    ll sz = s.size();
    for(ll i = 0 ; i<s.size(); i++){
        ll n = s[i] - '0';
        if(n==0)    continue;
        double p = pow(2,sz-i);
        ll q = (ll)p - 1;
        ans+= n*q;
    }
    return ans;
}


int main(){
string s;
while(cin>>s){
    if(s[0]=='0' && s.size()==1)    break;
    ll ans = cal(s);
    cout<<ans<<endl;

}





return 0;
}
