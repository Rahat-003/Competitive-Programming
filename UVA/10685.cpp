#include <bits/stdc++.h>
using namespace std;
unordered_map<string,string> ar;
unordered_map<string,int> child;

string f(string a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

int main(){
  int n,e;
while(cin>>n>>e){
  if(!n && !e ) break;
  while(n--){
    string a;
    cin>>a;
    ar[a] = a;
    child[a] = 1;
  }
  while(e--){
    string a,b;
    cin>>a>>b;
    string pa = f(a);
    string pb = f(b);
    if(pa!=pb){
      child[pa]+=child[pb];
      ar[pb] = pa;
    }
  }
  int ans = 0;
  for(auto it=child.begin();it!=child.end();++it){
    if(it->second > ans)
      ans = it->second;

  }
  cout<<ans<<endl;
  ar.clear();
  child.clear();
}




return 0;
}
