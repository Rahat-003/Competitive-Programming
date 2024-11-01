#include <bits/stdc++.h>
using namespace std;

    unordered_map <string,string> mp;
    unordered_map <string,int> vote;
    unordered_map <string,bool> vis;
int main(){

  //freopen("tst.txt","r",stdin);

int t;
scanf("%d",&t);

bool fl = false;
// cin.ignore();
while(t--){

  int n;
  scanf("%d",&n);
cin.ignore();
  while(n--){
    string p,q;
    getline(cin,p);
    getline(cin,q);
    mp[p] = q;
    vis[p] = true;
  }

  int x;
  scanf("%d",&x);
  cin.ignore();
  while(x--){
    string p;
    while(getline(cin,p)){
    if(p.size()){
    if( vis[p] )
      vote[p]++;
      break;
    }
  }
  }
  int cnt = -1;
  string ans;

  for(auto it = vote.begin(); it!=vote.end(); ++it){
    if( cnt < it->second )
      cnt = it->second;
  }
  int tt = 0;

  for(auto it = vote.begin(); it!=vote.end(); ++it){
    if(it->second==cnt){
      tt++;
    ans = mp[it->first];
    }
  }
  if(fl)  cout<<endl;
  fl = true;

  if( tt!= 1 ) ans = "tie";
    cout<<ans<<endl;

  mp.clear();
  vote.clear();
  vis.clear();
}


return 0;
}
