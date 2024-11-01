
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> s;
//vector<ll> hum;
void f(){
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    pq.push(1);

    ll ar[] = {2,3,5,7};

    for(ll i = 0; i<5842; i++){
        ll top;
        do{
            top = pq.top();
            pq.pop();
        }   while(s.count(top)==1);
        s.insert(top);

        for(ll j = 0; j<4; j++){
            ll p = top*ar[j];
            if(s.count(p)==0)   pq.push(p);
        }
//        cout<<i<<" "<<top<<endl;
    }
}

int main(){
f();
vector<ll>  hum(s.begin(),s.end());
ll n;

while(1==scanf("%lld",&n)){
    if(!n)  break;
    ll x = n%100, y = x%10;;
    string str;
    if(x>10 && x<14){
        str = "th";
    }
    else if(y>=1 && y<4){
        if(y==1)    str = "st";
       else if(y==2)    str = "nd";
        else str = "rd";
    }
    else str = "th";
    printf("The %lld%s humble number is %lld.\n",n,str.c_str(),hum[n-1]);

}


return 0;
}
