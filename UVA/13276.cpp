#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
ll E,P,K,R;

ll bal(ll damage,ll target,ll limit){
    if(target>limit*damage){
//        energy-=limit*damage;
        return limit;
    }
    ll p = target/damage;
    if(p*damage==target){
//        energy-=target;
        return p;
    }
    else{
        p+=1;
//        energy-=p*damage;
        return p;
    }
}
double tot;
ll cnt = 0;

ll go(){
    vector<double> v;
    priority_queue<ll,vector<ll>,less<ll> > pq;
    if(E>P*K && R>=P*K)  return -1;
    if(E==P*K)  return K;
    pq.push(E);
    ll ans = 0;

    while(true){
        ll u = pq.top();
        pq.pop();
        if(E>=P*K){
            ans+=K;
            E-=P*K;
        }
        else{
            ll x = bal(P,E,K);
            ans+=x;
            E-=x*P;
        }
        if(v.size()<=2) v.push_back((double)E);

        if(v.size()==2){
            double dif = v[0]-v[1];
            tot = floor(v[0]/dif);
//            double cc = ceil(v[0]/dif);
//            tot+=1;
            if(v[1]!=0){

            E=(ll)(v[0]-tot*dif);
//            cout<<"bal "<<cc<<endl;
            ans=(ll)((tot+1)*K);
            }
//            ans+=(ll)( (cc+1)*K);
//            tot*=K;
//            return (ll)tot;
//        cout<<v[0]<<"\n"<<v[1]<<endl;
//        cout<<ans<<" "<<E<<endl;
        }

//        cout<<"E "<<E<<endl;
        cnt++;
        if(E<=0)    return ans;
        E+=R;
        if(E>=u && cnt==6)    return -1;
//        if(E-R>=0)  return (E-R+1)*K;
        pq.push(E);
    }

}


int main(){
//    read;
//    write;
int t,tc = 0;
ll a,b,c,d;
/*
while(cin>>a>>b>>c>>d){
    cout<<bal(a,b,c,d)<<" "<<d<<endl;
}
*/

cin>>t;
while(t--){
    cin>>E>>P>>K>>R;
    cnt=0;
    ll ans = go();
    case;
    cout<<" "<<ans<<endl;

}



return 0;
}

