#include <bits/stdc++.h>
using namespace std;
int r,c;
string dir = "NESW";

vector <vector<char> > v;

int mod(int a){
while(a<0)
  a+=4;
return a%4;
}
int dx(int x,int y, char ch){
  if(ch=='E'){
    if(x+1<=r && x+1>=0) {
      x+=1;
    }
    else v[x][y] = 'E' ;
  }
  if(ch=='W'){
    if(x-1<=r && x-1>=0 && v[x][y]!= -1)
      x-=1;
    else v[x][y] = 'W' ;
  }
  return x;
}
int dy(int x,int y,char ch){
  if(ch=='N'){
    if(y+1<=c && y+1>=0 && v[x][y]!=-1)
      y+=1;
    else v[x][y] ='N';
  }
  if(ch=='S'){
    if(y-1<=c && y-1>=0 && v[x][y]!=-1)
      y-=1;
    else v[x][y] = 'S' ;
  }
  return y;
}

int main(){
  freopen("118.txt","r",stdin);
cin>>r>>c;

v.assign(r+1,vector<char>(c+1,'Z'));

int x,y;  char ch;
while(cin>>x>>y>>ch){
  int flag = 1;
  string s;
  cin>>s;
  int sum = dir.find(ch);
  for(int i=0;i<s.size();i++){

    if(s[i]=='L') sum-=1;
    if(s[i]=='R') sum+=1;
      sum = mod(sum);
      ch = dir[sum];
    if(s[i]=='F' && v[x][y]!=ch){
      x = dx(x,y,ch);
      y = dy(x,y,ch);
    if(v[x][y]== ch){
        cout<<x<<" "<<y<<" "<<ch<<" LOST\n";
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
