#include <bits/stdc++.h>
using namespace std;
vector<int> ar;
vector<bool> vis;

int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}


int main(){

int n,e;
int tc = 0;
while(cin>>n>>e){
  if(!n && !e)
      break;

    tc++;
  vis.assign(n+1,false);
  vis[0] = true;
  for(int i=0;i<=n;++i)
    ar.push_back(i);

  int cnt = 0;
  while(e--){
    int a,b;
    cin>>a>>b;
    int pa = f(a);
    int pb = f(b);
    if(pa!=pb){
      ar[pb] = pa;
    }

  }

  for(int i=1;i<ar.size();++i){
    ar[i] = f(ar[i]);
    if(!vis[ ar[i] ]){
      cnt+=1;
      vis[ ar[i] ] = true;
    }
  }

    printf("Case %d: ",tc);
    cout<<cnt<<endl;
    vis.clear();
    ar.clear();


}





return 0;
}
