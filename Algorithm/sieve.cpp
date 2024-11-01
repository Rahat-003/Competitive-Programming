#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define pb(x)                   push_back(x)
#define ook(x)                  order_of_key(x)
#define fbo(x)                  find_by_order(x)
#define all(x)                  (x).begin(),(x).end()
#define FOR(i,a,b)              for(int i = a; i<=b; i++)
#define REP(i,a,b)              for(int i = a; i<b;  i++)
#define dbg(a)                  cout<<#a <<" --> "<<(a)<<endl;
#define TT                      int TC;  cin>>TC;  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace std;
using                           namespace __gnu_pbds;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;
#define mx 1000002


vector<int> prime = {2};


void sieve(){
    const int size = 4001;
    bitset<size> mark;
    for(ll i = 3; i*i<size; i+=2) if(mark[i]==0) for(ll j = i*i; j<size; j+=2*i)   mark[j] = 1;
    for(ll i = 3; i<size; i+=2)   if(mark[i]==0)    prime.push_back(i);
}


main(){
//read;

sieve();
cout<<prime.size();



return 0;
}
