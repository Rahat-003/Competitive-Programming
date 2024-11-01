#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx (ll)1e5

struct player{
    ll x,y,v;
    player(){};
    player(ll p,ll q,ll r){
        x = p,y = q,v = r;
    }
};
vector<player> P;

double dist(double x1,double y1,double x2,double y2){
    return hypot(x1-x2,y1-y2);
}

bool check(ll a,ll b,ll c){
    double x = (double)a;
    double y = (double)b;
    double t = (double)c;

    for(ll i = 0; i<P.size(); i++){
        player r = P[i];
        double _x = (double)r.x;
        double _y = (double)r.y;
        double v = (double)r.v;
        double dis = dist(x,y,_x,_y);
        if(v*t>=dis)    return false;
    }
    return true;
}


ll bsearch(ll l,ll h,ll a,ll b,ll c){
    ll mid = (l+h)/2;
    ll lz = a*l*l+b*l+c;
    ll hz = a*h*h+b*h+c;
    ll z = a*mid*mid+b*mid+c;
//    cout<<l<<" "<<h<<endl;

    if(lz<=0){
//     puts("bal");
//     cout<<l<<" "<<h<<endl;
     return l;
    }


    if(lz>0 && z<=0)  return bsearch(l,mid,a,b,c);
    else  return bsearch(mid+1,h,a,b,c);
}

ll pp(string s){
    ll i = s.find('=');
    string t;
    for(ll j = i+1; j<s.size(); j++)
        t.push_back(s[j]);
    return atoi(t.c_str());
}

int main(){
string s,T;
getline(cin,s);
istringstream iss(s);
ll n = pp(s);

while(n--){
    ll A,B,C;
    cin>>A>>B>>C;
    P.push_back(player(A,B,C));
}
cin.ignore();
getline(cin,s);

n = pp(s);
ll tc = 0;
while(n--){
ll a,b,c,d,e,f,g;
    cin>>a>>b>>c>>d>>e>>f>>g;
    ll t = bsearch(1,mx,a,b,c);
//    cout<<t<<endl;
ll  x = d*t+e;
   ll  y = f*t+g;
    printf("Ball %lld was ",++tc);

    if(x<0 || y<0){
        printf("foul at (%lld,%lld)\n",x,y);
        continue;
    }
    if(check(x,y,t)){
        printf("safe at ");
    }
    else printf("caught at ");

        printf("(%lld,%lld)\n",x,y);
}


return 0;
}

