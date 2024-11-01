#include <bits/stdc++.h>
using namespace std;
vector<int> ar,child;

int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}


int main(){
int t;
cin>>t;
while(t--){
  int n,e;
  cin>>n>>e;
  child.assign(n+1,1);
  for(int i=0;i<=n;++i)
    ar.push_back(i);
  while(e--){
    int a,b;
    cin>>a>>b;
    int pa = f(a);
    int pb = f(b);
    if(pa!=pb){
      child[pa]+=child[pb];
      ar[pb] = pa;
    }
  }
  int ans = 0;
  for(int i=0;i<child.size();++i){
    if(child[i]>ans)
      ans = child[i];
  }
  cout<<ans<<endl;
  ar.clear();
  child.clear();


}


return 0;
}
