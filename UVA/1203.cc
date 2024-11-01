#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pp;
vector<ll> v,w;
priority_queue<pp,vector<pp>,greater<pp>> pq;
int main(){
  string s;
  ll a,b;
//  cin>>s>>a>>b;
  while(cin>>s){
    if(s=="#")break;
    cin>>a>>b;
    v.push_back(b);
    w.push_back(a);
  }
  ll p; cin>>p;
  for(int i = 0;i<v.size();++i){
    int k=0;
    for(int j=0;j<p;++j){
      k++;
      pq.push(pp(v[i]*k,w[i]));
    }
  }
  ll _p=0;
while(!pq.empty()){
  if(p==_p) break;
  _p++;
  cout<<pq.top().second<<endl;
  pq.pop();
}

return 0;
}
