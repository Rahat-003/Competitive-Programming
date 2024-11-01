#include <bits/stdc++.h>
using namespace std;
int r,c;
string dir = "NESW";

vector <vector<int> > v;

int mod(int a){
while(a<0)
  a+=4;
return a%4;
}

int dx(int x,int y, char ch){
  if(ch=='E'){
    if(x+1<=r && x+1>=0)
      x+=1;
   else v[x][y] -= 1;
  }
  if(ch=='W'){
    if(x-1<=r && x-1>=0 )
      x-=1;
   else v[x][y]-=1;
  }
  return x;
}
int dy(int x,int y,char ch){
  if(ch=='N')
    if(y+1<=c && y+1>=0 )
      y+=1;
    else v[x][y]-=1;

  if(ch=='S'){
    if(y-1<=c && y-1>=0 )
      y-=1;
    else v[x][y]-=1;
  }
  return y;
}

int main(){
 // freopen("118.txt","r",stdin);
cin>>r>>c;

v.assign( r+1,vector<int> (c+1,0) );

int x,y;  char ch;
while(cin>>x>>y>>ch){
  int flag = 1;
  string s;
  cin>>s;
  int sum = dir.find(ch);
  for(int i=0;i<s.size();i++){

    if(s[i]=='L') sum-=1;
    if(s[i]=='R') sum+=1;

    if(s[i]=='F' ){
      sum = mod(sum);
      ch = dir[sum];
      x = dx(x,y,ch);
      y = dy(x,y,ch);
    if(v[x][y]== -1){
        cout<<x<<" "<<y<<" "<<ch<<" LOST\n";
        v[x][y] -= 1;
        flag=0;
        break;
    }
    }
  }
  sum=mod(sum);
  ch=dir[sum];
  if(flag) cout<<x<<" "<<y<<" "<<ch<<endl;
}

return 0;
}
