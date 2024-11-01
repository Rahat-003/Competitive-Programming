#include <bits/stdc++.h>
using namespace std;
int r,c;
vector < vector<bool> > vis;
string s = "NESW";

int mod(int a){
  while(a<0)
    a+=4;
  a = a%4;
  return a;
}

int dy(int x,int y,char z){
  if(vis[y+1][x] && z=='E')
    return y+1;
  else if(vis[y-1][x] && z=='W')
    return y-1;
  else return y;
}
int dx(int x,int y,char z){
  if(vis[y][x-1] && z=='N')
    return x-1;
  else if(vis[y][x+1] && z=='S')
    return x+1;
  else return x;
}

int main(){
 // freopen("10377.txt","r",stdin);
int t;  cin>>t;
int f=1;
while(t--){
  cin>>r>>c;

vis.assign(c,vector<bool>(r,true));
  cin.ignore();

  for(int i=0;i<r;i++){
      string ss; getline(cin,ss);
    for(int j=0;j<c;j++){
      if(ss[j]=='*') vis[j][i] = false;
    }
  }
  int ix,iy;  cin>>ix>>iy;
string line;
int nx,ny;
nx=ix-1;
ny=iy-1;
  int sum=0;
  char ch;
  while(1){
    cin>>line;
    for(int i=0;i<line.size(); i++){
      if(line[i]=='L') sum-=1;
      if(line[i]=='R') sum+=1;

      if(line[i]=='F'){
      sum = mod(sum);
      ch = s[sum];
        nx = dx(nx,ny,ch);
        ny = dy(nx,ny,ch);
      }
    }
    if(line[line.size()-1]=='Q') break;

  }
  if(!f) cout<<endl;
  f=0;
  sum = mod(sum);
  ch = s[sum];

cout<<nx+1<<" "<<ny+1<<" "<<ch<<endl;
for(int i=0;i<vis.size();i++)
  vis[i].clear();

}

return 0;
}
