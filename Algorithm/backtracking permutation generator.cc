#include <bits/stdc++.h>
using namespace std;

vector<int> v,u;
vector<bool> vis;
  int n;

void perm(int id){
    if(id==n){
      for(int i=0;i<u.size();i++)
        cout<<u[i]<<" ";
      cout<<endl;
      return ;
    }

    for(int i=0;i<v.size();++i){
      int m = v[i];
      if(!vis[i]){
        vis[i] = true;
        u[id] = m;
        perm(id+1);
        vis[i] = false;
      }

    }

}


int main(){

  cin>>n;
  vis.assign(n,false);
  u.assign(n,-1);
  for(int i=0;i<n;i++){
    int a;  cin>>a;
    v.push_back(a);
  }


perm(0);





return 0;
}

