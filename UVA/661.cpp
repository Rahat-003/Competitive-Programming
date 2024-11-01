#include <bits/stdc++.h>
using namespace std;

int main(){
 //   freopen("661.txt","r",stdin);
int cc=1;
int a,b,c;
while(cin>>a>>b>>c){
    if(a==0 && b==0 && c==0) break;
  //if(cc>1) cout<<endl;
  vector<int>v;
  map<int,bool>vis;
  v.push_back(0);
  while(a--){
    int d;  cin>>d; v.push_back(d);
  }
  int total=0, flag=-1;
  while(b--){
    int x;  cin>>x;
    if(!vis[x]){
        vis[x] =true;
        total+= v[x];
    }
    else if(vis[x]){
      vis[x] =false;
      total-=v[x];
    }
    if(total>flag)
      flag =total;
  }

  printf("Sequence %d\n",cc);
  cc++;
  if(flag>c) cout<<"Fuse was blown.\n";
  else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n",flag);
  cout<<endl;
}

return 0;
}
