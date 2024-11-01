#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
  ll r,c,mul;
  node(ll a=0,ll b=0,ll d = 0){
    r=a;
    c=b;
    mul = d;
  }
};

node m(node a, node b){
  ll r,c,mul;
  if (a.c!=b.r) mul = -1;
  else{
    mul = a.r*a.c*b.c;
  r = a.r;
  c = b.c;
  }
  node ans = node(r,c,mul);

  return ans;
}

map<char,node> mp;
map<char,bool> vis;
int main(){

// freopen("tst.txt","r",stdin);
ll t;
cin>>t;
while(t--){
  char c;
  ll R,C;
  cin>>c>>R>>C;
  mp[c] = node(R,C,0);
  vis[c] = true;
}
string s;

while(cin>>s){
  string t = s;
  bool fl = false;
  node ans ;
  ll tot=0;
  ll cnt = 0;
  if(s[0]=='(' && s[2]==')') {
      if(vis[s[1]]) cout<<0;
      else cout<<"error";
      cout<<endl;

    continue;
      }
    while(t.size()!=1 ){
    for(ll i=0;i<t.size()-3;i++){
      if(t[i]=='(' && t[i+3]==')'){
        char p = t[i+1],  q = t[i+2];
        ans = mp[q];
    node a = mp[p], b = mp[q];
        ans = m(mp[p],ans);
        tot+=ans.mul;

        if(ans.mul==-1) fl = true;
      t.erase(i,4);
      string y(1,'a'+cnt);
        mp[y[0]] = ans;
      t.insert(i,y);
      cnt++;
      break;
      }
    }

  }

  if(fl || (s.size()==1 && !vis[s[0]]) )  puts("error");
  else cout<<tot<<endl;

}


return 0;
}
