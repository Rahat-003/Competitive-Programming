#include <bits/stdc++.h>
using namespace std;
string ss="";
map<int,int> gr;
int r,c,s;
int dir(int s){
  if(ss[s]=='E'){
    return s+1;
  }
  else if(ss[s]=='W'){
    return s-1;
    }
  else if(ss[s]=='N'){
  return s-c;
  }
  else if(ss[s]=='S'){
  return s+c;
  }
}
int main(){
  //freopen("10116.txt","r",stdin);
vector<int>vv;
while(cin>>r>>c>>s){
  if(!r && !c && !s)  break;
int x = r*c;
vv.clear();
gr.clear();
ss.clear();
vector<bool> vis(x,false);

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      char cc; cin>>cc;
      ss.push_back(cc);
      gr[c*i+j] = 0;
      if(j==0 && cc=='W') {
        gr[c*i+j] = r*c;
        vv.push_back(c*i+j);
      }
      if(j==c-1 && cc=='E'){
        gr[j+c*i] = r*c;
        vv.push_back(c*i+j);
      }
      if(i==0 && cc=='N'){
        gr[j+i*c] = r*c;
        vv.push_back(c*i+j);
      }
      if(i==r-1 && cc=='S'){
        gr[j+i*c] = r*c;
        vv.push_back(c*i+j);
      }
    }
  }
  int tmp = s-1;
  vector<int> v;
  int loop = 0;
  while(1){
  v.push_back(tmp);
  vis[tmp] = true;
  if(gr[tmp]) break;
  tmp = dir(tmp);
  if(vis[tmp]) {
      loop = 1;
      v.push_back(tmp);
      break;
  }
  }
int yy = count(vis.begin(),vis.end(),true),y;

//cout<<y<<endl;
  if(loop){
  for(y=0;y<v.size();y++)
    if(v[y]==tmp) break;

  printf("%d step(s) before a loop of %d step(s)",y,v.size()-y-1);

  }
else printf("%d step(s) to exit",yy);
cout<<endl;
}
return 0;
}
